#include <stdio.h>  // 표준 입출력 함수를 위한 헤더 파일
#include <unistd.h> // 유닉스 표준 함수를 위한 헤더 파일
#include <stdlib.h> // 일반 유틸리티 함수를 위한 헤더 파일
#include <string.h> // 문자열 처리 함수를 위한 헤더 파일

int main(int argc, char *argv[]) { // 메인 함수 시작
    int opt; // 옵션을 저장할 변수
    int verbose = 0; // 상세 출력 옵션을 위한 변수
    int quiet = 0; // 조용한 출력 옵션을 위한 변수
    int num_plus = 0; // '+' 옵션을 위한 변수

    int num_lines = 10; // 출력할 라인 수를 위한 변수. 기본값은 10

    // getopt 함수를 사용하여 명령행 인자를 파싱
    while ((opt = getopt(argc, argv, "vqn:")) != -1) {
        switch (opt) {
            case 'v': // 'v' 옵션일 경우 verbose 변수를 1로 설정
                verbose = 1;
                break;
            case 'q': // 'q' 옵션일 경우 quiet 변수를 1로 설정
                quiet = 1;
                break;
            case 'n': // 'n' 옵션일 경우 num_lines 변수를 옵션 값으로 설정
		if (optarg[0] == '+') // '+' 옵션이면 num_plus를 1로 설정
		    num_plus = 1;
                num_lines = atoi(optarg); // 옵션 값이 숫자일 경우 atoi 함수를 사용하여 변환
                break;
            default: // 알 수 없는 옵션일 경우 사용법을 출력하고 프로그램 종료
                fprintf(stderr, "사용법: %s [옵션] [파일]\n", argv[0]);
                return 1;
        }
    }

    // 파일 이름이 제공되지 않았을 경우 사용법을 출력하고 프로그램 종료
    if (optind >= argc) {
        fprintf(stderr, "사용법: %s [옵션] [파일]\n", argv[0]);
        return 1;
    }

    // 파일 이름이 제공되었을 경우 각 파일에 대해 처리
    for (int i = optind; i < argc; i++) {
        const char *file_name = argv[i]; // 파일 이름을 저장하는 변수

        // 파일을 읽기 모드로 열기. 실패할 경우 에러 메시지 출력하고 다음 파일로 넘어감
        FILE *file = fopen(file_name, "r");
        if (file == NULL) {
            perror("fopen");
            continue;
        }

        // verbose 옵션이 설정되었거나 여러 파일이 제공되었을 경우 파일 이름 출력
        if ((verbose || argc-optind >= 2) && !quiet) {
            printf("==> %s <==\n", file_name);
        }

	char buffer[100]; // 파일에서 읽은 라인을 저장할 버퍼
        char lines[100][100]; // 파일의 모든 라인을 저장할 배열
        int lineCount = 0; // 현재까지 읽은 라인 수
        int startLine = 0; // 출력할 첫 번째 라인의 인덱스
	int endLine = 0; // 출력할 마지막 라인의 인덱스

        // 파일의 끝에 도달할 때까지 라인을 읽어서 lines 배열에 저장
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            strcpy(lines[lineCount], buffer);
            lineCount++;
    	}

        // 출력할 첫 번째 라인의 인덱스 계산
        startLine = (lineCount > num_lines) ? (lineCount - num_lines) : 0;
	if(num_plus) // '+' 옵션이면 startLine을 num_lines-1로 설정
	    startLine = num_lines-1;
        endLine = lineCount; // 출력할 마지막 라인의 인덱스는 lineCount

        // startLine부터 endLine까지의 라인을 출력
        for (int j = startLine; j < endLine; j++) {
            printf("%s", lines[j]);
        }

        // 마지막 파일이 아니고 quiet 옵션이 아니면 줄바꿈 출력
        if (!(i == argc-1) && !quiet){
            printf("\n");
        }

        fclose(file); // 파일 닫기
    }

    return 0; // 프로그램 종료
}

