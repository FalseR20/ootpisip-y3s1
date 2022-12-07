#include <QTextStream>
#include <QBitArray>
#include "AdditionalTask.hpp"


AdditionalTask::AdditionalTask(QWidget *parent) : TaskWidget(
        "Доп задание\n"
        "Из введенного слова составить массив из битов",
        parent
) {
    labelText = "Доп задание";

    lineEdit = new QLineEdit(runWidget);
    lineEdit->setText("Word");
    runButton = new QPushButton(runWidget);
    runButton->setText("Run");
    auto *resultLineEdit = new QLineEdit(runWidget);
    resultLineEdit->setDisabled(true);
    auto *taskLayout = new QHBoxLayout(runWidget);
    taskLayout->addWidget(lineEdit);
    taskLayout->addWidget(runButton);
    layout()->addWidget(resultLineEdit);

    QWidget::connect(
            runButton, &QPushButton::clicked, [=]() {
                QByteArray text = lineEdit->text().toLocal8Bit();
                QBitArray arr(text.count() * 8);

                QString textOut;
                QTextStream textOutStream(&textOut);
                for (int iByte = 0; iByte < text.count(); iByte++) {
                    for (int iBit = 0; iBit < 8; iBit++) {
                        bool bit = text.at(iByte) & (1 << (7 - iBit));
                        arr.setBit(iByte * 8 + iBit, bit);
                        textOutStream << bit;
                    }
                    textOutStream << " ";

                }
                resultLineEdit->setText(textOut);
            }
    );
}
