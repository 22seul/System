#include <utime.h> // 파일의 접근 시간과 수정 시간을 변경하기 위한 헤더 파일
#include <stdio.h>  // 표준 입출력 함수를 위한 헤더 파일
#include <stdlib.h> // 일반 유틸리티 함수를 위한 헤더 파일
#include <unistd.h> // 유닉스 표준 함수를 위한 헤더 파일
#include <getopt.h> // 명령행 인자 파싱을 위한 헤더 파일
#include <sys/stat.h> // 파일 정보를 얻기 위한 헤더 파일
#include <time.h> // 시간 관련 함수를 위한 헤더 파일

int main(int argc, char *argv[]) { // 메인 함수 시작
    int opt; // 옵션을 저장할 변수
    int update_atime = 0; // 접근 시간을 업데이트할지 여부를 저장하는 변수
    int update_mtime = 0; // 수정 시간을 업데이트할지 여부를 저장하는 변수
    int create_file = 0; // 파일을 생성할지 여부를 저장하는 변수

    time_t change_time = time(NULL); // 변경할 시간을 저장하는 변수. 기본값은 현재 시간

    // getopt 함수를 사용하여 명령행 인자를 파싱
    while ((opt = getopt(argc, argv, "amct:d:")) != -1) {
        switch (opt) {
            case 'a': // 'a' 옵션일 경우 update_atime 변수를 1로 설정
                update_atime = 1;
                break;
            case 'm': // 'm' 옵션일 경우 update_mtime 변수를 1로 설정
                update_mtime = 1;
                break;
	    case 'c': // 'c' 옵션일 경우 create_file 변수를 1로 설정
		create_file = 1;
		break;
	    case 'd': // 'd' 옵션일 경우 change_time 변수를 옵션 값으로 설정
                {
                    struct tm tm_time = { 0 };
                    sscanf(optarg, "%d-%d-%d %d:%d:%d",
                        &tm_time.tm_year, &tm_time.tm_mon, &tm_time.tm_mday,
                        &tm_time.tm_hour, &tm_time.tm_min, &tm_time.tm_sec);
                    tm_time.tm_year -= 1900;
                    tm_time.tm_mon -= 1;
                    change_time = mktime(&tm_time);
                }
                break;
	    case 't': // 't' 옵션일 경우 change_time 변수를 옵션 값으로 설정
		{
		    struct tm tm_time = { 0 };
                    sscanf(optarg, "%2d%2d%2d%2d%2d.%2d",
           		&tm_time.tm_year, &tm_time.tm_mon, &tm_time.tm_mday,
             		&tm_time.tm_hour, &tm_time.tm_min, &tm_time.tm_sec);
		    tm_time.tm_year += 100;
                    tm_time.tm_mon -= 1;
		    tm_time.tm_isdst = -1;
                    change_time = mktime(&tm_time);
		    break;
		}
            default: // 알 수 없는 옵션일 경우 사용법을 출력하고 프로그램 종료
                fprintf(stderr, "사용법: touch [option] [file]\n");
                return 1;
        }
    }

    // 파일 이름이 제공되지 않았을 경우 에러 메시지를 출력하고 프로그램 종료
    if (optind >= argc) {
        fprintf(stderr, "파일 이름이 제공되지 않았습니다.\n");
        return 1;
    }

    // 파일 이름이 제공되었을 경우 각 파일에 대해 처리
    for (int i = optind; i < argc; i++) {
        struct stat file_info; // 파일 정보를 저장할 구조체
        struct utimbuf new_times; // 새로운 접근 시간과 수정 시간을 저장할 구조체

        // stat 함수를 사용하여 파일 정보를 얻음
        if (stat(argv[i], &file_info) == -1) {
            // 파일이 존재하지 않고 create_file 옵션이 설정된 경우 파일을 생성
            if(!create_file){
		FILE *file = fopen(argv[i], "w");
            	fclose(file);
	    }
            continue;
        }

        // update_atime 또는 update_mtime 옵션이 설정된 경우 해당 시간을 변경
        if (update_atime) {
            new_times.actime = change_time;
            new_times.modtime = file_info.st_mtime;
        } else if (update_mtime) {
            new_times.actime = file_info.st_atime;
            new_times.modtime = change_time;
        } else {
            new_times.actime = change_time;
            new_times.modtime = change_time;
        }

        // utime 함수를 사용하여 파일의 접근 시간과 수정 시간을 변경
        if (utime(argv[i], &new_times) != 0) {
            fprintf(stderr, "파일을 업데이트할 수 없습니다: %s\n", argv[i]);
        }
    }

    return 0; // 프로그램 종료
}

