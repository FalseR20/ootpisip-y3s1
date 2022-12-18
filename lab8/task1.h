#ifndef TASK1_H
#define TASK1_H

#include <QtWidgets>
#include <QObject>
#include <QWidget>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMap>


using namespace std;


// ABSTRACT PRODUCTS
class AbstractList: public QListWidget {
public:
    virtual ~AbstractList() {};
};


class AbstractLineEdit: public QLineEdit {
public:
    virtual ~AbstractLineEdit() {};
};


class AbstractButton: public QPushButton {
Q_OBJECT
public:
    virtual ~AbstractButton() {};

public slots:

    virtual void onClick() = 0;
};


// CONCRETE PRODUCTS
//LIST
class RedList: public AbstractList {};


class BlueList: public AbstractList {};


// LINE EDIT
class RedLineEdit: public AbstractLineEdit {};


class BlueLineEdit: public AbstractLineEdit {};


// BUTTON
class RedButton: public AbstractButton {
Q_OBJECT
public slots:

    void onClick() override {
        QMessageBox::information(this, tr("RED BUTTON"), tr("Clicking to red button."));
    };
};


class BlueButton: public AbstractButton {
Q_OBJECT
public slots:

    void onClick() override {
        QMessageBox::information(
                this, tr("BLUE BUTTON"), tr("Clicking to blue button.")
        );
    };
};


// ABSTRACT FACTORY
class AbstractFactory {
public:
    virtual AbstractList *CreateList() const = 0;

    virtual AbstractLineEdit *CreateLineEdit() const = 0;

    virtual AbstractButton *CreateButton() const = 0;
};


// CONCRETE FACTORY
class RedFactory: public AbstractFactory {
public:
    AbstractList *CreateList() const override {
        AbstractList *list = new RedList();
        list->setStyleSheet("color: red;");
        return list;
    };

    AbstractLineEdit *CreateLineEdit() const override {
        AbstractLineEdit *lineEdit = new RedLineEdit();
        lineEdit->setStyleSheet("color: red;");
        return lineEdit;
    };

    AbstractButton *CreateButton() const override {
        AbstractButton *button = new RedButton();
        button->setStyleSheet("color: red;");
        return button;
    };
};


class BlueFactory: public AbstractFactory {
public:
    AbstractList *CreateList() const override {
        AbstractList *list = new BlueList();
        list->setStyleSheet("color: blue;");
        return list;
    };

    AbstractLineEdit *CreateLineEdit() const override {
        AbstractLineEdit *lineEdit = new BlueLineEdit();
        lineEdit->setStyleSheet("color: blue;");
        return lineEdit;
    };

    AbstractButton *CreateButton() const override {
        AbstractButton *button = new BlueButton();
        button->setStyleSheet("color: blue;");
        return button;
    };
};

// MAIN

class Task1: public QWidget {
Q_OBJECT
public:
    explicit Task1(const AbstractFactory &factory, QWidget *parent = nullptr);

public slots:

    void closeAllWindows();
};

// PROTOTYPE

enum Type {
    RED_PROTOTYPE = 0, BLUE_PROTOTYPE
};


class Prototype {
protected:
    QString prototype_name_;
    const AbstractFactory *prototype_factory_;

public:
    Prototype() {}

    Prototype(QString prototype_name): prototype_name_(prototype_name) {}

    virtual ~Prototype() {}

    virtual Prototype *Clone() const = 0;

    virtual void Show() = 0;
};


class RedPrototype: public Prototype {
private:
    const AbstractFactory *red_prototype_field1_;

public:
    RedPrototype(
            QString prototype_name, AbstractFactory *red_prototype_field
    ): Prototype(prototype_name), red_prototype_field1_(red_prototype_field) {}

    void Show() override {
        Task1 *window = new Task1(*this->red_prototype_field1_);
        window->show();
    }

    Prototype *Clone() const override {
        return new RedPrototype(*this);
    }
};


class BluePrototype: public Prototype {
private:
    const AbstractFactory *blue_prototype_field2_;

public:
    BluePrototype(
            QString prototype_name, AbstractFactory *concrete_prototype_field
    ): Prototype(prototype_name), blue_prototype_field2_(concrete_prototype_field) {}

    void Show() override {
        Task1 *window = new Task1(*this->blue_prototype_field2_);
        window->show();
    }

    Prototype *Clone() const override {
        return new BluePrototype(*this);
    }
};


class PrototypeFactory {
private:
    QMap<Type, Prototype *> prototypes_;

public:
    PrototypeFactory() {
        RedFactory *redFactory = new RedFactory();
        BlueFactory *blueFactory = new BlueFactory();
        prototypes_[Type::RED_PROTOTYPE] = new RedPrototype(
                "RED_PROTOTYPE", redFactory
        );
        prototypes_[Type::BLUE_PROTOTYPE] = new BluePrototype(
                "BLUE_PROTOTYPE", blueFactory
        );
    }

    ~PrototypeFactory() {
        delete prototypes_[Type::RED_PROTOTYPE];
        delete prototypes_[Type::BLUE_PROTOTYPE];
    }

    Prototype *CreatePrototype(Type type) {
        return prototypes_[type]->Clone();
    }
};


// SINGLETON

class Singleton: public QPushButton {
Q_OBJECT
protected:
    Singleton(const QString buttonText): buttonText_(buttonText) {
        this->setStyleSheet("color: yellow;");
        this->setText(buttonText_);

        connect(this, SIGNAL(clicked(bool)), this, SLOT(onClick()));
    }

    static Singleton *singleton_;

    QString buttonText_;

public:
    // No clone
    Singleton(Singleton &other) = delete;

    // No assignable
    void operator=(const Singleton &) = delete;

    static Singleton *GetInstance(const QString &buttonText);

public slots:

    void onClick() {
        QMessageBox::information(
                this, tr("SINGLETON BUTTON"), tr("Clicking to singleton button.")
        );
    }
};


#endif // TASK1_H
