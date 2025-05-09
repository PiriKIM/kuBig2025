def main():
    li = [i for i in range(101) if i % 2 == 0]
    print(li)
    li = [i ** 2 for i in range(101) if i % 2 == 0]
    print(li)
    li = [i + 1 for i in range(101) if i % 2 == 0]
    print(li)
    li = [(i + 1) ** 2 for i in range(101) if i % 2 == 0]
    print(li)

    li = [i ** 2  if i % 2 == 0 else i ** 3 for i in range(21)]
    print(li)

if __name__ == "__main__":
    main()