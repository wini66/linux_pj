#include <stdio.h>

int main(int argc, char *argv[]) {
	    if (argc < 2) {
		    printf("사용법: %s 파일명\n", argv[0]);
		            return 1;
			        }
	     const char *filename = argv[1];

	     FILE *file = fopen(filename, "r");
	         if (file == NULL) {
			         perror("파일 열기 오류");
				         return 1;
					     }
	 char ch;
	     while ((ch = fgetc(file)) != EOF) {
		             putchar(ch);
			         }

	      fclose(file);
	          return 0;
}


