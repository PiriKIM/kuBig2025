def main():
    # f = open("data/text.txt", "w")
    # print(f.fileno())   # file descriptor
    # f.write("hello, Python Programming, hi everyone!!")
    # # C에서는 표준 IO 함수 fputs, fprintf, f....
    # f.close()

    # with문이 끝날 때 자동으로 close 됨
    with open("data/text.txt", "a", encoding="utf-8") as f:
        f.write("\nhello Python!! add input.")

if __name__ == "__main__":
    main()