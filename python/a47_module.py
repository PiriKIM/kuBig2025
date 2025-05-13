import math # 모듈명 명시해야함
from math import e, pi, sin, cos, tan, tau # 모듈명을 명시하기 싫을 때

# sudo python3 -m pip install numpy
import numpy as np

def main():
    # print(math.pi)
    # print(pi)
    print(np.pi)
    print(pi, e, tau)
    print(math.sin(30 / 180 * math.pi))     # sin 30도 -> 라디안



if __name__ == "__main__":
    main()