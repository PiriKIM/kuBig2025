import datetime

import test_package


class Myclass:
    # __str__() 메서드는 객체를 print()로 출력할 때 호출
    def __str__(self):
        return "test My class"

# 1. PATH PYTHONPATH 에 있는 ~.py 파일들 대상 불러온다.
# 2. package 가 임포트
# 3. .so 파일을 임포트 (dynamic loading) <- C 모듈 만들기(Cpython) -> GIL 우회
#     .(pyi(stub) .so) --> github. -> 실행속도가 빠르다. || 병렬처리.
#     GIL global interpreter lock -> PVM
def main():
    ptime = datetime.datetime.now()
    print(ptime)
    # datetime.datetime.now()처럼 datetime 객체를 출력할 때,
    # 사람이 읽기 좋은 형식("YYYY-MM-DD HH:MM:SS")으로 출력되는 이유는
    # __str__()이 오버라이딩되어 있기 때문!!!

    myclass =Myclass()
    print(myclass)

    print(ptime.month)
    print(f"{ptime.year} 년 {ptime.month} 월 {ptime.day} 일")

if __name__ == "__main__":
    main()