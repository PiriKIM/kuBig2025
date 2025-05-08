def afunc():
    a = 10
    b = 20
    return a, b

def main():
    # iterable 하고 list 와 차이가 없다.
    # tuple -> 불변 자료형!
    a = tuple()
    c = 123
    b = a, c
    print(type(b))

    # swap
    d = 10
    e = 20
    d, e = e, d
    print(d, e)
    print(afunc())

if __name__ == "__main__":
    main()