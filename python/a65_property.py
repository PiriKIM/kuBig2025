import math

class Circle:
    def __init__(self, radius):
        self._radius = radius
        self.__hidden = radius

    def get_area(self):
        return math.pi * self._radius ** 2
    
    @property
    def radius(self):
        return self._radius

    @radius.getter
    def radius(self):
        return self._radius
    
    @radius.setter
    def radius(self, value):
        if value < 0:
            self._radius = 0
        elif value > 100:
            self._radius = 100
        else:
            self._radius = value

def main():
    circle = Circle(10)
    # print(circle._radius)   # 언더바 1번은 부탁만 한다.
    print(circle.radius)
    circle.radius = -10
    print(circle.radius)
    circle.radius = 120
    print(circle.radius)
    circle.radius = 55
    print(circle.radius)
    print(circle.get_area())
    # print(circle.__hidden)  # 언더바 2번이면 강제성이 있다.
    # 강제성은 있지만 은닉은 못 한다.

if __name__ == "__main__":
    main()