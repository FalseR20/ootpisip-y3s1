#ifndef TASK2_H
#define TASK2_H

#include <QObject>
#include <QWidget>
#include <QDebug>


class RobotBuilder {
public:
    virtual ~RobotBuilder() {};

    virtual void ProduceHead() const = 0;

    virtual void ProduceBody() const = 0;

    virtual void ProduceEngine() const = 0;

    virtual QString GetDescription() const = 0;
};


class Robot {
public:
    QVector<QString> parts_;

    void ListParts() const {
        qDebug() << "Product parts: ";
        for (int i = 0; i < parts_.size(); i++) {
            if (parts_[i] == parts_.back()) {
                qDebug() << parts_[i];
            } else {
                qDebug() << parts_[i] << ", ";
            }
        }
        qDebug() << "\n";
    }
};


class RobotDestroyer: public RobotBuilder {
private:
    Robot *robot;
public:
    RobotDestroyer() {
        this->Reset();
    }

    ~RobotDestroyer() {
        delete robot;
    }

    void Reset() {
        this->robot = new Robot();
    }

    void ProduceHead() const override {
        this->robot->parts_.push_back("Helmet of Fear");
    }

    void ProduceBody() const override {
        this->robot->parts_.push_back("Steel armor");
    }

    void ProduceEngine() const override {
        this->robot->parts_.push_back("Turbojet engine");
    }

    QString GetDescription() const override {
        return QString("It is Destroyer Robot");
    }

    Robot *GetProduct() {
        Robot *result = this->robot;
        this->Reset();
        return result;
    }
};


class RobotHealer: public RobotBuilder {
private:
    Robot *robot;
public:
    RobotHealer() {
        this->Reset();
    }

    ~RobotHealer() {
        delete robot;
    }

    void Reset() {
        this->robot = new Robot();
    }

    void ProduceHead() const override {
        this->robot->parts_.push_back("Doctor's cap");
    }

    void ProduceBody() const override {
        this->robot->parts_.push_back("The Robe of Power");
    }

    void ProduceEngine() const override {
        this->robot->parts_.push_back("Quiet engine");
    }

    QString GetDescription() const override {
        return QString("It is Healer Robot");
    }

    Robot *GetProduct() {
        Robot *result = this->robot;
        this->Reset();
        return result;
    }
};


class ServiceRobot: public RobotBuilder {
private:
    Robot *robot;
public:
    ServiceRobot() {
        this->Reset();
    }

    ~ServiceRobot() {
        delete robot;
    }

    void Reset() {
        this->robot = new Robot();
    }

    void ProduceHead() const override {
        this->robot->parts_.push_back("Engeneer hat");
    }

    void ProduceBody() const override {
        this->robot->parts_.push_back("Tool belt");
    }

    void ProduceEngine() const override {
        this->robot->parts_.push_back("Energy efficient engine");
    }

    QString GetDescription() const override {
        return QString("It is Service Robot");
    }

    Robot *GetProduct() {
        Robot *result = this->robot;
        this->Reset();
        return result;
    }
};


class Director {
private:
    RobotBuilder *builder;
public:

    void set_builder(RobotBuilder *builder) {
        this->builder = builder;
    }

    void BuildMinimalViableRobot() {
        this->builder->ProduceEngine();
    }

    void BuildFullFeaturedRobot() {
        this->builder->ProduceBody();
        this->builder->ProduceHead();
        this->builder->ProduceEngine();
    }
};


class Creator {
public:
    virtual ~Creator() {};

    virtual RobotBuilder *FactoryMethod() const = 0;
};


class RobotDestroyerCreator: public Creator {
public:
    RobotBuilder *FactoryMethod() const override {
        return new RobotDestroyer();
    }
};


class RobotHealerCreator: public Creator {
public:
    RobotBuilder *FactoryMethod() const override {
        return new RobotHealer();
    }
};


class ServiceRobotCreator: public Creator {
public:
    RobotBuilder *FactoryMethod() const override {
        return new ServiceRobot();
    }
};


class Task2: public QWidget {
Q_OBJECT
public:
    explicit Task2(QWidget *parent = nullptr);
};


#endif // TASK2_H
