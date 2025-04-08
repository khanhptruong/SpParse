#include "SpParse.h"

#define NUM_ARGS 4

int main(int argc, char* argv[]) {
	arg_t args[NUM_ARGS] = {
		{ at_pos,   0, false, NULL },
		{ at_pos,   0, false, NULL },
		{ at_flg, '?', false, NULL},
		{ at_val, 'f', false, NULL}
	};

	parseArgs(args, NUM_ARGS, argc, argv);
	printArgs(args, NUM_ARGS);
}