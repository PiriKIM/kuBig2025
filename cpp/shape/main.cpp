#include <iostream>
#include <typeinfo>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"

void printShape(const Shape *ps)
{
    if (typeid(*ps) == typeid(Rectangle)) {
        const Rectangle *pr = (Rectangle *)ps;
        std::cout << "rectangle diagonal : " << pr->getDiagonal() << ", ";
    } else if (typeid(*ps) == typeid(Circle)) {
        const Circle *pc = (Circle *)ps;
        std::cout << "circle circumference : " << pc->getCircumference() << ", ";
    }

    std::cout << "area : " << ps->area() << std::endl;
}

int main()
{
    // Shape s;     // 생성 불가능
    Shape *ps;      // 생성 가능
    Rectangle r1(2, 3, 40, 50);
    Circle c1(10, 10, 40);
    
    Shape *pShapes[5];
    pShapes[0] = new Rectangle(10, 10, 100, 20);
    pShapes[1] = new Circle(50, 50, 20);
    pShapes[2] = new Rectangle(0, 0, 10, 10);
    pShapes[3] = new Circle(100, 100, 50);
    pShapes[4] = new Circle(100, 150, 20);

    for (int i = 0; i < 5; ++i) {
        printShape(pShapes[i]);
    }

    for (int i = 0; i < 5; ++i) {
        delete pShapes[i];    
    }

    return 0;
}