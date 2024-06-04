#include <stdio.h>  // 표준 입출력 함수를 사용하기 위한 헤더 파일
#include <sys/stat.h> // 파일 상태 정보를 가져오는 함수를 사용하기 위한 헤더 파일
#include <unistd.h> // POSIX 운영체제 API를 사용하기 위한 헤더 파일

int main(int argc, char *argv[]) { // 메인 함수 시작
    int opt; // getopt 함수의 반환값을 저장할 변수
    int seccess_message = 0; // -v 옵션을 저장할 변수

    // 명령행 인자를 처리
    while ((opt = getopt(argc, argv, "v")) != -1) {
        switch (opt) {
            case 'v': // -v 옵션이 주어진 경우
                seccess_message = 1;
                break;
            default : // 그 외의 경우
                fprintf(stderr, "사용법 : rmdir [옵션] [파일]\n");
                return 1;
        }
    }

    // 명령행 인자로 주어진 디렉토리에 대해
    if (optind >= argc) {
        printf("사용법: %s [디렉토리 경로]\n", argv[0]);
        return 1;
    }

    for (int i = optind; i < argc; i++) {
        char *dirPath = argv[i]; // 디렉토리 경로를 저장

        // rmdir 함수를 사용하여 디렉토리를 삭제
        int result = rmdir(dirPath);
        // 삭제에 성공한 경우
        if (result == 0) {
            // -v 옵션이 주어진 경우 삭제 성공 메시지를 출력
            if(seccess_message){
                printf("rmdir: removing directory, '%s'\n", argv[i]);
            }
        } else { // 삭제에 실패한 경우
            printf("디렉토리 삭제에 실패했습니다.\n");
            return 1;
        }

        return 0; // 프로그램이 성공적으로 종료
    }
}

