# kuBig2025
IoT 빅데이터 SW 개발자 과정 C언어 수업 저장소

---
## 2025-03-04
---
- ctrl + alt + T : 터미널 열기
- mkdir 폴더명 >> 폴더만들기
- cd ~ >> 홈 디렉토리로 이동
- cd .. >> 상위 폴더로
- ls >> 현재 위치에 폴더, 파일 리스트
- ls -al >> 숨김 파일까지 표시
- touch 파일명 >> 빈 파일 만들어줌
- nano 파일명 >> 파일 수정
- cat 파일명 >> 파일 내용 보기
- cc 파일명 >> 컴파일,
	 코드 변경할때마다 실행
- cc 파일명 -o 바이너리파일명
- sudo apt install gcc >> 컴파일 설치
- ./a.out(컴파일된 파일명) >> 실행
- ctrl + c : 강제 종료
- ps : 실행 중인 프로세스 리스트

### gitHub 연동
- git init >> .git 폴더 생성됨
- git remote add origin 깃허브주소
- https://github.com/PiriKIM/kuBig2025.git
- 깃허브 연동 위치 설정

- git fetch origin >> git 내용을 가져옴
- git pull >> git 내용을 끌어와 적용

- git checkout -b main origin/main

### VS code 설치
- sudo apt install ./code_1.97.2-1739406807_amd64.deb

## #리눅스 가상환경
- vmware
- wsl2 >> 최적화
- 우분투 22.04
- 텍스트 프로그램
- nano, vi, vsCode, copilot(무료)

### ##1일차 과제##
- vsCode 단축키
- vsCode 확장 기능
- README.md(markdown)
- markdown문법을 이용해 정리
- make 문법 알아두기





---
## 2025-03-05
---
### 리눅스 명령어(쉘 명령어)
- bash 쉘
- zsh (ohmygod)

### 전처리 지시자
- #include <> : 디폴트 폴더에서
- #include " " : 현재 위치에서

### void
- 함수 타입
- 함수 출력이 없을 때
- 함수 입력이 없을 때
- 임의의 인자 절달

** %f는 float에 사용, %lf는 double에 사용

** %d : 10진수, %o : 8진수, %x : 16진수

### 연산자
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

### 변수(Variable)와 상수(Constant)
- 변수 선언 후 값을 할당하지 않으면 임의의 값인 쓰레기 값이 할당됨.
- 전역 변수는 초기화 자동.

### ##2일차 과제##
- 프로그래머스 1 문제 풀기
- 리눅스 쉘 명령어 정리
- git 사용 방법



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




---
## 2025-03-12
---
#구조화
-분할컴파일
>>헤더 : 전역변수, 구조체, 함수선언+주석
>>오브젝트 : 전역변수, 함수정의, 소스 공개 여부(코드 안전)

#string.h
-strlen, strcpy, strcmp, strcat, ....
-C함수 길다. >> 헤더를 대표하는 문구가 함수 이름 앞에 붙음.

#문자열
-char * = "상수" >> 데이터 영역 (0x55xxxxxx)
-char[] = "blah.." >> 스택 영역, 힙 영영 (0x7xxxxxx)

#외부 라이브러리 사용 연습
-sql 라이브러리로 연습
-어떤 검색 >> 어떻게 사용?
-설치 >> 시스템 폴더 루트 (/usr/lib/include/...)
-*.h, *.o, *.so (정적링크), *.a (동적링크)
-동적링크 우선 (*.dll)

#데이터베이스
-관계형 데이터베이스
>>클라우드 : AWS, googleDB, gcp,...
>>로컬 : MySQL, sqlite
-소켓프로그램으로 운용
>>TCP, IP, Port, ID, PW,...

>>sudo apt install mysql-server
>>dpkg -l | grep mysql
>>sudo mysql_secure_installation
>>sudo systemctl status mysql
>>sudo mysql -u root -p
>>패스워드 입력하면 접속
>>use mysql; >> 사용할 DB 선택
>>alter user root@localhost identified with 'mysql_native_password' by '0000'; >> 패스워드 변경
>>create user myuser@'%' identified with mysql_native_password by '1017'; >> @ 뒤에 '%'을 붙이면 어느 IP에서든 접속 가능한 유저.
exit; >> mysql 종료.

