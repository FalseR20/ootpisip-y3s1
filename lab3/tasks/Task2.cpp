#include <QTextStream>
#include <QSpinBox>
#include "Task2.hpp"


Task2::Task2(QWidget *parent): TaskWidget(
        QString(
                "1 Дан целочисленный массив A. Вывести номер первого из тех его элементов\n"
                "A[i], которые удовлетворяют двойному неравенству: A[1] < A[i] < A[10]. Если\n"
                "таких элементов нет, то вывести 0.\n"
                "\n"
                "2 Дана матрица размера m x n. Найти минимальное и максимальное значение\n"
                "в каждой строке (нахождение максимального/минимального значения\n"
                "определяется пользователем в виджете comboBox)."
        ), parent
) {
    lineEdit = new QLineEdit(runWidget);
    runButton = new QPushButton(runWidget);
    runButton->setText("Run");
    auto *taskLayout = new QHBoxLayout(runWidget);
    auto *resultBox = new QSpinBox();
    resultBox->setDisabled(true);
    resultBox->setValue(0);
    taskLayout->addWidget(lineEdit);
    taskLayout->addWidget(runButton);
    taskLayout->addWidget(resultBox);

    QWidget::connect(
            runButton, &QPushButton::clicked, [=]() {
                auto text = lineEdit->text();
                auto text_vals = text.split(" ");
                QVector<int> values;
                for (auto &text_val: text_vals) {
                    if (!text_val.isEmpty())
                        values.push_back(text_val.toInt());
                }

                resultBox->setValue(0);
                if (values.size() < 10) {
                    return;
                }
                auto v0 = values.at(0);
                auto v9 = values.at(9);
                for (auto val: values) {
                    if (v0 < val and val < v9) {
                        resultBox->setValue(val);
                        return;
                    }
                }
            }
    );
}
