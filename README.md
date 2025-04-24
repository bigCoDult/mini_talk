# mini_talk

**프로젝트 개요**
mini_talk는 Unix 시그널(SIGUSR1, SIGUSR2)을 이용해 프로세스 간 1바이트(8비트) 단위로 메시지를 전송하는 클라이언트-서버 방식의 교육용 프로젝트입니다.

**프로젝트 의의**
- 시그널 기반 통신으로 데이터를 비트 단위로 인코딩하고 전송하는 방법을 학습합니다.
- `signal`과 `kill` 시스템 호출을 사용해 동기화된 메시지 교환 로직을 구현합니다.
- 정적 변수를 활용해 이전 상태를 유지하고, 메시지 조합 및 출력 과정을 이해합니다.

## 라이센스
이 프로젝트는 **Beerware License (Revision 42)**를 따릅니다.

```
THE BEER-WARE LICENSE (Revision 42)
As long as you retain this notice you can do anything with this stuff.
If we meet some day, and you think this stuff is worth it, you can buy me a beer in return.
```
