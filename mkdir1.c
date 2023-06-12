#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("사용법: %s 디렉토리명\n", argv[0]);
		return 1;
		    }

	    const char *directory_name = argv[1];
	     int result = mkdir(directory_name, 0777);

	         if (result == 0) {
			         printf("디렉토리 '%s'가 생성되었습니다.\n", directory_name);
				     } else {
					             perror("mkdir");
						             return 1;
							         }

		     return 0;
}
