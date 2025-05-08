b = [1, 2, 3, 'four']

def main():
    a = 123
    print("로컬변수:", locals())
    print("바스변수:", vars())
    print("전역변수:", globals())

if __name__ == "__main__":
    main()