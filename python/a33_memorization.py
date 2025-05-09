cnt = 0
dictionary = {1:1, 2:1}

def fibonacci(n):
    global cnt  # 전역 변수 명시
    cnt += 1
    
    if n in dictionary:
        print(f"dict {n}")
        return dictionary[n]
    else:
        print(f"else {n}")
        output = fibonacci(n - 1) + fibonacci(n - 2)
        dictionary[n] = output
        return output
    
def main():
    print(fibonacci(99))
    print(f"fibonacci가 수행된 횟수 {cnt}")

    print(fibonacci(100))
    print(f"fibonacci가 수행된 횟수 {cnt}")

    print(fibonacci(101))
    print(f"fibonacci가 수행된 횟수 {cnt}")

if __name__ == "__main__":
    main()