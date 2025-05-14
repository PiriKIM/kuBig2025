from dataclasses import dataclass

@dataclass
class Student:
    name: str
    korean: int
    math: int
    english: int
    science: int

    def get_sum(self):
        return self.korean + self.math + self.english + self.science


def main():
    st1 = Student("aaa", 23, 34, 45, 56)
    st2 = Student("bbb", 32, 43, 54, 65)
    print(st1.__dict__)
    print(st2.__dict__)
    print(st1.get_sum(), st2.get_sum())

if __name__ == "__main__":
    main()