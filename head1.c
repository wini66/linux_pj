#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 10

int main(int argc, char *argv[]) {
	    if (argc < 2) {
		            printf("사용법: %s 파일명\n", argv[0]);
			            return 1;
				        }

	        FILE *file = fopen(argv[1], "r");
		    if (file == NULL) {
			            printf("파일을 열 수 없습니다: %s\n", argv[1]);
				            return 1;
					        }

		        char line[256];
			    for (int i = 0; i < MAX_LINES && fgets(line, sizeof(line), file); i++) {
				            printf("%s", line);
					        }

			        fclose(file);

				    return 0;
}

