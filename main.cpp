#include "stdio.h"
#include "Circle.h"
#include "Rectangle.h"

int main() {
    IShape* shapes[] = { new Circle(), new Rectangle() };

    for (IShape* shape : shapes) {
        shape->Draw();
    }

    // メモリ解放
    for (IShape* shape : shapes) {
        delete shape;
    }

    return 0;
}