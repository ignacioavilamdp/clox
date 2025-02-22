#include <stdio.h>
#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int arg, const char* argv[]){
    initVM();

    Chunk chunk;
    initChunk(&chunk);

    // 1.2 constant
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    // 3.4 constant
    constant = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    // sum
    writeChunk(&chunk, OP_ADD, 123);

    // 5.6 constant
    constant = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    
    // divide
    writeChunk(&chunk, OP_DIVIDE, 123);
    
    // negate
    writeChunk(&chunk, OP_NEGATE, 123);
    
    // return
    writeChunk(&chunk, OP_RETURN, 123);

    // disassemble and interpret
    disassembleChunk(&chunk, "test chunk");
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);

    return 0;
}