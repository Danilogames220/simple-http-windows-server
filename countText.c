#include <stdio.h>
#include <string.h>
#include "renderfile.h"

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		printf("No arguments have ben given!!!\n");
		return 1;
	}
	const unsigned long long int fileSize = strlen(renderFile(argv[1]));
	printf("file (%s) has (%llu) caracters of text\n", argv[1], fileSize);
	return 0;
}
