from functools import wraps


def hi(v1, v2):
    def mydecorator(func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            print(f"func 실행 전 코드...{v1}")
            result = func(*args, **kwargs)
            print(f"func 실행 후 코드...{v2}")
            return result

        return wrapper
    return mydecorator

@hi("hi", "bye")
def print_hello(n, v):
    for _ in range(n):
        print(v)
    return 123


def main():
    print(print_hello(3, "hello"))
    print(print_hello.__name__)

if __name__ == "__main__":
    main()