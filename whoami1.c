#include <stdio.h>
#include <stdlib.h>

int main() {
	    char *username = getenv("USER");

	        if (username != NULL) {
			        printf("Current user: %s\n", username);
				    } else {
					            perror("getenv");
						            return 1;
							        }

		    return 0;
}

