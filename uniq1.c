#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uniq(FILE *file) {
	    char line[256];
	        char prev_line[256] = "";

		    while (fgets(line, sizeof(line), file) != NULL) {
			            if (strcmp(line, prev_line) != 0) {
					                printf("%s", line);
							            strcpy(prev_line, line);
								            }
				        }
}

int main(int argc, char *argv[]) {
	    if (argc != 2) {
		            printf("Usage: ./uniq <filename>\n");
			            return 1;
				        }
char *filename = argv[1];
    FILE *file = fopen(filename, "r");
        if (file == NULL) {
		        perror("fopen");
			        return 1;
				    }

	    uniq(file);

	        fclose(file);
		    return 0;
}

