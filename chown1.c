#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	    if (argc < 3) {
		            printf("사용법: %s 사용자:그룹 파일명\n", argv[0]);
			            return 1;
				        }
	    const char *owner_group = argv[1];
	        const char *filename = argv[2];

		    if (chown(filename, -1, -1) == -1) {
			            perror("chown");
				            return 1;
					        }

		        if (chown(filename, -1, atoi(owner_group)) == -1) {
				        perror("chown");
					        return 1;
						    }

			    printf("파일 '%s'의 소유자와 그룹을 '%s'로 변경하였습니다.\n", filename, owner_group);

			        return 0;
}


