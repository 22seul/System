#include <stdio.h>  // 표준 입출력 함수를 사용하기 위한 헤더 파일

// 파일의 각 줄 앞에 줄 번호를 출력하는 함수
void printNumberedLines(FILE *file) {
    char line[BUFSIZ]; // 한 줄을 저장할 문자열
    int lineNumber = 1; // 줄 번호

    // 파일의 각 줄을 읽어옴
    while (fgets(line, sizeof(line), file) != NULL) {
        // 줄이 빈 줄이면 줄바꿈만 출력
        if (line[0] == '\n') {
            printf("\n");
        } else { // 줄이 빈 줄이 아니면 줄 번호와 줄의 내용을 출력
            printf("%6d  %s", lineNumber, line);
            lineNumber++; // 줄 번호 증가
        }
    }
}

int main(int argc, char *argv[]) { // 메인 함수 시작
    // 명령행 인자의 수가 2가 아닌 경우 사용법을 출력하고 프로그램을 종료
    if (argc != 2) {
        printf("사용법: %s [파일 경로]\n", argv[0]);
        return 1;
    }

    char *filePath = argv[1]; // 명령행 인자로 주어진 파일 경로를 저장

    FILE *file = fopen(filePath, "r"); // 파일을 읽기 모드로 열음
    // 파일을 열지 못한 경우 오류 메시지를 출력하고 프로그램을 종료
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    printNumberedLines(file); // 파일의 각 줄 앞에 줄 번호를 출력하는 함수를 호출

    fclose(file); // 파일을 닫음

    return 0; // 프로그램이 성공적으로 종료
}

