
function longWork() { //시간이 오래걸리는 작업 함수 만들기
    const now = new Date(); //현재 날짜 가져오기
    const milliseconds = now.getTime(); // 현재 시간을 밀리초로 가져오기
    const afterTwoSeconds = milliseconds+2*1000;
    //코드 실행 시간에서 2초 더한 시간

    //현재 루프가 돌아가는 시간
    //2초동안 실행되는 반복문
    while(new Date().getTime() < afterTwoSeconds){ 

    }

    //2초 동안 작업 끝나고 완료 출력
    console.log('완료'); //콘솔창 출력
}

console.log('Hello');
longWork();
console.log("World");
