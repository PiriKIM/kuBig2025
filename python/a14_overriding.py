class MyClass:
    def __init__(self, value):
        self.value = value

    def __eq__(self, other):
        return self.value == other.value

def main():
    a = MyClass(10)
    b = MyClass(10)
    if a == b:
        print("a와 b는 같다.")

    print("가나다" == "가나다")

if __name__ == "__main__":
    main()