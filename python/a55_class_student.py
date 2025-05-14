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


def student_get_sum(student: Student):
    return student.korean + student.math + student.english + student.science


def student_get_average(student: Student, num: int):
    return student_get_sum(student) / num


def student_to_string(student: Student, num: int):
    return f'{student.name}\t{student_get_sum(student)}\t{student_get_average(student, num)}'


def main():
    hanguls = list("최강박이손정적고구류오김송곽유왕부오양")
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
        print(student_to_string(student, 4))


if __name__ == "__main__":
    main()