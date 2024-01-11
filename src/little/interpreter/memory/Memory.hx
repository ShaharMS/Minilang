package little.interpreter.memory;

import little.tools.TextTools;
import vision.ds.Color;
import little.tools.Tree;
import haxe.ds.Either;
import little.interpreter.Tokens.InterpTokens;
import vision.ds.ByteArray;

using little.tools.Extensions;
using vision.tools.MathTools;

class Memory {
    
	public var memory:ByteArray;
	public var reserved:ByteArray;

    public var heap:Heap;
	public var stack:Stack;
	public var externs:ExternalInterfacing;
    public var constants:ConstantPool;

	@:noCompletion public var memoryChunkSize:Int = 128; // 128 bytes, 512 bits

	/**
		The maximum amount of memory that can be allocated, by bytes.
		By default, this is 2GB.
	**/
	public var maxMemorySize:Int = 1024 * 1024 * 2;

	/**
		The current amount of memory allocated, in bytes.
	**/
	public var currentMemorySize(get, never):Int;
	@:noCompletion function get_currentMemorySize() {
		var initialSize = reserved.length;
		var i = reserved.length - 1;
		while (i >= 0 && reserved[i] == 0) {
			i--;
			initialSize--;
		}

		return initialSize;
	}

	public function new() {
		memory = new ByteArray(memoryChunkSize);
		reserved = new ByteArray(memoryChunkSize);
		reserved.fill(0, memoryChunkSize, 0);

		heap = new Heap(this);
		stack = new Stack(this);
		constants = new ConstantPool(this);
		
	}


	public function increaseBuffer() {
		if (memory.length > maxMemorySize) {
			Runtime.throwError(ErrorMessage('Out of memory'), MEMORY);
		}
		var size = MathTools.min(memory.length + memoryChunkSize, maxMemorySize);
		var delta = size - memory.length;
		memory.resize(size);
		reserved.resize(size);
		reserved.fill(memory.length - delta, memory.length, 0);
	}

	public function sizeOf(token:InterpTokens):Int {
		switch token {
			case ConditionCall(_, _, _) | FunctionCall(_, _) | Expression(_, _) | PropertyAccess(_, _) | Identifier(_): return sizeOf(/* Actions.evaluate(token) */ null /**will change after im done testing memory**/);
			case Write(_, v): return sizeOf(v);
			case TypeCast(v, _): return sizeOf(v);
			case Block(body, _): return sizeOf(Characters(ByteCode.compile(...body)));
			case Number(num): return 4;
			case Decimal(num): return 8;
			case Characters(string) | Sign(string): return string.length; // 8 bit
			case NullValue | FalseValue | TrueValue: return 1;
			case ErrorMessage(msg): return msg.length * 2;
			case _: 
		}

		Runtime.throwError(ErrorMessage('Unable to get size of token `$token`'), MEMORY_SIZE_EVALUATOR);
		return -1;
	}

	/**
		General-purpose memory allocation for objects:

		- if `token` is `true`, `false`, `0`, or `null`, it pulls a pointer from the constant pool
		- if `token` is a string, a number, a sign or a decimal, it pulls a pointer from the stack.
		- if `token` is a structure, it stores it on the heap, and returns a pointer to it.
	**/
	public function store(token:InterpTokens):MemoryPointer {
		if (token.is(TRUE_VALUE, FALSE_VALUE, NULL_VALUE)) {
			return constants.get(token);
		} else if (token.staticallyStorable()) {
			return heap.storeStatic(token);
		} else if (token.is(OBJECT)) {
			return heap.storeObject(token);
		}

		Runtime.throwError(ErrorMessage('Unable to allocate memory for token `$token`.'), MEMORY_HEAP);

		return constants.NULL;
	}

	/**
		Allocate `size` bytes of memory.
	    @param size The number of bytes to allocate
	    @return A pointer to the allocated memory
	**/
	public function allocate(size:Int):MemoryPointer {
		if (size <= 0) Runtime.throwError(ErrorMessage('Cannot allocate ${size} bytes'));
		return heap.storeBytes(size);
	}

	/**
	    Reads a value of type `type` from `pointer`. Only "static" values can be read.
	    @param pointer The pointer to read from.
	    @param type The type of value to read.
	    @return A token representing the value.
	**/
	public function read(pointer:MemoryPointer, type:String):InterpTokens {
		switch type {
			case (_ == Little.keywords.TYPE_BOOLEAN => true): 
				return pointer.rawLocation == constants.TRUE.rawLocation ? TrueValue : FalseValue;
			case (_ == Little.keywords.TYPE_INT => true): {
				if (pointer == constants.NULL) return NullValue;
				if (pointer == constants.ZERO) return Number(0);
				return Number(heap.readInt32(pointer));
			}
			case (_ == Little.keywords.TYPE_FLOAT => true): {
				if (pointer == constants.NULL) return NullValue;
				if (pointer == constants.ZERO) return Decimal(0);
				return Decimal(heap.readDouble(pointer));
			}
			case (_ == Little.keywords.TYPE_STRING => true): {
				if (pointer == constants.NULL) return NullValue;
				return Characters(heap.readString(pointer));
			}
			case _: {
				Runtime.throwError(ErrorMessage('Cannot statically read object of type `$type`.'));
				return NullValue;
			}
		}
	}


	public function getTypeInformation(name:String):TypeInfo {

		var block = stack.getCurrentBlock();
		var reference = block.get(name);
		var typeInfo:Heap.TypeBlocks = heap.readType(reference);

		return {
			pointer: reference.address,
			typeName: name,
			instanceByteSize: typeInfo.instanceByteSize,
			staticByteSize: typeInfo.staticByteSize,
			classByteSize: typeInfo.classByteSize,
		}
	}

	public function getTypeName(pointer:MemoryPointer):String {
		var block = stack.getCurrentBlock();

		for (key => value in block) {
			if (value.address == pointer) {
				return key;
			}
		}

		throw 'Cannot retrieve name of type at $pointer';
	}

	public function stringifyMemoryBytes():String {
		var s = "\n";
		for (i in 0...memory.length) {
			s += StringTools.hex(memory[i], 2) + " ";
		}

		return s;
	}
	public function stringifyReservedBytes():String {
		var s = "\n";
		for (i in 0...reserved.length) {
			s += TextTools.multiply(reserved[i] + "", 2) + " ";
		}
		return s;
	}
}

typedef TypeInfo = {
	pointer:MemoryPointer,
	typeName:String,
	instanceByteSize:Int,
	staticByteSize:Int,
	classByteSize:Int,
}