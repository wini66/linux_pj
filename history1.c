#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HISTORY_SIZE 1000

int main() {
	char* history[HISTORY_SIZE];
	    int count = 0;

	char input[100];
	    printf("Enter a command: ");
	        fgets(input, sizeof(input), stdin);

	 history[count] = strdup(input);
	     count++;

	  printf("Command history:\n");
	      for (int i = 0; i < count; i++) {
		              printf("%d: %s", i+1, history[i]);
			          }
	    for (int i = 0; i < count; i++) {
		            free(history[i]);
			        }

	        return 0;
}

