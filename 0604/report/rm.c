#include <stdio.h>  // 표준 입출력 함수를 사용하기 위한 헤더 파일
#include <sys/stat.h> // 파일 상태 정보를 가져오는 함수를 사용하기 위한 헤더 파일
#include <unistd.h> // POSIX 운영체제 API를 사용하기 위한 헤더 파일

int main(int argc, char *argv[]) { // 메인 함수 시작
    int opt; // getopt 함수의 반환값을 저장할 변수
    int seccess_message = 0; // -v 옵션을 저장할 변수
    int remove_directory = 0; // -d 옵션을 저장할 변수

    // 명령행 인자를 처리
    while ((opt = getopt(argc, argv, "vd")) != -1) {
        switch (opt) {
            case 'v': // -v 옵션이 주어진 경우
                seccess_message = 1;
                break;
            case 'd': // -d 옵션이 주어진 경우
                remove_directory = 1;
                break;
            default : // 그 외의 경우
                fprintf(stderr, "사용법 : rm [옵션] [파일]\n");
                return 1;
        }
    }

    // 명령행 인자로 주어진 파일에 대해
    if (optind >= argc) {
        printf("사용법: %s [디렉토리 경로]\n", argv[0]);
        return 1;
    }

    for (int i = optind; i < argc; i++) {
        struct stat file_stat; // 파일 상태 정보를 저장할 구조체
        char *file = argv[i]; // 파일 이름을 저장

        // stat 함수를 사용하여 파일 상태 정보를 가져옴
        if (stat(file, &file_stat) == 0) {
            // 파일이 디렉토리인 경우
            if (S_ISDIR(file_stat.st_mode)) {
                // rmdir 함수를 사용하여 디렉토리를 삭제
                int result = rmdir(file);
                // 삭제에 성공한 경우
                if (result == 0) {
                    // -v 옵션이 주어진 경우 삭제 성공 메시지를 출력
                    if(seccess_message){
                        printf("removed '%s'\n", argv[i]);
                    }
                } else { // 삭제에 실패한 경우
                    // -v 옵션이 주어진 경우 삭제 실패 메시지를 출력
                    if(seccess_message){
                        printf("rm: cannot remove '%s'\n", argv[i]);
                    }
                return 1;
                }
            } else { // 파일이 디렉토리가 아닌 경우
                // remove 함수를 사용하여 파일을 삭제
                int result = remove(file);
                // 삭제에 성공한 경우
                if (result == 0) {
                    // -v 옵션이 주어진 경우 삭제 성공 메시지를 출력
                    if(seccess_message){
                        printf("removed '%s'\n", argv[i]);
                    }
                } else { // 삭제에 실패한 경우
                    // -v 옵션이 주어진 경우 삭제 실패 메시지를 출력
                    if(seccess_message){
                        printf("rm: cannot remove '%s'\n", argv[i]);
                    }
                return 1;
                }
            }
        } else { // 파일 상태 정보를 가져오지 못한 경우 오류 메시지를 출력
            printf("Failed to retrieve file status.\n");
        }

        return 0; // 프로그램이 성공적으로 종료
    }
}

