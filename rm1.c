#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		        printf("사용법: %s 파일1 파일2 파일3...\n", argv[0]);
			        return 1;
				    }
	for (int i = 1; i < argc; i++) {
	        if (unlink(argv[i]) == -1) {
	            perror("unlink");
		                return 1;
				  } else {
	             printf("파일 '%s'가 삭제되었습니다.\n", argv[i]);
	             }
			  }
	    return 0;

}
