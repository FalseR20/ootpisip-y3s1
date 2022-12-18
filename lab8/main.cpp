#include "task1.h"
#include "task2.h"

#include <QApplication>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // TASK 1
    PrototypeFactory *prototypeFactory = new PrototypeFactory();
    Prototype *redPrototype = prototypeFactory->CreatePrototype(Type::RED_PROTOTYPE);
    redPrototype->Show();

    Prototype *bluePrototype = prototypeFactory->CreatePrototype(Type::BLUE_PROTOTYPE);
    bluePrototype->Show();

    Prototype *bluePrototypeClone = bluePrototype->Clone();
    bluePrototypeClone->Show();

    // TASK 2
    Task2 *testing = new Task2();
    delete testing;

    return a.exec();
}
