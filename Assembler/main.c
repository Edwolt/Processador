#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.h"

// -m MIF file
// -b binary file
// -0 text file with 0s and 1s of all memory
int main(int argc, char const *argv[]) {
    if (argc < 3) {
        printf("Missing arguments\n");
        return EXIT_FAILURE;
    }

    int i, j;

    int memory[TAM_MEM];
    for (i = 0; i < TAM_MEM; i++) {
        memory[i] = 0;
    }

    FILE *source = fopen(argv[1], "r");
    FILE *dest = fopen(argv[2], "wb");

    char name[20];
    int instruction;

    i = 0;
    while (fscanf(source, " %s", name) == 1) {
        if (strcmp(name, "j")) {
            instruction = OP_J << 12;
        } else if (strcmp(name, "cmp") == 1) {
            instruction = OP_CMP << 12;
        } else if (strcmp(name, "store") == 1) {
            instruction = OP_STORE << 12;
        } else if (strcmp(name, "load") == 1) {
            instruction = OP_LOAD << 12;
        } else if (strcmp(name, "in") == 1) {
            instruction = OP_INOUT << 12;
        } else if (strcmp(name, "out") == 1) {
            instruction = OP_INOUT << 12;
        } else if (strcmp(name, "set") == 1) {
            instruction = OP_SET << 12;
        } else if (strcmp(name, "move") == 1) {
            instruction = OP_MOVE << 12;
        } else if (strcmp(name, "add") == 1) {
            instruction = OP_ADD << 12;
        } else if (strcmp(name, "sub") == 1) {
            instruction = OP_SUB << 12;
        } else if (strcmp(name, "mul") == 1) {
            instruction = OP_MUL << 12;
        } else if (strcmp(name, "div") == 1) {
            instruction = OP_DIV << 12;
        } else if (strcmp(name, "and") == 1) {
            instruction = OP_AND << 12;
        } else if (strcmp(name, "or") == 1) {
            instruction = OP_OR << 12;
        } else if (strcmp(name, "xor") == 1) {
            instruction = OP_XOR << 12;
        } else if (strcmp(name, "not") == 1) {
            instruction = OP_NOT << 12;
        }
        memory[i] = instruction;
        i++;
    }

    for (i = TAM_MEM; i > 0; i--) {
        if (memory[i] != 0) break;
    }

    fwrite(&i, sizeof(int), 1, dest);

    for (j = 0; j <= i; j++) {
        fwrite(memory + j, sizeof(int), 1, dest);
    }

    fclose(source);
    fclose(dest);
}