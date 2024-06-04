#include <stdio.h>  // 표준 입출력 함수를 사용하기 위한 헤더 파일
#include <stdlib.h> // 일반 유틸리티 함수를 사용하기 위한 헤더 파일
#include <sys/stat.h> // 파일 상태 정보를 가져오는 함수를 사용하기 위한 헤더 파일

int main(int argc, char *argv[]) {
    // 명령행 인자의 수가 3이 아닌 경우 사용법을 출력하고 프로그램을 종료
    if (argc != 3) {
        printf("사용법: %s [퍼미션] [파일 경로]\n", argv[0]);
        return 1;
    }

    char *permissionString = argv[1]; // 첫 번째 명령행 인자를 퍼미션 문자열로 저장
    char *filePath = argv[2]; // 두 번째 명령행 인자를 파일 경로로 저장

    // 퍼미션 문자열을 8진수 정수로 변환
    int permission = strtol(permissionString, NULL, 8);

    // chmod 함수를 사용하여 파일의 퍼미션을 변경
    // 변경에 실패한 경우 1을 반환하여 프로그램을 종료
    if (chmod(filePath, permission) == -1) {
        return 1;
    }

    // 프로그램이 성공적으로 종료
    return 0;
}

