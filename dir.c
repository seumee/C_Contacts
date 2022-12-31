#include "Func.h"

void SetDir() {
	int Dir = _chdir("WorkSpace");
	if (Dir == -1) {
		if (_mkdir("WorkSpace") == 0)	printf("Create Directory Success!\n");
		if (_chdir("WorkSpace") == 0) {
			printf("Set Directory Success!\n");
		}
	}
	else printf("Set Directory Success!\n");
	printf("\n");

	return;
}