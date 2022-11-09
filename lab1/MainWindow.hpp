#pragma once


#include <QLayout>
#include <QMainWindow>
#include <QWidget>

#include "ColorChanger.hpp"

class MainWindow : public QMainWindow {
    QWidget *centralWidget;
    QVBoxLayout *centralLayout;
    ColorChanger *colorChangers[3]{};
    QWidget *coloredWidget;

    QColor coloredWidgetColor;

    void changeColorEvent();

public:
    MainWindow();
};
