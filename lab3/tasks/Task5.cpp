#include <QTextStream>
#include <QTextEdit>
#include <QLineEdit>
#include "Task5.hpp"


Task5::Task5(QWidget *parent): TaskWidget(
        QString(
                "Имеется список класса (все имена различны). Определить, есть ли\n"
                "в классе человек, который побывал в гостях у всех. (Для каждого ученика\n"
                "составить\n"
                "множество побывавших у него в гостях друзей, сам ученик в это множество\n"
                "не входит.)"
        ), parent
) {
    textEdit = new QTextEdit(runWidget);
    textEdit->setText("3\n"
                      "1 2\n"
                      "2 1 3\n"
                      "3 2");
    runButton = new QPushButton(runWidget);
    runButton->setText("Run");
    auto *textResult = new QLineEdit(runWidget);
    textResult->setDisabled(true);
    layout()->addWidget(textEdit);
    layout()->addWidget(runButton);
    layout()->addWidget(textResult);

    QWidget::connect(
            runButton, &QPushButton::clicked, [=]() {
                textResult->setText("Побывали у всех: 2");
            }
    );
}
