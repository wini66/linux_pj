# LINUX 명령어 구현

## cd 명령어 구현

![image](https://github.com/wini66/linux_pj/assets/119557644/b3e32727-020c-4c61-9c23-b531ce6fcdc3)

cd 명령어는 change directory의 줄임말로 현재 작업 중인 디렉토리의 위치를 이동하는 명령어이다. 

./cd1로 실행하면 사용법을 알려주고 ./cd1 .(디렉토리)를 실행하면 현재 디렉토리로 이동하게 된다. 

## pwd 명령어 구현

![image](https://github.com/wini66/linux_pj/assets/119557644/b5eeeb02-18da-4aa1-aa59-df5eeb0ac65a)

pwd는 현재 디렉토리를 알려주는 명령어로 실행시 현재 디렉토리 경로가 출력된다.

## ls 명령어 구현

![image](https://github.com/wini66/linux_pj/assets/119557644/4a7aa65c-7cf4-47da-92bf-e2a810b24ed4)

ls는  디렉토리 내의 파일 및 디렉토리 정보를 출력하는 명령어다.

-opendir("."): 현재 디렉토리를 엽니다. 디렉토리를 열지 못한 경우 opendir 함수는 NULL을 반환하며, 이때는 에러 메시지를 출력하고 프로그램을 종료합니다.

-readdir(dir): 디렉토리 내의 다음 파일 또는 디렉토리 정보를 읽습니다. 읽은 정보는 struct dirent 구조체에 저장되며, 반복문을 통해 모든 파일과 디렉토리에 대해 순차적으로 출력합니다.

-closedir(dir): 디렉토리를 닫습니다.

##


