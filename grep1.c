#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
	if (argc < 3) {
		        printf("사용법: %s 검색어 파일명\n", argv[0]);
			        return 1;
				    }
	const char *search_word = argv[1];
	    const char *filename = argv[2];

	 FILE *file = fopen(filename, "r");
	     if (file == NULL) {
		             perror("파일 열기 실패");
			             return 1;
				         }
	 char line[MAX_LINE_LENGTH];
	     while (fgets(line, sizeof(line), file)) {

	if (strstr(line, search_word) != NULL) {
		             printf("%s", line);
			             }
	    }

	      fclose(file);

	          return 0;
}

