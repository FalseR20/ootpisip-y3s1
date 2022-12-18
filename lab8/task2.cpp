#include "task2.h"
#include <QDebug>


void ClientCode(Director &director) {
    Creator *creator = new RobotDestroyerCreator();
    RobotDestroyer *builder = dynamic_cast<RobotDestroyer *>(creator->FactoryMethod());

    director.set_builder(builder);
    qDebug() << "Standard basic product:\n";
    director.BuildMinimalViableRobot();

    Robot *robot = builder->GetProduct();
    robot->ListParts();
    delete robot;

    qDebug() << "Standard full featured product:\n";
    director.BuildFullFeaturedRobot();

    robot = builder->GetProduct();
    robot->ListParts();
    delete robot;

    qDebug() << "Custom product:\n";
    builder->ProduceHead();
    builder->ProduceEngine();
    robot = builder->GetProduct();
    robot->ListParts();
    delete robot;

    delete builder;
    delete creator;
}

Task2::Task2(QWidget *parent): QWidget{parent} {
    Director *director = new Director();
    ClientCode(*director);
    delete director;
}
