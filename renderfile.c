#include "renderfile.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//reads text files and converts them into a string
char * renderFile(const char *filename) {
    FILE* file = fopen(filename, "r");

	if (file == NULL) {
		return NULL;
	}else {
		//printf("%s does exist \n", filename);
	}

	fseek(file, 0, SEEK_END);
	long fsize = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* temp = malloc(sizeof(char) * (fsize+1));
	char ch;
	int i = 0;
	while((ch = fgetc(file)) != EOF) {
		temp[i] = ch;
		i++;
	}
	fclose(file);
	return temp;

}
//reads binary files and converts them into a string
//same thing as renderFile, but reads binary files instead
char *renderBinary(const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        return NULL;
    } else {
        //printf("%s does exist \n", filename);
    }

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *temp = malloc(sizeof(char) * (fsize + 1));
    fread(temp, 1, fsize, file);
    //temp[fsize] = '\0'; // Null-terminate the string (optional)

    fclose(file);
    return temp;
}