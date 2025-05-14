import random

class Student:
    def __init__(self, name, korean, math, english, science):
        # C++에서 *this => self
        # C++에서는 this-> 생략 가능
        # Python에서는 인스턴스 변수 사용 시 self를 반드시 붙여야한다
        self.name = name
        self.korean = korean
        self.math = math
        self.english = english
        self.science = science
        self.num = 4

    def student_get_sum(self):
        return self.korean + self.math + self.english + self.science

    def student_get_average(self):
        return self.student_get_sum() / self.num

    def student_to_string(self):
        return f'{self.name}\t{self.student_get_sum()}\t{self.student_get_average()}'
    
    def __str__(self):  # special method
        return f'{self.name}\t{self.student_get_sum()}\t{self.student_get_average()}'
    
    def __gt__(self, value):
        return self.student_get_sum() > value.student_get_sum()
    
    def __eq__(self, value):
        return self.student_get_sum() == value.student_get_sum()

    def __ne__(self, value):
        return self.student_get_sum() != value.student_get_sum()
    
    # __ge__, __le__, __lt__


def main():
    hanguls = list("최강박이손정적고구려유오김송곽유왕부오양")
    hanguls2 = list("가나다라마바사아자차카타파하동필화섭우석수길진호윤진우림영재형해준애순관식")
    students = [
        Student(
            random.choice(hanguls) + "".join(random.choices(hanguls2, k=2)),
            random.randint(65, 100),
            random.randint(65, 100),
            random.randint(65, 100),
            random.randint(65, 100),
        )
        for _ in range(50)
    ]
    print("이름\t총점\t평균")
    for student in students:
        print(student.student_to_string())


if __name__ == "__main__":
    main()