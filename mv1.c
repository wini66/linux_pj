#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	    if (argc < 3) {
		            printf("사용법: %s <원본 파일 또는 디렉토리> <목적지 파일 또는 디렉토리>\n", argv[0]);
			            return 1;
				        }

	      
	        int result = rename(argv[1], argv[2]);

		    if (result == 0) {
			            printf("%s가 %s로 이동되었습니다.\n", argv[1], argv[2]);
				        } else {
						        perror("mv");
							        return 1;
								    }

		        return 0;
}



