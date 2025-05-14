import pickle
import random
from a58_method import Student

def main():
    hanguls = list("최강박이손정적고구려유오김송곽유왕부오양")
    hanguls2 = list("가나다라마바사아자차카타파하동필화섭우석수길진호윤진우림영재형해준애순관식")
    with open("data/students_binary.pickle", "wb") as f:
        for _ in range(100):
            data = Student(
                random.choice(hanguls) + "".join(random.choices(hanguls2, k=2)),
                random.randint(60, 100),
                random.randint(60, 100),
                random.randint(60, 100),
                random.randint(60, 100)
            )
            pickle.dump(data, f)
            

if __name__ == "__main__":
    main()