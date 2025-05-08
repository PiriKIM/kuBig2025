def main():
    string = 'abc'
    string2 = 'this is format test: {}'.format(10)
    print(string)
    print(string2)
    string3 = 'this is format test: {2} {1} {0}'.format(10, 20, 30)
    print(string3)

    string3 = 'this is format test: {2:d} {1:5d} {0:05d}'.format(10, 20, 30)
    print(string3)

    string3 = 'this is format test: {2:+d} {1:+5d} {0:+05d}'.format(10, 20, 30)
    print(string3)

    string3 = 'this is format test: {2:+f} {1:+5.2f} {0:+05.1f}'.format(-10.123, 20.45, 30)
    print(string3)

    # .format 보다 f 스트링을 사용하는 것을 권장
    string3 = f'this is format test: {-10.123:+f} {20.45:+5.2f} {30:+06.1f} {string} {3+3:+4.2f}'
    print(string3)

if __name__ == "__main__":
    main()