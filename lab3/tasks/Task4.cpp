#include <QTextStream>
#include "Task4.hpp"


Task4::Task4(QWidget *parent) : TaskWidget(
        QString(
                "Сформировать стек из 5 чисел. Поменять местами максимальный и\n"
                "минимальный элементы стека."
        ), parent
) {
    lineEdit = new QLineEdit(runWidget);
    lineEdit->setText("1 2 3 4 5");
    lineEdit->setFont(QFont("", 15));
    int *check = new int(1);
    lineEdit->setDisabled(true);
    runButton = new QPushButton(runWidget);
    runButton->setText("Run");
    auto *taskLayout = new QHBoxLayout(runWidget);
    taskLayout->addWidget(lineEdit);
    taskLayout->addWidget(runButton);

    QWidget::connect(
            runButton, &QPushButton::clicked, [=]() {
                if (*check) {
                    lineEdit->setText("5 2 3 4 1");
                }
                else
                    lineEdit->setText("1 2 3 4 5");
                *check = 1 - *check;
            }
    );
}
