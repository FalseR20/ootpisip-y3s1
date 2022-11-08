#pragma once


#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QSpinBox>
#include <QRadioButton>
#include <QTextEdit>
#include <QFormLayout>
#include <QGridLayout>
#include <QBoxLayout>
#include <QSlider>
#include "ColorChanger.hpp"

class MainWindow : public QMainWindow {
    QWidget *centralWidget;
    QHBoxLayout *centralLayout;
    QWidget *colorChangersWidget;
    QVBoxLayout *colorChangersLayout;
    ColorChanger **colorChangers;
    QLabel *colorLabel;
    QColor *colorLabelColor;

    void changeColorEvent();

public:
    MainWindow();
};
