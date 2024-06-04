#include <stdio.h>  // 표준 입출력 함수를 사용하기 위한 헤더 파일
#include <unistd.h> // POSIX 운영체제 API를 사용하기 위한 헤더 파일
#include <stdlib.h> // 일반 유틸리티 함수를 사용하기 위한 헤더 파일
#include <string.h> // 문자열 처리 함수를 사용하기 위한 헤더 파일

int main(int argc, char *argv[]) { // 메인 함수 시작
    int opt; // getopt 함수의 반환값을 저장할 변수
    int verbose = 0; // -v 옵션을 저장할 변수
    int quiet = 0; // -q 옵션을 저장할 변수
    int num_minus = 0; // -n 옵션의 값이 음수인지를 저장할 변수

    int num_lines = 10; // 출력할 줄의 수를 저장할 변수
    const char *file_name; // 파일 이름을 저장할 변수
    FILE *file; // 파일 포인터

    // 명령행 인자를 처리
    while ((opt = getopt(argc, argv, "vqn:")) != -1) {
        switch (opt) {
            case 'v': // -v 옵션이 주어진 경우
                verbose = 1;
                break;
            case 'q': // -q 옵션이 주어진 경우
                quiet = 1;
                break;
            case 'n': // -n 옵션이 주어진 경우
                if (optarg[0] == '-') { // 옵션의 값이 음수인 경우
                    num_minus = 1;
                    num_lines = -1 * atoi(optarg);
                } else // 옵션의 값이 양수인 경우
                    num_lines = atoi(optarg);
                break;
            default: // 그 외의 경우
                fprintf(stderr, "사용법: %s [옵션] [파일]\n", argv[0]);
                return 1;
        }
    }

    // 명령행 인자로 주어진 파일에 대해
    for (int i = optind; i < argc; i++) {
        file_name = argv[i]; // 파일 이름을 저장

        file = fopen(file_name, "r"); // 파일을 읽기 모드로 열음
        if (file == NULL) { // 파일을 열지 못한 경우 오류 메시지를 출력하고 다음 파일로 넘어감
            perror("fopen");
            continue;
        }

        // -v 옵션이 주어지거나 여러 개의 파일이 주어진 경우 파일 이름을 출력
        if ((verbose || argc-optind >= 2) && !quiet) {
            printf("==> %s <==\n", file_name);
        }

        char buffer[100]; // 한 줄을 저장할 문자열
        char lines[100][100]; // 모든 줄을 저장할 문자열 배열
        int lineCount = 0; // 줄의 수를 저장할 변수
        int endLine = 0; // 출력할 마지막 줄의 번호를 저장할 변수

        // 파일의 각 줄을 읽어서 저장
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            strcpy(lines[lineCount], buffer);
            lineCount++;
        }

        // 출력할 줄의 수를 결정
        if(num_lines < lineCount)
            endLine = num_lines;
        else
            endLine = lineCount;
        if(num_minus)
            endLine = lineCount - num_lines;

        // 결정된 줄까지 출력
        for (int j = 0; j < endLine; j++) {
            printf("%s", lines[j]);
        }

        // 파일 사이에 빈 줄을 출력
        if (!(i == argc-1) && !quiet){
            printf("\n");
        }

        fclose(file); // 파일을 닫음
    }

    return 0; // 프로그램이 성공적으로 종료
}

