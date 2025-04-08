Spartan Parse (SpParse) is an extremely simple, small, lightweight library for
parsing command line parameters.

It is NOT safe, it is prone undefined behavior on improper inputs.

The purpose is to be quick and dirty, for prototyping or small personal
projects.

### Usage:

Initialize arguments with an array of arg_t:

	arg_t args[NUM_ARGS] = {
		{ at_pos,   0, false, NULL },
		{ at_pos,   0, false, NULL },
		{ at_flg, '?', false, NULL},
		{ at_val, 'f', false, NULL}
	};

at_pos is a positional argument
at_flg is a flag input of one character length, ie /?
at_val is a flag input with a value, ie /s "string"

All args must be initialize with false, NULL

### Building:

A CMakeLists.txt file is included for easy building of the library. To include
in your CMake project, see example below:

cmake_minimum_required(VERSION 3.12) #this specific version is not required
project(MY_PROJECT)

include_directories(SpParse)
add_subdirectory(SpParse)

#Build the executable
add_executable(MY_PROJECT MY_PROJECT.c)

#Link the executable with the library
target_link_libraries(MY_PROJECT SpParse)

