#include <stdio.h>

int main() {
	    int lines = 0;
	        int words = 0;
		    int characters = 0;
		        char ch;

			    printf("Enter some text (press Ctrl+D to end):\n");

			        while ((ch = getchar()) != EOF) {
					        characters++;

						        if (ch == '\n')
								            lines++;

							        if (ch == ' ' || ch == '\n' || ch == '\t')
									            words++;
								    }

				    printf("Lines: %d\n", lines);
				        printf("Words: %d\n", words);
					    printf("Characters: %d\n", characters);

					        return 0;
}

