#include "MainWindow.hpp"
#include "tasks/Task1.hpp"
#include "tasks/Task2.hpp"
#include "tasks/Task3.hpp"
#include "tasks/Task4.hpp"
#include "tasks/Task5.hpp"
#include <iostream>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    resize(700, 400);

    // Central widget
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    centralWidgetLayout = new QVBoxLayout(centralWidget);

    // Tasks group widget
    tasksGroupBox = new QGroupBox(centralWidget);
    centralWidgetLayout->addWidget(tasksGroupBox);

    tasksGroupBoxLayout = new QHBoxLayout(tasksGroupBox);
    tasksGroupBoxLayout->setAlignment(Qt::Alignment(Qt::AlignTop));
    tasksGroupBox->setSizePolicy(
            QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum
    );

    // Tasks vector
    tasksVector = {
            new Task1(),
            new Task2(),
            new Task3(),
            new Task4(),
            new Task5(),
            new TaskWidget("6"),
    };
    for (auto taskWidget: tasksVector) {
        taskWidget->hide();
        centralWidgetLayout->addWidget(taskWidget);
    }
    taskWidget = tasksVector[0];
    taskWidget->show();

    // Buttons
    QString str;
    for (auto i = 0; i < TASKS_COUNT; ++i) {
        auto *tasksButton = new QPushButton(tasksGroupBox);
        str.sprintf("Task %d", i + 1);
        tasksButton->setText(str);
        tasksButton->setMinimumSize(80, 50);
        QObject::connect(
                tasksButton, &QPushButton::clicked, [=]() {
                    taskWidget->hide();
                    taskWidget = tasksVector[i];
                    taskWidget->show();
                }
        );
        tasksGroupBoxLayout->addWidget(tasksButton);
    }
}
