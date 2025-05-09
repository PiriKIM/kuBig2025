import random

def main():
    hanguls = list("최강박이손정적고구류오김송곽유왕")
    hanguls2 = list("가나다라마바사아자차카타파하동필화섭우석수길진호윤진우림영재형")
    with open("data/info.txt", "w") as f:
        for _ in range(1000):
            name = random.choice(hanguls) + "".join(random.choices(hanguls2, k=2))
            weight = random.randint(40, 120)
            height = random.randint(160, 210)
            f.write(f"{name}, {weight}, {height}\n")

if __name__ == "__main__":
    main()