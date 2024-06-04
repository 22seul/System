#include <stdio.h>  // 표준 입출력 함수를 사용하기 위한 헤더 파일
#include <stdlib.h> // 일반 유틸리티 함수를 사용하기 위한 헤더 파일
#include <string.h> // 문자열 처리 함수를 사용하기 위한 헤더 파일
#include <unistd.h> // POSIX 운영체제 API를 사용하기 위한 헤더 파일

// 파일의 각 줄 앞에 줄 번호를 출력하는 함수
void printLineNum(FILE *file) {
    char line[BUFSIZ]; // 한 줄을 저장할 문자열
    int lineNumber = 1; // 줄 번호

    // 파일의 각 줄을 읽어옴
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%6d  %s", lineNumber, line); // 줄 번호와 줄의 내용을 출력
        lineNumber++; // 줄 번호 증가
    }
}

// 빈 줄이 아닌 줄 앞에 줄 번호를 출력하는 함수
void printLineExist(FILE *file) {
    char line[BUFSIZ]; // 한 줄을 저장할 문자열
    int lineNumber = 1; // 줄 번호

    // 파일의 각 줄을 읽어옴
    while (fgets(line, sizeof(line), file) != NULL) {
        // 줄이 빈 줄이면 줄 번호 없이 줄바꿈만 출력
        if (line[0] == '\n') {
            printf("\n");
        } else { // 줄이 빈 줄이 아니면 줄 번호와 줄의 내용을 출력
            printf("%6d  %s", lineNumber, line);
            lineNumber++; // 줄 번호 증가
        }
    }
}

// 파일의 각 줄 끝에 $ 기호를 출력하는 함수
void printLineDollar(FILE *file) {
    char line[BUFSIZ]; // 한 줄을 저장할 문자열

    // 파일의 각 줄을 읽어옴
    while (fgets(line, sizeof(line), file) != NULL) {
        size_t len = strlen(line); // 줄의 길이를 계산
        // 줄의 끝이 줄바꿈 문자이면 이를 $ 기호로 바꿔서 출력
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '$';
            printf("%s\n", line);
        } else if (len == 0) { // 줄의 길이가 0이면 $ 기호만 출력
            printf("$\n");
        } else { // 그 외의 경우 줄의 내용을 그대로 출력
            printf("%s\n", line);
        }
    }
}

// 파일에서 탭 문자를 ^I로 바꿔서 출력하는 함수
void printTabExpanded(FILE *file) {
    int c; // 문자를 저장할 변수

    // 파일의 각 문자를 읽어옴
    while ((c = getc(file)) != EOF) {
        // 문자가 탭 문자이면 ^I로 바꿔서 출력
        if (c == '\t') {
            putchar('^');
            putchar('I');
        } else { // 그 외의 경우 문자를 그대로 출력
            putchar(c);
        }
    }
}

// 파일에서 탭 문자를 ^I로, 줄바꿈 문자를 $로 바꿔서 출력하는 함수
void printShowAll(FILE *file) {
    int c; // 문자를 저장할 변수

    // 파일의 각 문자를 읽어옴
    while ((c = getc(file)) != EOF) {
        // 문자가 탭 문자이면 ^I로 바꿔서 출력
        if (c == '\t') {
            putchar('^');
            putchar('I');
        } else if (c == '\n') { // 문자가 줄바꿈 문자이면 $로 바꿔서 출력
            putchar('$');
            putchar(c);
        } else { // 그 외의 경우 문자를 그대로 출력
            putchar(c);
        }
    }
}

// 파일에서 연속된 빈 줄을 하나의 빈 줄로 바꿔서 출력하는 함수
void printSqueezedLines(FILE *file) {
    char line[BUFSIZ]; // 한 줄을 저장할 문자열
    int emptyLine = 0; // 빈 줄인지 아닌지를 저장할 변수

    // 파일의 각 줄을 읽어옴
    while (fgets(line, sizeof(line), file) != NULL) {
        // 줄이 빈 줄이면
        if (line[0] == '\n') {
            // 이전 줄이 빈 줄이 아니었다면 줄바꿈 문자를 출력
            if (emptyLine == 0) {
                printf("%s", line);
                emptyLine = 1; // 이번 줄이 빈 줄임을 기록
            }
        } else { // 줄이 빈 줄이 아니면 줄의 내용을 그대로 출력
            printf("%s", line);
            emptyLine = 0; // 이번 줄이 빈 줄이 아님을 기록
        }
    }
}

int main(int argc, char *argv[]) {
    int c; // 문자를 저장할 변수
    int line_number = 0; // -n 옵션을 저장할 변수
    int line_dollar = 0; // -E 옵션을 저장할 변수
    int tab_expanded = 0; // -T 옵션을 저장할 변수
    int line_exist = 0; // -b 옵션을 저장할 변수
    int show_all = 0; // -A 옵션을 저장할 변수
    int squeeze_line = 0; // -s 옵션을 저장할 변수
    int opt; // getopt 함수의 반환값을 저장할 변수

    // 명령행 인자를 처리
    while ((opt = getopt(argc, argv, "AbEnsT")) != -1) {
        switch (opt) {
            case 'b': // -b 옵션이 주어진 경우
                line_exist = 1;
                break;
            case 'n': // -n 옵션이 주어진 경우
                line_number = 1;
                break;
            case 'E': // -E 옵션이 주어진 경우
                line_dollar = 1;
                break;
            case 'T': // -T 옵션이 주어진 경우
                tab_expanded = 1;
                break;
            case 'A': // -A 옵션이 주어진 경우
                show_all = 1;
                break;
            case 's': // -s 옵션이 주어진 경우
                squeeze_line = 1;
                break;
            default: // 그 외의 경우
                fprintf(stderr, "사용법: %s [option] [file] ...\n", argv[0]);
                return 1;
        }
    }

    // 명령행 인자로 주어진 각 파일에 대해
    for (int i = optind; i < argc; i++) {
        FILE *file = fopen(argv[i], "r"); // 파일을 열음
        if (file == NULL) { // 파일을 열지 못한 경우 오류 메시지를 출력하고 다음 파일로 넘어감
            fprintf(stderr, "파일을 열 수 없습니다: %s\n", argv[i]);
            continue;
        }

        // 각 옵션에 따라 적절한 함수를 호출
        if (squeeze_line) {
            printSqueezedLines(file);
        } else if (show_all) {
            printShowAll(file);
        } else if (line_exist) {
            printLineExist(file);
        } else if (tab_expanded) {
            printTabExpanded(file);
        } else if (line_dollar) {
            printLineDollar(file);
        } else if (line_number) {
            printLineNum(file);
        } else { // 옵션이 주어지지 않은 경우 파일의 내용을 그대로 출력
            while ((c = getc(file)) != EOF)
                putc(c, stdout);
        }

        fclose(file); // 파일을 닫음
    }

    return 0;
}
