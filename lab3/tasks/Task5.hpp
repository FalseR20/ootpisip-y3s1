#pragma once

#include <QTextEdit>
#include <QPushButton>
#include "TaskWidget.hpp"


class Task5: public TaskWidget {
    QTextEdit *textEdit;
    QPushButton *runButton;

public:
    explicit Task5(QWidget *parent = nullptr);
};
