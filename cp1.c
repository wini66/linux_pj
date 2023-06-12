#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc < 3) {
		        printf("사용법: %s 소스파일 대상파일\n", argv[0]);
			        return 1;
				    }
	const char *source_file = argv[1];
	const char *target_file = argv[2];

	FILE *source = fopen(source_file, "r");
	    if (source == NULL) {
		            perror("fopen");
			            return 1;
				        }
	 FILE *target = fopen(target_file, "w");
	     if (target == NULL) {
		             perror("fopen");
			             fclose(source);
				             return 1;
					         }
	  int ch;
          while ((ch = fgetc(source)) != EOF) {
	        fputc(ch, target);
          }

 fclose(source);
    fclose(target);

       printf("파일 '%s'이(가) '%s'로 복사되었습니다.\n", source_file, target_file);

       return 0;
} 
