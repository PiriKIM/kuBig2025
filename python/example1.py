# 파이썬으로 구구단 출력하기
def main():
    for i in range(2,10):
        print('----', i, '단 ----')
        for j in range(2,10):
            print(i, 'x', j, '=', i * j)

    dan = '23456789'
    for i in dan:
        print('----', i, 'dan ----')
        for j in dan:
            print(i, '*', j, '=', int(i) * int(j))


if __name__ == "__main__":
    main()