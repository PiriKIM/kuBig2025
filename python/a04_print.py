def main():
    print(1234567)
    print(1_234_567)    # 1'234'567
    print("kim dong pil")
    print(3.141592)

    print("this is", "python", "class!!")
    print(10, 20, 30, "hi", "bye")
    print()     # 줄 바꿈

    # end의 default가 "\n"이어서 print할 때마다 자동 줄바꿈
    # sep의 default가 " "이어서 , 로 이어붙이면 자동으로 한칸 띄어씀
    print("this is", "python", "class!!", sep="", end="")
    print("this is", "python", "class!!", sep="-")


if __name__ == "__main__":
    main()