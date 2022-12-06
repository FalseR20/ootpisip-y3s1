#include <QTextStream>
#include <QSpinBox>
#include <QCheckBox>
#include "Task3.hpp"


Task3::Task3(QWidget *parent) : TaskWidget(
        QString(
                "Заполнить 2 списка случайными элементами. Реализовать добавление\n"
                "введенного элемента в 1 список или второй, или в оба (использовать\n"
                "CheckBox)."
        ), parent
) {
    auto line_edit = new QLineEdit(runWidget);
    line_edit->setText("0");
    runButton = new QPushButton(runWidget);
    runButton->setText("Run");
    auto *taskLayout = new QHBoxLayout(runWidget);
    taskLayout->addWidget(line_edit);
    taskLayout->addWidget(runButton);
    auto checkBox1 = new QCheckBox("Add to list1");
    checkBox1->setChecked(true);
    layout()->addWidget(checkBox1);
    auto checkBox2 = new QCheckBox("Add to list2");
    layout()->addWidget(checkBox2);
    auto list1 = new QLineEdit;
    list1->setDisabled(true);
    list1->setText("1 2 3");
    layout()->addWidget(list1);
    auto list2 = new QLineEdit;
    list2->setDisabled(true);
    list2->setText("4 5 6");
    layout()->addWidget(list2);


    QWidget::connect(
            runButton, &QPushButton::clicked, [=]() {
                if (!checkBox1->isChecked() and !checkBox2->isChecked())
                    return;
                auto text = line_edit->text();
                if (checkBox1->isChecked()) {
                    list1->setText(list1->text() + " " + text);
                }
                if (checkBox2->isChecked()) {
                    list2->setText(list2->text() + " " + text);
                }
            }
    );
}
