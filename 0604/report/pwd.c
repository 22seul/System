#include <stdio.h>  // 표준 입출력 함수를 사용하기 위한 헤더 파일
#include <unistd.h> // POSIX 운영체제 API를 사용하기 위한 헤더 파일

int main() { // 메인 함수 시작
    char cwd[4096]; // 현재 작업 디렉토리 경로를 저장할 문자열

    // getcwd 함수를 사용하여 현재 작업 디렉토리 경로를 가져옴
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd); // 현재 작업 디렉토리 경로를 출력
    } else { // 현재 작업 디렉토리 경로를 가져오지 못한 경우 오류 메시지를 출력하고 프로그램을 종료
        printf("현재 작업 디렉토리 경로를 얻을 수 없습니다.\n");
        return 1;
    }

    return 0; // 프로그램이 성공적으로 종료
}

