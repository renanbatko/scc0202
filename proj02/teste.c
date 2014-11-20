#include <stdlib.h>
#include <stdio.h>
#define ENTER 10

char *readline() {
	char *command = NULL;
	char ch;
	int counter = 0;
	
	do {
		ch = fgetc(stdin);
		command = (char *) realloc(command, (counter+1) * sizeof(char));
		command[counter++] = ch;
	} while (ch != ENTER);
	command[counter-1] = '\0';
	
	return command;
}

int main() {
	char *palavra;
	palavra = readline();
	
	printf("palavra: %s\n", palavra);
	
	free(palavra);
	return 0;
}