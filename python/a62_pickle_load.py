import pickle
from a58_method import Student

def main():
    students: list[Student] = []

    with open("data/students_binary.pickle", "rb") as f:
        try:
            while data := pickle.load(f):
                students.append(data)
        except EOFError:
            pass

    print("이름\t총점\t평균")
    for student in students:
        print(student)

    print(students[0], students[1])
    print(students[0] > students[1])
    print(students[0] == students[1])
    print(students[0] != students[1])
 

if __name__ == "__main__":
    main()