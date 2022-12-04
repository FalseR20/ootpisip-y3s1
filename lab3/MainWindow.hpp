#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QMap>

#include "tasks/TaskWidget.hpp"


class MainWindow: public QMainWindow {
    QWidget *centralWidget;
    QVBoxLayout *centralWidgetLayout;
    QGroupBox *tasksGroupBox;
    QHBoxLayout *tasksGroupBoxLayout;
    int TASKS_COUNT = 6;
    TaskWidget *taskWidget;
    QVector<TaskWidget *> tasksVector;

public:
    MainWindow(QWidget *parent = nullptr);
};
