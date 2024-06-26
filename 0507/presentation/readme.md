# 0507 - fsck, badblocks 주제 발표
## PPT + 대본
> ![슬라이드1](https://github.com/22seul/System/assets/143988446/a14f4b5d-eb76-4153-a6c5-f725c090bf76)
---
> ![슬라이드2](https://github.com/22seul/System/assets/143988446/c98fa9b9-be30-42a5-9d82-d32dc12c8e61)
> * 먼저 리눅스의 디스크관리 명령어로는 다음과 같이 
파일 시스템을 검사하는 fsck, 확장 파일 시스템을 검사하는 e2fsck, 
배드블록 검색하는 badblocks, 파일 시스템 정보를 출력하는 dumpe3fs가 있습니다.
오늘은 fsck, badblocks에 대해 좀 더 자세히 알아보겠습니다.
---
> ![슬라이드3](https://github.com/22seul/System/assets/143988446/47df6b7e-bde4-4b81-bf6e-149a258ec227)
> * 먼저 fsck는 file system consistency check의 약자로 파일 시스템 일관성 검사기입니다. 기능의 첫번째로는 파일 시스템 점검인데요. fsck는 파일 시스템의 무결성과 일관성을 검사하고 필요한 경우 복구 작업을 수행합니다. 
두번째로는 문제 진단으로, 파일 시스템 내 오류를 발견하고 원인을 파악합니다.
세번째로는 자동수정으로, 파일 시스템의 문제를 감지하면 자동으로 문제를 해결할 수 있습니다
---
> ![슬라이드4](https://github.com/22seul/System/assets/143988446/a3286da2-d586-4186-b349-6c6d4bd24c6d)
> * 다음으로는 형식인데요. 다음과 같이 fsck, 옵션, filesystem과 같은 일반 형식을 가집니다. 옵션으로는 모든 파일 시스템 점검, 루트 파일 시스템 제외, 버전정보 생략, 강제 검사, 모든 질문 yes 대답, 자동 복구 등이 있습니다.
---
> ![슬라이드5](https://github.com/22seul/System/assets/143988446/4a4f548a-8181-40a3-8b57-46e2989cbc9e)
> * fsck를 사용한 파일 시스템 복구 과정은 다음과 같습니다.
첫번째로 파일 시스템을 점검인데요. Fsck 명령어를 실행하여 시스템의 무결성을 확인합니다. 이 명령어는 앞서 말했던 일반 형식을 사용합니다.
다음으로는 장치 마운트 해제입니다. 마운트 된 장치에서 fsck를 실행하면, 파일 시스템이 손상될 수 있으므로, 먼저 대상을 마운트 해제해야 합니다.
마운트 해제까지 하였다면 이제 fsck 명령어를 실행하여 파일 시스템을 복구합니다.
이제 마지막으로 파일 시스템이 복구되면 파티션을 다시 마운트 합니다.
---
> ![슬라이드6](https://github.com/22seul/System/assets/143988446/7826cac9-c787-4cc9-ba01-a21db9b597a0)
> * 다음으로는 badblocks 명령어에 대해 알아보겠습니다.
badblocks 기능의 첫번째로는 badblock 검사로, 하드디스크에 badblock, 즉 나쁜 섹터가 있는지 검사합니다.
두번째로는 데이터 보호로, badblock를 찾아 데이터 손상을 방지합니다.
세번째로는 비파괴적 검사로, 기본적으로 비파괴적 읽기 전용 모드에서 실행되어 데이터를 안전하게 유지합니다.
---
> ![슬라이드7](https://github.com/22seul/System/assets/143988446/50f9c83b-f7d0-484e-b932-ac658c39cf0f)
> * 다음으로는 형식인데요. Fsck와 동일하게 badblocks 옵션, 장치명과 같은 형식을 가지고, 옵션으로는, 지정 파일에 배드블록 리스트 기록, 읽기/쓰기 모드에서 검사, 비파괴적 읽기 쓰기 모드 등이 있습니다.
---
> ![슬라이드8](https://github.com/22seul/System/assets/143988446/94786f46-f2eb-4858-b5f9-15befc57f1d6)
> * badblocks를 사용한 하드 디스크 진단 과정은 다음과 같습니다.
첫번째로 fdisk명령으로 문제가 있는 디스크를 찾습니다
다음으로 badblocks명령어를 사용해 일반 형식 명령으로 실행합니다
마지막으로 명령어가 실행되면 검사 결과가 출력되는데요. 출력에서 Pass completed, X bad blocks found (Y/Z/W errors) 형식의 메시지를 확인할 수 있는데,
이 메시지에서 X는 발견된 badblock의 수, Y는 읽기 에러의 수, Z는 쓰기 에러의 수, W는 비교 에러의 수를 나타냅니다.
---
> ![슬라이드9](https://github.com/22seul/System/assets/143988446/120e96a2-5575-47ac-b1c2-564a17983aa9)
> * 이제 이러한 명령어들을 언제 실행하면 좋을지 한 번 보겠습니다.
첫번째로는 정기적인 유지보수로, 파일 시스템의 무결성을 유지하고 데이터 손상을 방지하기 위해, 이러한 명령어를 정기적으로 실행하는 것이 좋습니다.
두번째로는 시스템 부팅 실패로, 시스템이 제대로 부팅되지 않거나 파일 시스템에 문제가 있는 것 같은 경우, fsck를 사용하여 파일 시스템 복구가 가능합니다.
세번째로는 디스크에서 오류가 발생하거나, 디스크의 성능이 저하된 것 같은 경우, badblocks를 사용하여 디스크를 검사할 수 있습니다.
마지막으로는 새로운 하드웨어를 설치한 후, badblocks를 사용하여 하드 드라이브를 검사하는 것이 좋습니다. 이렇게 하면 하드 드라이브에 문제가 있는지 미리 확인할 수 있습니다.
---
> ![슬라이드10](https://github.com/22seul/System/assets/143988446/6c1978c4-d051-42ac-b47f-45e1e2831572)
> * 다음으로는 주의사항입니다. 제가 발표를 준비하면서 실습을 하다가 노트북을 다시 켜서 wsl을 실행시키려고 하였을 때 저런 문구가 떴는데요… 이러한 문제가 발생하지 않기 위해서는 첫번째로 작업 전 반드시 중요한 데이터들을 백업하고, 두번째 파일 시스템 또는 디스크 검사 시 시스템을 종료하고, 마지막으로 복잡한 문제는 전문가의 도움을 받도록 하는 것이 좋습니다.
---
> ![슬라이드11](https://github.com/22seul/System/assets/143988446/baa62005-fa10-4aba-8108-483c203be8e1)
> * 생략
---
> ![슬라이드12](https://github.com/22seul/System/assets/143988446/b12e185f-4d5d-49d2-9ca9-0009d25f7f58)
> * 이제 실습을 해볼텐데 먼저 fsck 명령어 실습을 해보겠습니다.
sudo fsck /dev/sdc 와 같이 옵션 없이 sdc 파일 시스템을 검사해보면
순서대로 fsck 버전, e2fsck 버전
다음으로는 sdc가 마운트되어 있다는 것을 알수있습니다.
다음으로는 옵션 -TV, 자세한 출력 및 버전 출력 방지하는 옵션을 추가하여 실행해보겠습니다.
sudo fsck -TV /dev/sdc를 입력하면 아까와 달리 첫번째 줄에 fsck의 버전이 안 나오고 ‘fsck.ext4’명령어가 드라이브에 대해 실행되고 있음을 나타냅니다. 다른 줄은 앞에서 한 실습과 동일 합니다.
---
> ![슬라이드13](https://github.com/22seul/System/assets/143988446/9c393eaf-7e33-4018-a621-1e29eba1a4ab)
> * 다음으로 badblocks 명령어 실습을 해보겠습니다.
sudo badblocks /dev/sdb 를 입력하면 아무런 출력이 나오지 않아
sudo badblocks -v /dev/sdb 이와 같이 자세히 출력하는 -v 옵션을 추가하여 실행해주면 
첫째줄에서 블록 검사의 범위를 알 수 있고
제가 badblocks는 기본적으로 읽기 모드에서 실행된다고 말했는데 두번째 줄에서 읽기 전용 테스트를 수행하고 있는 것을 볼 수 있습니다. 그리고 done은 다 검사하면 뜨고,
마지막 줄은 앞서 설명했듯이 배드블록 수가 0이고, 읽기, 쓰기, 비교 에러의 수도 0으로 배드블록이 발견되지 않았으며, 오류도 0개로 보고되었습니다
---
> ![슬라이드14](https://github.com/22seul/System/assets/143988446/f85c0314-d5e6-4988-992b-ee26d20b93d9)

