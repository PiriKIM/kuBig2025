class Parent:
    def __init__(self, value):
        self.value = "부모 클래스"
        self.value2 = value
        print("Parent Class __init__ 메소드 실행")
    
    def test(self):
        print("Parent Class의 test 메소드")

class Child(Parent):
    def __init__(self, value):
        super().__init__(value)
        print("Child Class __init__ 메소드 실행")

    def test(self):
        print("Child Class의 test 메소드")

    def child_test(self):
        print("Child Class의 메소드 실행")

def main():
    child = Child("123")
    child.test()
    print(child.value2)
    print(child.__dict__)
    print(child.__dir__())
    print(Child.mro())

if __name__ == "__main__":
    main()