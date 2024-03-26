# 0326 - 동기,비동기,블로킹,논블로킹 주제 발표
## PPT + 대본
> ![슬라이드1](https://github.com/22seul/System/assets/143988446/b6a32abe-1d04-4aa0-8077-6365802ccdbe)
---
> ![슬라이드2](https://github.com/22seul/System/assets/143988446/befc6753-dfde-4d51-bde0-4fcc07c394bb)
> * 먼저 동기, 비동기에 대해 설명하겠습니다.
동기, synchronous 단어를 보자면 syn은 그리스어로 함께, chrono는 시간이라는 뜻인데요. 즉 Synchronous는 작업 시간을 함께 맞춰서 실행한다 라는 뜻으로 해석됩니다. 작업을 맞춰 실행한다는 말은 요청한 작업에 대해 완료 여부를 따져 순차대로 처리하는 것을 말합니다.
> * 다음으로 비동기, Asynchronous는 synchronous앞에 A가 붙어 부정하는 형태인데요.그래서 동기와 반대로, 요청한 작업에 대해 완료 여부를 따지지 않고 자신의 다음 작업을 그대로 수행하게 됩니다.
---
> ![슬라이드3](https://github.com/22seul/System/assets/143988446/ced6ade6-4962-4a29-a441-f62bf8e1ceb9)
> * 이해를 돕기 위해 예시를 준비했는데요. 먼저 동기방식의 예로 A가 B에게 만원을 송금하는 경우를 들었습니다. 첫번째로 A의 계좌는 만원을 뺄 생각을 하고 있고, 다음으로 A의 계좌가 B의 계좌에 만원을 송금합니다. B의 계좌는 만원을 받았다는 걸 인지하고, A의 계좌에 만원을 받았다고 전송한 후 A, B 계좌 각각 증가와 차감이 동시에 발생하게 됩니다!! 아까 설명한 개념과 동시에 생각해 보자면 2번 3번과 같이 요청과 응답으로 작업 완료 여부를 따진 후, 4번과 같이 같은 일이 동시에 진행된 것을 볼 수 있습니다.
> * 다음으로 비동기 방식의 예로는 시험날의 학생과 선생님 경우를 들었는데요. 학생은 시험문제를 풀고 시험문제를 모두 푼 학생은 선생님께 시험지를 제출하겠죠? 그 후 선생님은 학생의 시험지를 채점한 뒤 채점된 시험지를 전달하고, 학생은 전달받은 시험지 채점 결과를 확인하게 됩니다.학생이 시험지를 제출한 뒤 결과가 나오기 전에 다음 과목 시험을 보거나 활동을 하겠죠? 이는 요청한 작업 완료 여부를 따지지 않고 자신의 다음 작업을 수행하는 것을 알 수 있고, 학생과 선생님은 시험지에 행하는 행위가 다르기 때문에 둘의 작업 처리 시간은 일치하지 않고, 일치하지 않아도 된다는 것을 알 수 있습니다.
---
> ![슬라이드4](https://github.com/22seul/System/assets/143988446/4f2306d5-cdf0-4118-9103-5afba2795a64)
> ![슬라이드5](https://github.com/22seul/System/assets/143988446/aeb5d3ea-50a3-42dc-9d6b-b86a3853de38)
> ![슬라이드6](https://github.com/22seul/System/assets/143988446/e3f60dda-fa7d-40bd-9a3f-425870e119f3)
> ![슬라이드7](https://github.com/22seul/System/assets/143988446/bad72ac3-a814-469d-a6b0-d9e12f249c55)
> ![슬라이드8](https://github.com/22seul/System/assets/143988446/3b99dfa7-d208-4073-b624-87379350c326)
> ![슬라이드9](https://github.com/22seul/System/assets/143988446/054a3f81-aa08-495b-9620-12268faddbae)
> ![슬라이드10](https://github.com/22seul/System/assets/143988446/9cb1d028-3d19-4b41-89ca-35c23e9b1f80)
> ![슬라이드11](https://github.com/22seul/System/assets/143988446/15f69030-c4a7-4188-95d2-3ba37501441b)
> ![슬라이드12](https://github.com/22seul/System/assets/143988446/22e215b5-3e33-4877-b1ea-d24e7d53bf7e)
> ![슬라이드13](https://github.com/22seul/System/assets/143988446/5bb4c0f1-bcc2-478c-8908-10474940cd9f)
