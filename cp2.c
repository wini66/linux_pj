#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void copy_file(const char *source, const char *destination, int recursive, int interactive, int verbose) {
	    FILE *src_file = fopen(source, "r");
	        if (src_file == NULL) {
			        perror("파일 열기 실패");
				        return;
					    }
FILE *dest_file = fopen(destination, "w");
    if (dest_file == NULL) {
	            perror("파일 생성 실패");
		            fclose(src_file);
			            return;
				        }

char buffer[1024];
    size_t read_bytes;
        while ((read_bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
		        fwrite(buffer, 1, read_bytes, dest_file);
			    }
 fclose(src_file);
     fclose(dest_file);

     if (verbose) {
	             printf("'%s' 파일이 '%s'로 복사되었습니다.\n", source, destination);
		         }
}

int main(int argc, char *argv[]) {
	int recursive = 0;
	int interactive = 0;
	int verbose = 0;

if (argc < 3) {
	        printf("사용법: %s 옵션 소스파일 대상파일\n", argv[0]);
		        return 1;
			    }
for (int i = 1; i < argc - 2; i++) {
	        if (strcmp(argv[i], "-r") == 0) {
		            recursive = 1;
		          } else if (strcmp(argv[i], "-i") == 0) {	
		    	    interactive = 1;
		        } else if (strcmp(argv[i], "-v") == 0) {
		            verbose = 1;
		            }
		    }

const char *source = argv[argc - 2];
    const char *destination = argv[argc - 1];

    if (recursive) {
	            char command[256];
		            snprintf(command, sizeof(command), "cp -r %s %s", source, destination);
 system(command);
     } else {
	    if (interactive) {
	printf("'%s' 파일을 '%s'로 복사하시겠습니까? (y/n) ", source, destination);
	            char answer[2];
		                fgets(answer, sizeof(answer), stdin);
	if (answer[0] == 'y' || answer[0] == 'Y') {
	copy_file(source, destination, recursive, interactive, verbose);
	            } else {
printf("복사가 취소되었습니다.\n");
 }
	 } else {
		             copy_file(source, destination, recursive, interactive, verbose);
			             }
	        }
    return 0;
}
