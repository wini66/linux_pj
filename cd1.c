#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[0]){
	// 인자 개수 확인
	if (argc != 2) {
		printf("사용법: %s 디렉토리\n", argv[0]);
		return 1;
	}
	//디렉토리 변경
	int result = chdir(argv[1]);
	if (result != 0) {
		perror("chdir");
		return 1;
	}
	//변경된 디렉토리 경로 출력
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("현재 디렉토리: %s\n",cwd);
	} else {
		perror("getcwd");
		return 1;
	}
	return 0;
}
