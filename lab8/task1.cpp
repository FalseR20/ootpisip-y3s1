#include "task1.h"


Singleton *Singleton::singleton_ = nullptr;;

Singleton *Singleton::GetInstance(const QString &buttonText) {
    if (singleton_ == nullptr) {
        singleton_ = new Singleton(buttonText);
    }
    return singleton_;
}

Task1::Task1(const AbstractFactory &factory, QWidget *parent): QWidget{parent} {
    this->resize(400, 300);

    AbstractButton *abstractButton = factory.CreateButton();
    AbstractList *abstractList = factory.CreateList();
    AbstractLineEdit *abstractLineEdit = factory.CreateLineEdit();

    QVBoxLayout *layout = new QVBoxLayout(this);
    QHBoxLayout *actionButtonsLayout = new QHBoxLayout();

    Singleton *singletonButton = Singleton::GetInstance("Singleton Button");

    abstractButton->setText("Click Me");

    QPushButton *exitBtn = new QPushButton();
    exitBtn->setText("Close Window");

    QPushButton *closeAllBtn = new QPushButton();
    closeAllBtn->setText("Close all windows");

    actionButtonsLayout->addWidget(exitBtn);
    actionButtonsLayout->addWidget(closeAllBtn);

    new QListWidgetItem(tr("First"), abstractList);
    new QListWidgetItem(tr("Second"), abstractList);
    new QListWidgetItem(tr("Third"), abstractList);

    layout->addWidget(abstractButton);
    layout->addWidget(abstractList);
    layout->addWidget(abstractLineEdit);
    layout->addWidget(singletonButton);
    layout->addLayout(actionButtonsLayout);

    connect(exitBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(closeAllBtn, SIGNAL(clicked(bool)), this, SLOT(closeAllWindows()));
    connect(abstractButton, SIGNAL(clicked(bool)), abstractButton, SLOT(onClick()));
}

void Task1::closeAllWindows() {
    QCoreApplication::quit();
}
