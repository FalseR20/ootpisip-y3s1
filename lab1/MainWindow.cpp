#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

#include "MainWindow.hpp"

MainWindow::MainWindow() {
    this->resize(400, 200);
    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    centralLayout = new QHBoxLayout(centralWidget);

    colorChangers = new ColorChanger *[3];
    colorChangers[0] = new ColorChanger(QString("red"));
    QObject::connect(colorChangers[0]->slider, &QSlider::sliderMoved, [=](int value) {
        colorLabelColor->setRed(value);
        this->changeColorEvent();
    });
    colorChangers[1] = new ColorChanger(QString("green"));
    QObject::connect(colorChangers[1]->slider, &QSlider::sliderMoved, [=](int value) {
        colorLabelColor->setGreen(value);
        this->changeColorEvent();
    });
    colorChangers[2] = new ColorChanger(QString("blue"));
    QObject::connect(colorChangers[2]->slider, &QSlider::sliderMoved, [=](int value) {
        colorLabelColor->setBlue(value);
        this->changeColorEvent();
    });

    colorChangersWidget = new QWidget();
    colorChangersLayout = new QVBoxLayout(colorChangersWidget);
    for (int i = 0; i < 3; i++) {
        colorChangersLayout->addWidget(colorChangers[i]);
    }

    colorLabel = new QLabel(this);
    colorLabelColor = new QColor();
    this->changeColorEvent();
    centralWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    centralLayout->addWidget(colorChangersWidget);
    centralLayout->addWidget(colorLabel);
}

void MainWindow::changeColorEvent() {
    colorLabel->setStyleSheet("background-color: #" + QString::number(colorLabelColor->rgb(), 16));
}
