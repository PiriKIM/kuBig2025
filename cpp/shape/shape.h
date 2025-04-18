#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
// private:
protected:
    int x_;
    int y_;

public:
    Shape(int x = 0, int y = 0);
    virtual ~Shape() { }

    void move(int x, int y);
    virtual double area() const = 0;        // can't be implemented. -> pure virtual func.

};

#endif