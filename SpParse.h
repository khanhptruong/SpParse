#ifndef SPPARSE_H
#define SPPARSE_H

#include <stdio.h>
#include <stdbool.h>

typedef enum ArgType {
	at_pos, //positional argument
	at_flg, //flag without value
	at_val  //flag with value
} argType_t;

typedef struct ArgObj {
	argType_t argTyp;
	char flag;
	bool isSet;
	char* value;
} arg_t;

void parseArgs(arg_t args[], size_t numArgs, int argc, char* argv[]);
void printArgs(arg_t args[], size_t numArgs);

#endif // !SPPARSE_H
