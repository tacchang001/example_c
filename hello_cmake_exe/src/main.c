#include <stdio.h>

#include "hello.h"

int main(int argc, char *argv[]) {
	if (argc == 2) {
		const char *message = argv[1];
		say(message);
	}
	return 0;
}

