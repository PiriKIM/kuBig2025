# kuBig2025
IoT 빅데이터 SW 개발자 과정 C언어 수업 저장소

---
## 2025-03-04
---
ctrl + alt + T : 터미널 열기
mkdir 폴더명 >> 폴더만들기
cd ~ >> 홈 디렉토리로 이동
cd .. >> 상위 폴더로
ls >> 현재 위치에 폴더, 파일 리스트
ls -al >> 숨김 파일까지 표시
touch 파일명 >> 빈 파일 만들어줌
nano 파일명 >> 파일 수정
cat 파일명 >> 파일 내용 보기
cc 파일명 >> 컴파일,
	 코드 변경할때마다 실행
cc 파일명 -o 바이너리파일명
sudo apt install gcc >> 컴파일 설치
./a.out(컴파일된 파일명) >> 실행
ctrl + c : 강제 종료
ps : 실행 중인 프로세스 리스트

<gitHub 연동>
git init >> .git 폴더 생성됨
git remote add origin 깃허브주소
https://github.com/PiriKIM/kuBig2025.git
깃허브 연동 위치 설정

git fetch origin >> git 내용을 가져옴
git pull >> git 내용을 끌어와 적용

git checkout -b main origin/main

<VS code 설치>
sudo apt install ./code_1.97.2-1739406807_amd64.deb

#리눅스 가상환경
- vmware
- wsl2 >> 최적화
#우분투 22.04
#텍스트 프로그램
- nano, vi, vsCode, copilot(무료)

##1일차 과제##
** vsCode 단축키
** vsCode 확장 기능
** README.md(markdown)
** markdown문법을 이용해 정리
** make 문법 알아두기





---
## 2025-03-05
---
#리눅스 명령어(쉘 명령어)
- bash 쉘
- zsh (ohmygod)

#전처리 지시자
- #include <> : 디폴트 폴더에서
- #include " " : 현재 위치에서

#void
- 함수 타입
- 함수 출력이 없을 때
- 함수 입력이 없을 때
- 임의의 인자 절달

** %f는 float에 사용, %lf는 double에 사용

** %d : 10진수, %o : 8진수, %x : 16진수

#연산자
- 폰 노이만 머신
 >> 폰 노이만 구조
 >> 하버드 구조
- 산술연산자 : + - * / %
- 대입연산자 : =
- 복합연산자 : +=, -=, *= ...
- 증감연산자 : ++, --
 >> 전위 : ++a, 후위 : a++
- 관계연산자 : <, >, <=, >=, ==, !=
- 논리연산자 : &&, ||, !(NOT)
- 형변환연산자 : (newType)변수 >> 형변환
- sizeof 연산자 >> 결과 (%ld)
- 비트연산자 : ^, &, ~, |, <<, >>
    -> XOR, AND, NOT, OR, 이동연산 좌우

#변수(Variable)와 상수(Constant)
- 변수 선언 후 값을 할당하지 않으면 임의의 값인 쓰레기 값이 할당됨.
- 전역 변수는 초기화 자동.

##2일차 과제##
** 프로그래머스 1 문제 풀기
** 리눅스 쉘 명령어 정리
** git 사용 방법



---
## 2025-03-06
---
#if문, for문, while문, switch문, goto문
- 흐름 제어, 반복, 체크, 분기
- if 조건문 -> int 0 : false, 그 외 1,2,-1,-2,... : true

#식별자 쓸 때
- C, C++은 Camel Case 사용. ex) leafYear
- 상수는 Upper Case 사용. ex) #define YEAR
- 내장 타입은 소문자 ex) int, float...
- 사용자 타입, 구조체 같은거 ex) MyData

#atoi : string을 int로 바꾸는 함수




---
## 2025-03-07
---
- 실행 흐름 -> 시간
- 멀티 스레드 -> 시분할
- if / else if / else -> 순서대로 조건문 확인. 조건문에 부합하면 바로 if문 탈출. 그러므로 조건문들의 순서 중요.
- switch / case / default -> case가 여러 개면 break; 필수
- for ( 초기화 ; 조건문 ; 증감 )
- n의 보수 : 마이너스 기호없이 음수를 나타내기 위해
n 자리 수의 서로 대치되는 양수와 음수를 더하면 0이 된다.

#함수 (Function)
- 반복적인 코드를 묶어서 실행
- 정적 지역 변수 static
  >> 해당 함수 안에서만 전역 변수처럼




---
## 2025-03-10
---
#정렬
- 선택 정렬(selection aligment)
>>배열 안에서 첫 인덱스를 기준으로 나머지와 비교하여 조건에 따라 배열 값들을 Swap하여 오름차순, 내림차순 등 일정 조건으로 정렬하는 것.
- 버블정렬
>>
- qSort (Quick Sort)
>>

#포인터
- 주소값을 저장하는 변수
- *(포인터변수)
- 다중포인터 이중포인터는 포인터를 가리킨다.

#이중포인터
- 보통 단일포인터의 배열을 가리킬때 사용.
- **pp >> {*p, *p+1, *p+2, ...}

#함수포인터

#void 포인터
- 포괄형 generic pointer

#포인터의 사용
- 호출하는 쪽의 변수를 바꿀 때 (호출당하는 함수에서) ex.SWAP
- 배열을 넘길 때 (배열의 크기도 필수)
- 구조체의 자료를 넘길 때
- 사용자 정의 연산을 넘길 때 (함수 포인터)
- 임의의 자료를 넘길 때 (void 포인터)



---
## 2025-03-11
---
#분할 컴파일
->main.c->main.o->main(실행파일)
ex) main.c & serial.c
 >> cc -c main.c    (main.o생성)
 >> cc -c serial.c   (serial.o생성)
 >> cc -o serial main.o serial.o    (serial 이라는 이름의 실행파일 생성)
 >> ./serial     (serial 실행)

#구조체(struct)
- 사용자 정의 타입 (기본 타입 조합)
- 데이터의 형태

1.
struct 구조체타입명 { };
struct 구조체타입명 변수명;

2.
typedef struct { } 구조체타입명;
구조체타입명 변수명;

#메모리 영역
-코드영역
>>실행코드, 상수
-데이터영역
>>전역변수, 정적지역변수
>>가변, 불변으로 나뉨
-힙 영역
>>동적변수
-스택 영역
>>지역변수, 매개변수










