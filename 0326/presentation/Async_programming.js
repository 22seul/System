
function longWork(){
    //자바스크립트에서 기본으로 제공해주는 함수
    //setTimeout(함수, 시간) : 몇 초 동안 기다렸다가 함수를 실행할지
    //setTimeout 함수는 비동기로 실행되는 함수로 설계되어 있음
    setTimeout(() => {
        console.log('완료');
    }, 2000); 
}

console.log('Hello');
longWork();
console.log("World");