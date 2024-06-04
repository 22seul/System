#include <stdio.h>  // 표준 입출력 함수를 사용하기 위한 헤더 파일

int main(int argc, char *argv[]) // 메인 함수 시작
{
    char c; // 문자를 저장할 변수
    FILE *fp1, *fp2; // 파일 포인터 두 개 선언

    // 명령행 인자의 수가 3이 아닌 경우 사용법을 출력하고 프로그램을 종료
    if (argc != 3) {
        fprintf(stderr, "사용법: %s 파일1 파일2\n", argv[0]);
        return 1;
    }

    // 첫 번째 파일을 읽기 모드로 열고 파일 포인터에 저장
    fp1 = fopen(argv[1], "r");
    // 파일을 열지 못한 경우 오류 메시지를 출력하고 프로그램을 종료
    if (fp1 == NULL) {
        fprintf(stderr, "파일 %s 열기 오류\n", argv[1]);
        return 2;
    }

    // 두 번째 파일을 쓰기 모드로 열고 파일 포인터에 저장
    fp2 = fopen(argv[2], "w");

    // 첫 번째 파일의 내용을 문자 단위로 읽어서 두 번째 파일에 씀
    while ((c = fgetc(fp1)) != EOF)
        fputc(c, fp2);

    // 파일을 닫음
    fclose(fp1);
    fclose(fp2);

    // 프로그램이 성공적으로 종료
    return 0;
}

