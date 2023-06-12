#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	 if (argc < 3) {
		         printf("사용법: %s 모드 파일\n", argv[0]);
			         return 1;
				     }
 const char *mode = argv[1];
     const char *filename = argv[2];

     int chmod_result = strtol(mode, 0, 8);
         if (chmod_result == 0) {
		         perror("모드 변환 실패");
			         return 1;
				     }
	 if (chmod(filename, chmod_result) != 0) {
		         perror("chmod");
			         return 1;
				     }

	     return 0;
}

