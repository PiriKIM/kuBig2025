# 섭씨->화씨 변환 프로그램 input -> casting -> 연산 -> 출력
def main():
    input_var = input("섭씨 온도를 입력하세요:")
    try:
        # float(input_var) 실수로 변환 시도 (정수도 포함됨)
        print(f'섭씨 {float(input_var):+.3f} >>> 화씨 {(float(input_var) * 9 / 5) + 32:+.3f}')
    except ValueError:
        print(input_var, "은 숫자가 아닙니다.", sep="")
        

if __name__ == "__main__":
    main()