#include <mysql.h>
>>sudo apt install libmysql++**
>>dpkg -L libmysqlclient-dev | grep mysql.h
>>cc -o bookSql bookSql.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
>>외부 라이브러리 사용할 때 컴파일 코드

#CMake
>>sudo apt install cmake
>>sudo apt-get install -y build-essential
>>makefile 생성 도구
>>부가기능 : 디버깅, deb배포 (CPACK), install,....





---
## 2025-03-13
---
#할당
-메모리에 저장 장소 확보

#정적할당
-프로그램 코드 시작 시 할당
-컴파일 시에 확정

#동적할당
-런타임(프로그램  동작 중간) 중에 할당
-힙 메모리 공간에 할당
-malloc() >> 바로 할당. 빠름.
-free() >> 할당 해제.
-calloc() >> 0으로 초기화 후 할당.
-realloc() >> 저장 공간 크기 조절.
-memset >> 메모리 초기화 함수.
-힙메모리 사용 후에 반드리 free를 해라!
-아레나 구조.





---
## 2025-03-13
---
# 표준 파일 입출력
- 0 : stdin >> 버퍼o
- 1 : stdout >> 버퍼o
- 2 : stderr >> 버퍼x

- 입력 버퍼 >> 큐(que) 버퍼 FIFO
- read() >> 버퍼데이터가 없으면 블로킹, 있으면 읽어서 리턴.
- get(), getc(), fgetc(), gets(), fgets(), scanf() -> read() 호출.
- fgetc(), fgets() 사용을 추천.

- 출력 버퍼
- fflush(stdout)으로 처리 가능.

- write() >> 버퍼가 가득 찼을 때 블로킹, 버퍼가 비워지기 전까지
- printf(), put(), putc(), fputc(), putchar() >> write() 호출.


# 볼링 프로그램 만들기
- 입력 함수
- 10개 프레임
- 점수판 만들기
- 사용자명, 점수, 날짜 (Table1)
- 사용자명, 날짜별 횟수 (Table2)
 >> DB Table에 저장
- 점수는 사용자 입력 or 랜덤



---
## 2025-03-18
---
#임베디드 프로그래밍
#ATmega128 - 8bit

#USB 포트 인식 설정(임시 수동)
lsusb
ls -l /dev/bus/usb/002/008
sudo chmod 666 /dev/bus/usb/002/008

#ATmega 정보
  idVendor           0x03eb Atmel Corp.
  idProduct          0x2104 AVR ISP mkII

#USB 포트 인식 설정(영구 자동)
sudo nano /etc/udev/rules.d/99-avrisp.rules
SUBSYSTEM=="usb", ATTR(idVendor)=="03eb", ATTR(idProduct)=="2104", MODE="0666"
sudo udevadm control --reload
sudo udevadm trigger

Future Technology Devices International, Ltd FT232 Serial (UART) IC

idVendor : 0x0403 Future Technology Devices International, Ltd
idProduct : 0x6001 FT232 Serial (UART) IC

Atmel Corp. AVR ISP mkII

idVendor : 0x03eb Atmel Corp.
idProduct : 0x2104 AVR ISP mkII

#UART 포트 인식 설정(임시 수동)
ls -l /dev/ttyUSB0
sudo chmod 666 /dev/ttyUSB0





---
## 2025-04-01
---
### 라즈베리파이 수업 시작

##### 임베디드 atmega128
- main 함수 하나 실행
- 복잡한 하드웨어 x
- 커다란 시스템 x
- 장난감, 게임기, 센서제어 등등

##### 그러므로 OS 필요
- 여러개의 프로세스 가능
- 복잡한 하드웨어 가능
- 핸드폰, 로못, 키오스크 등등

##### 라즈베리파이(임베디드 + OS)
- 임베디드와 OS의 중간 단계
- 커널링 - OS의 깊은 설정
>> 한정된 자원을 최적화
- RTOS - 임베디드에 꼭 필요한것만

### 라즈베리 파이 이미저 다운로드
- 설치 후 실행
- 기기 - 라즈베리 파이 4
- 운영체제 - 라즈베리파이 OS 64bit
- 저장소 - SD카드
- 커스마이징
- 호스트네임, 사용자이름, 비밀번호 설정
- 무선랜 turtle, turtlebot3
- 국가 - KR, 시간대 - asia/seoul, 키보드 - us
- 서비스 - SSH 사용 체크 - 비밀번호 인증
- 옵션 - 밑에꺼 두개 체크

