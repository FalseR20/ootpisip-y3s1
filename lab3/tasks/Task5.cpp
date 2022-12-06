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
    runButton = new QPushButton(runWidget);
    runButton->setText("Run");
    auto *textResult = new QLineEdit(runWidget);
    textResult->setDisabled(true);
    layout()->addWidget(textEdit);
    layout()->addWidget(runButton);
    layout()->addWidget(textResult);

    QWidget::connect(
            runButton, &QPushButton::clicked, [=]() {
                auto text = textEdit->toPlainText();
                auto lines = text.split("\n");
                int count = lines[0].toInt();
                QString people;
                for (int i = 1; i < lines.count(); i++) {
                    if (lines[i].split(" ").count() == count) {
                        QString is;
                        is.sprintf(" %d", i);
                        people += is;
                    }
                }
                textResult->setText("Побывали у всех: " + people);
            }
    );
}
