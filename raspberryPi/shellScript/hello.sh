#!/bin/bash

# 이 스크립트는 헬로우 월드를 출력합니다.
name="KIM dogn pil"
export age=25

echo "Hello, World!, $name"
echo "date : " `date`   # 이 라인은 date 유틸리티를 실행합니다.


text="hello, world!"
echo ${text:0:5}    # 문자열 자르기(문자열:시작점:갯수)
echo ${text:7}      # # 문자열 자르기(시작점에서 끝까지)

text="I like cats"
echo ${text/cats/dogs}  # 문자열 치환

text="I like cats, I really love cats"
echo ${text/cats/dogs}  # 여러개 있을 때는 처음 하나만
echo ${text//cats/dogs} # 여러개 모두를 다 치환 가능
echo ${#text}           # 문자열 길이 출력


# 중요! unset env 환경 변수 초기화!


# read
echo "Enter Your Name: "
read name
read -s -p "Enter Your Password: " password
echo -e "\nUser Name: $name"
echo "Password: $password"
export name=$name
./envTest

# 화면출력 echo, printf
echo -n "이어지는"  # 개행 없음
echo "문장"
echo -e "엔터가 들어가는\n 문장"    # escape 문자 작동 옵션
printf "Name: %s, Age: %d\n" "KIM DP" 32

# 중요!! argument 받기 $1 $2
# source hello.sh KIM DONGPIL
echo "First Argument: $1"
echo "Second Argument: $2"
echo "Argument Count: $#"
echo "All Argument: $@"
echo "All Argument: $*"

# 제어문 if then fi(endif)
read -p "Enter Your Age: " age
if [ $age -lt 18 ]; then
    echo "성인이 아닙니다."
elif [ $age -gt 70 ]; then
    echo "노인입니다."
else
    echo "성인입니다."
fi

# 연산자 - 숫자
# 같다: eq, 같지 않다: ne
# 크다: gt, 작다: lt
# 크같: ge, 작같: le

# 연산자 - 문자
# 같다: =, 같지않다: !=
# 길이가 0 len(문자열) : z
# 길이가 0 이 아닌 len(문자열) : n

read -p "입력값을 넣으세요: " input
if [ ! -z "$input" ]; then
    echo "입력값이 있습니다."
else
    echo "입력값이 없습니다."
fi

# 논리 연산 똑같음 && || !


# switch - case -> case ~ esac

read -p "과일 입력: " fruit
case $fruit in
    "사과"|"딸기") echo "빨간 과일" ;;
    "바나나"|"망고") echo "노란 과일" ;;
    *) echo "알 수 없음" ;;     # *: default
esac