### 와이파이 turtle - turtlebot3
- 192.168.0.1 접속
- admin - admin 로그인
- 관리도구-고급설정-네트워크관리-내부네트워크설정
- vmware 터미널에서 ifconfig 실행
- inet 주소 확인 192.168.232.128
- vmware-player-manage-setting-network adapter
>> bridged >> configure adapters
>> 내컴퓨터가 쓰는 와이파이만 체크
- inet 주소 확인 192.168.0.xx 로 바뀜
- vscode실행-open a remote window-ssh눌러서 설치
- 터미널에서 ssh piri@192.168.0.61
- 내 컴퓨터가 할당받은 ip말고
- vmware가 할당받은 ip 말고
- 라즈베리파이가 할당받은 ip!!!!!!!

### 라즈베리파이 설정
- sudo raspi-config
- 5.localization - locale - en_US.UTF-8 선택
- 3.interface - VNC, SPI, I2C enable 설정

### vnc viewer 다운로드 설치
- vnc Viewer에 라즈베리파이 ip 넣고 접속

### 라즈베리파이에 원격 접속
- vscode실행 - open a remote window - connected to HOST - add new SSH host
- piri@192.168.0.54 - /home/piri/.ssh/config 클릭 - connect 클릭 - 새창 뜨면 비밀번호 입력

### 라즈베리파이 로컬에 git 연결
- git clone 으로 가져온거 push 안될때 확인
- git remote -v 로 본인의 레포지토리로 지정 확인
- git config --global user.name "사용자 이름"
- git config --global user.email "이메일 주소"

### WiringPi 라이브러리 git에서 다운로드 그리고 컴파일 방법
- git clone https://github.com/WiringPi/WiringPi.git
- cd WiringPi >> sudo ./build
- cc -o hello helloRaspberry.c -lwiringPi




---
2025-04-02
---
### OS 서비스 - 복합적인 프로세스
- 다중터미널 -> 한계가 있음
- 데몬 -> ./limit& : 실행 파일 뒤에 & 붙여서 실행. 터미널 종속적.
- nohup ./limit& : 터미널 비종속적. ps, kill 명령어로 종료해야함.
- tmux -> 설치 유틸리티. 프롬프트 창에서의 다중프로세스 출력 못하는 문제 해결 가능

** nohup ./infinit > output.log 2>&1 & 잘 안됨....;;;

### 시스템데몬 (systemd)
- *.service 파일 생성
- touch mydaemon.sh -> shell 파일 생성
- code mydaemon.sh  -> shell 파일 vscode에 열기
- sudo chmod +x mydaemon.sh -> shell 파일에 실행 권한 추가
- ls -al -> 모든 파일 및 폴더의 권한 조회
- sudo ./mydaemon.sh -> 쓰기 권한이 없어서 sudo로 실행
- cat /var/log/mydaemon/system_info.log -> 실행 결과 확인
- cd /etc/systemd/system/ -> 시스템데몬 폴더 이동
- sudo touch mydaemon.service
- code mydaemon.service
- sudo nano mydaemon.service
- sudo systemctl start mydaemon.service
- sudo systemctl stop mydaemon.service
- sudo systemctl enable mydaemon.service
- sudo systemctl disable mydaemon.service
- sudo systemctl status mydaemon.service
- sudo systemctl daemon-reload

### i2cdetect -y 1 -> i2c 연결 주소 확인



---
2025-04-03
---
### 커널 실행 전 칩 확인
- cd /sys/class/gpio/
- echo 23 > export
- echo 535 > export
- echo 535 > unexport

### LED 커널 모듈 실행
- sudo insmod led_module.ko : 실행
- sudo rmmod led_module : 종료
- dmesg : printk 메세지 확인
- sudo dmesg -C : dmesg Clear

### 디바이스 드라이버 실행
- sudo insmod driver_exam.ko
- dmesg
- sudo mknod /dev/driver_exam c 220 0
>> 파일위치, 장치타입, 주번호, 부번호
- ls /dev/driver_exam -al
- sudo chmod 666 /dev/driver_exam
- ls /dev/ | grep driver : "driver"가 들어간거만 검색



---
2025-04-04
---




