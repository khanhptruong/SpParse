#include "SpParse.h"

void parseArgs(arg_t args[], size_t numArgs, int argc, char* argv[]) {
	for (int argvIndex = 1; argvIndex < argc; ++argvIndex) {
		// Store Pos Arg
		if (*(argv[argvIndex]) != '/') {
			for (int i = 0; i < numArgs; ++i) {
				if (args[i].argTyp != at_pos) continue;
				if (args[i].isSet == true) continue;
				args[i].isSet = true;
				args[i].value = argv[argvIndex];
				break;
			}
			continue;
		}

		// Set Flag
		for (int i = 0; i < numArgs; ++i) {
			if (*(argv[argvIndex] + 1) != args[i].flag) continue;
			args[i].isSet = true;
			if (args[i].argTyp == at_flg) break;

			// Store Val Arg
			++argvIndex;
			args[i].value = argv[argvIndex];
			break;
		}
	}
}

void printArgs(arg_t args[], size_t numArgs) {
	puts("Arg Table:");
	puts("[Flag][Is-Set][Value]");
	for (int i = 0; i < numArgs; ++i) {
		char flg;
		if (args[i].argTyp == at_pos) flg = '_';
		else flg = args[i].flag;
		printf(" %c     %d       %s\n", flg, args[i].isSet, args[i].value);
	}
}