#include <QTextStream>
#include "Task1.hpp"


Task1::Task1(QWidget *parent): TaskWidget(
        QString(
                "Задание 1. Вариант 7\n"
                "Из трех данных чисел выбрать наименьшее и\n"
                "наибольшее (числа вводятся в lineedit), и заменить третье число иx\n"
                "разностью (число должно быть изменено в текущем lineedit)."
        ), parent
) {
    lineEdit = new QLineEdit(runWidget);
    runButton = new QPushButton(runWidget);
    runButton->setText("Run");
    auto *taskLayout = new QHBoxLayout(runWidget);
    taskLayout->addWidget(lineEdit);
    taskLayout->addWidget(runButton);

    QWidget::connect(
            runButton, &QPushButton::clicked, [=]() {
                auto text = lineEdit->text();
                QVector<int> values(3);
                QTextStream textStream(&text);
                textStream >> values[0] >> values[1] >> values[2];

                auto *maxValuePtr = std::max_element(values.cbegin(), values.cend());
                auto *minValuePtr = std::min_element(values.cbegin(), values.cend());
                for (auto iter = values.begin(); iter != values.end(); iter++) {
                    if (iter != minValuePtr && iter != maxValuePtr) {
                        *iter = *maxValuePtr - *minValuePtr;
                        break;
                    }
                }
                text.sprintf("%d %d %d", values[0], values[1], values[2]);
                lineEdit->setText(text);
            }
    );
}
