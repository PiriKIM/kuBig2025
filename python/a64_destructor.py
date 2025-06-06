class Test:
    def __init__(self, name):
        self.name = name
        print(f"{self.name} - 생성 되었습니다.")

    def __del__(self):
        print(f"{self.name} - 소멸 되었습니다.")

def main():
    a = Test("A")
    b = Test("B")
    c = Test("C")
    print(a, b, c)
    li = [a, b, c]
    del li[2]
    del c   # GC 작동하지 않고 수동으로 소멸
    # 컨테이너 안의 원소를 제거할때는 컨테이너 포함을 제거하고, 원소를 제거한다!
    # 원소만 제거하면 컨테이너 안에는 남아 있다.
    # 컨테이너 안을 제거하면 원소는 남아 있다.
    print(li)
    # print(c)

if __name__ == "__main__":
    main()