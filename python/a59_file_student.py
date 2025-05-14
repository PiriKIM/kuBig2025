# student 58번의 학생 총점 평균이 실행할 때마다 랜덤
# -> 고정적인 데이터로 100명의 학생을 처리하는 프로그램을 만드세요.
# 1. 100명의 데이터 생성 후 저장하는 프로그램
# 2. students.txt를 읽어서 클래스를 생성하고 처리하는 프로그램
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


def main():
    students = []
    hanguls = list("최강박이손정적고구려유오김송곽유왕부오양")
    hanguls2 = list("가나다라마바사아자차카타파하동필화섭우석수길진호윤진우림영재형해준애순관식")
    with open("data/students.txt", "w") as f:
        for _ in range(100):
            name = random.choice(hanguls) + "".join(random.choices(hanguls2, k=2))
            korean = random.randint(60, 100)
            math = random.randint(60, 100)
            english = random.randint(60, 100)
            science = random.randint(60, 100)
            f.write(f"{name},{korean},{math},{english},{science}\n")

    with open("data/students.txt", "r", encoding="utf-8") as f:
        while line := f.readline():
            line = line.strip("\n")
            info = line.split(",")
            students.append(Student(info[0], int(info[1]), int(info[2]), int(info[3]), int(info[4])))
    
    print("이름\t총점\t평균")
    for student in students:
        print(student.student_to_string())

if __name__ == "__main__":
    main()