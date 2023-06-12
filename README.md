# LINUX 명령어 구현

## 1 cd 명령어 구현

![image](https://github.com/wini66/linux_pj/assets/119557644/b3e32727-020c-4c61-9c23-b531ce6fcdc3)

cd 명령어는 change directory의 줄임말로 현재 작업 중인 디렉토리의 위치를 이동하는 명령어이다. 

./cd1로 실행하면 사용법을 알려주고 ./cd1 .(디렉토리)를 실행하면 현재 디렉토리로 이동하게 된다. 

## 2 pwd 명령어 구현

![image](https://github.com/wini66/linux_pj/assets/119557644/b5eeeb02-18da-4aa1-aa59-df5eeb0ac65a)

pwd는 현재 디렉토리를 알려주는 명령어로 실행시 현재 디렉토리 경로가 출력된다.

## 3 ls 명령어 구현

![image](https://github.com/wini66/linux_pj/assets/119557644/4a7aa65c-7cf4-47da-92bf-e2a810b24ed4)

ls는  디렉토리 내의 파일 및 디렉토리 정보를 출력하는 명령어다.

-opendir("."): 현재 디렉토리를 엽니다. 디렉토리를 열지 못한 경우 opendir 함수는 NULL을 반환하며, 이때는 에러 메시지를 출력하고 프로그램을 종료합니다.

-readdir(dir): 디렉토리 내의 다음 파일 또는 디렉토리 정보를 읽습니다. 읽은 정보는 struct dirent 구조체에 저장되며, 반복문을 통해 모든 파일과 디렉토리에 대해 순차적으로 출력합니다.

-closedir(dir): 디렉토리를 닫습니다.

## 4 mkdir 명령어 구현

![image](https://github.com/wini66/linux_pj/assets/119557644/5ba945a4-25ee-4f2b-a2d9-89c5cd4e64e3)

mkdir을 통해 디렉토리를 생성할 수 있다. 

'const char *directory_name = argv[1];은 프로그램 실행 시 전달된 명령줄 인수(argument) 중에서 두 번째(argv[1]) 인수를 가리키는 포인터 변수 directory_name에 할당하는 구문입니다.

여기서 argv는 프로그램 실행 시 전달되는 명령줄 인수들을 담고 있는 문자열 배열입니다. 첫 번째 인수 argv[0]는 프로그램의 이름(실행 파일 이름)을 가리키고, 두 번째 인수 argv[1]부터는 사용자가 입력한 명령어 인수들이 차례로 저장됩니다.

따라서 const char *directory_name = argv[1];은 두 번째 인수인 디렉토리명을 가리키는 포인터 변수 directory_name에 할당하는 것입니다. 이렇게 함으로써 프로그램에서는 directory_name을 통해 사용자가 입력한 디렉토리명에 접근하고 활용할 수 있습니다.

## 5 rm 명령어 구현

![image](https://github.com/wini66/linux_pj/assets/119557644/abfbb4f3-8b4c-47f6-bec9-c3368efa9450)

파일이나 디렉토리를 삭제하는 명령어이다.

각 파일에 대해 unlink() 함수를 호출하여 파일을 삭제한다.

## 6 cp 명령어 구현

![cp1](https://github.com/wini66/linux_pj/assets/119557644/3f3aedb2-557f-4e49-abf1-405e1ca30248)

cp는 파일을 복사하는 명령어이다. cat으로 실행해보면 정상적으로 복사되었음을 확인할 수 있다.

## 7 cat 명령어 구현

![image](https://github.com/wini66/linux_pj/assets/119557644/eea17418-b944-45be-a3f6-3271905927bb)

파일 내용을 출력하는 명령어다.

먼저, main 함수를 정의합니다. 이 함수는 프로그램의 진입점으로, 프로그램이 실행될 때 가장 먼저 호출되는 함수입니다.

argc와 argv 매개변수를 통해 프로그램 실행 시 전달된 명령행 인수를 받습니다. argc는 명령행 인수의 개수를 나타내는 정수이고, argv는 문자열 배열로 실제 명령행 인수의 값들을 포함합니다.

argc 값이 2 미만인 경우, 즉 파일명이 주어지지 않은 경우 사용법을 출력하고 프로그램을 종료합니다.

argv[1]을 통해 명령행 인수로 전달된 파일명을 가져옵니다.

fopen 함수를 사용하여 파일을 읽기 모드로 엽니다. 파일 열기에 실패한 경우, perror 함수를 사용하여 오류 메시지를 출력하고 프로그램을 종료합니다.

fgetc 함수를 사용하여 파일로부터 문자를 읽어옵니다. fgetc 함수는 파일에서 한 문자씩 읽어오며, 읽은 문자를 putchar 함수를 사용하여 터미널에 출력합니다. 파일의 끝에 도달할 때까지 이 과정을 반복합니다.

파일 읽기가 완료되면 파일을 닫습니다. fclose 함수를 사용하여 파일을 닫습니다.

return 0 문을 통해 프로그램을 정상적으로 종료합니다.

## 8 touch 명령어 구현

![image](https://github.com/wini66/linux_pj/assets/119557644/782ea223-8726-491a-afc8-65efc7057786)

touch는 파일 생성 또는 수정 시간을 갱신하는 명령어이다.

위 코드는 파일을 생성하고 파일 디스크립터를 닫는 간단한 과정으로 touch 명령어의 주요 기능을 수행합니다. 실행 시 파일명이 주어지지 않은 경우에는 프로그램이 종료되고, 파일명이 주어진 경우 해당 파일을 생성하거나 수정하여 수정 시간을 갱신합니다.

## 9 echo 명령어 구현

![image](https://github.com/wini66/linux_pj/assets/119557644/14c89eab-e412-4b52-8ac9-6af9e3d6c362)

echo는 텍스트를 출력하는 명령어이다.

argc와 argv는 main 함수의 인자로 전달되는 값입니다. argc는 전달된 인자의 개수를 나타내며, argv는 전달된 인자들의 문자열 배열입니다. argv[0]은 프로그램의 실행 경로를 나타내는 문자열이며, argv[1]부터 실제 전달된 인자들이 저장되어 있습니다.

for 루프를 사용하여 argv 배열을 인덱스 1부터 끝까지 순회합니다. i 변수는 인덱스를 나타냅니다.

각 인자인 argv[i]를 printf 함수를 사용하여 출력합니다.

if 문을 사용하여 현재 인자가 마지막 인자가 아닌 경우에만 공백 문자를 출력합니다.

마지막으로 printf 함수를 사용하여 새 줄을 출력합니다.

이렇게 구현된 코드를 실행하면 프로그램 실행 시 전달된 인자들이 공백으로 구분되어 출력됩니다.

## 10 grep 명령어 구현

![image](https://github.com/wini66/linux_pj/assets/119557644/90844291-1d76-4946-ac99-93fb0c58de8a)

파일내에서 특정 문자열을 검색하는 명령어이다.

사용자는 검색어와 파일명을 프로그램에 인자로 전달합니다. 프로그램은 해당 파일을 열고, 파일의 각 줄을 읽어와서 검색어가 포함된 줄을 출력합니다.

argc와 argv: 프로그램을 실행할 때 전달되는 인자의 개수와 값에 접근하기 위해 사용합니다. argc는 인자의 개수를 나타내며, argv는 인자의 값을 저장한 배열입니다. 첫 번째 인자 argv[0]에는 프로그램의 실행 경로가 저장되어 있습니다.

파일 열기: fopen 함수를 사용하여 지정된 파일을 읽기 모드로 엽니다. 파일 열기에 실패하면 NULL이 반환되며, perror 함수를 사용하여 오류 메시지를 출력합니다.

파일 내용 검색: fgets 함수를 사용하여 파일에서 한 줄씩 읽어옵니다. 각 줄에서 strstr 함수를 사용하여 검색어가 포함되어 있는지 확인합니다. 검색어가 포함된 줄은 출력됩니다.

파일 닫기: fclose 함수를 사용하여 파일을 닫습니다. 파일 작업이 완료되면 항상 파일을 닫아야 합니다.

## 11 chmod 명령어 구현

![image](https://github.com/wini66/linux_pj/assets/119557644/574dbb05-5af4-4923-ae4d-25f2aa5f490f)

파일 또는 디렉토리의 권한을 변경하는 명령어이다. 여기서 755는 파일의 권한을 표현하는 숫자로 '-rwxr-xr-x'같은 뜻이며 이는 소유자에게 읽기, 쓰기, 실행 권한이 있고, 그룹과 기타 사용자에게는 읽기와 실행 권한이 있는 것을 나타냅니다. 

사용자는 변경할 권한 모드와 대상 파일명을 프로그램에 인자로 전달합니다. 프로그램은 해당 파일의 권한을 설정합니다.

strtol 함수: 문자열을 숫자로 변환하는 함수입니다. mode 문자열을 8진수로 변환하여 권한 모드를 설정합니다.

chmod 함수: 파일의 권한을 설정하는 함수입니다. filename과 chmod_result 값을 전달하여 파일의 권한을 변경합니다. 변경에 실패하면 perror 함수를 사용하여 오류 메시지를 출력합니다.

## 12 chown 명령어 구현

파일 또는 디렉토리의 소유자를 변경하는 명령어이다.

## 13 data 명령어 구현

현재 날짜와 시간을 출력하는 명령어이다.

## 14 wc 명령어 구현

파일 내의 단어,줄,문자 수 등을 계산하는 명령어이다.

## 15 head 명령어 구현

파일의 앞 부분을 일부 출력하는 명령어이다.


















