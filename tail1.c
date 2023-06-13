#include <stdio.h>
#include <stdlib.h>

void tail(const char *filename, int num_lines) {
	    FILE *file = fopen(filename, "r");
	        if (file == NULL) {
			        perror("fopen");
				        return;
					    }
fseek(file, 0, SEEK_END);
    long long file_size = ftell(file);
        if (file_size < 0) {
		        perror("ftell");
			        fclose(file);
				        return;
					    }
if (file_size <= num_lines) {
	        rewind(file);
		        int c;
			        while ((c = getc(file)) != EOF) {
					            putchar(c);
						            }
} else {
 fseek(file, -num_lines, SEEK_END);
         int c;
	         while ((c = getc(file)) != EOF) {
			             putchar(c);
				             }
		     }

    fclose(file);
    }

int main(int argc, char *argv[]) {
if (argc != 3) {
        printf("Usage: ./tail <filename> <num_lines>\n");
        return 1;
    }

char *filename = argv[1];
    int num_lines = atoi(argv[2]);

  tail(filename, num_lines);

      return 0;
}
