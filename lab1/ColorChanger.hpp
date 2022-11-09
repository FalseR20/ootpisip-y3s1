#pragma once

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>


class ColorChanger : public QWidget {
    QLabel *label;
    QSpinBox *spinBox;
    QHBoxLayout *layout;
    QSlider *slider;

public:
    explicit ColorChanger(const QString &color, QWidget *parent = nullptr);

friend class MainWindow;
};
