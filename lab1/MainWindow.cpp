#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

#include "MainWindow.hpp"

MainWindow::MainWindow() {
    this->resize(400, 400);
    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    centralLayout = new QVBoxLayout(centralWidget);

//    colorChangers = new ColorChanger *[3];
    colorChangers[0] = new ColorChanger(QString("red"), centralWidget);
    QObject::connect(colorChangers[0]->slider, &QSlider::sliderMoved, [=](int value) {
        colorLabelColor->setRed(value);
        this->changeColorEvent();
    });
    colorChangers[1] = new ColorChanger(QString("green"), centralWidget);
    QObject::connect(colorChangers[1]->slider, &QSlider::sliderMoved, [=](int value) {
        colorLabelColor->setGreen(value);
        this->changeColorEvent();
    });
    colorChangers[2] = new ColorChanger(QString("blue"), centralWidget);
    QObject::connect(colorChangers[2]->slider, &QSlider::sliderMoved, [=](int value) {
        colorLabelColor->setBlue(value);
        this->changeColorEvent();
    });

    for (auto &colorChanger: colorChangers) {
        centralLayout->addWidget(colorChanger);
    }
    auto reset = new QPushButton(centralWidget);
    reset->setText(QString("Reset"));
    QObject::connect(reset, &QPushButton::clicked, [=]() {
        colorLabelColor->setRgb(0, 0, 0);
        this->changeColorEvent();
    });
    centralLayout->addWidget(reset);

    colorLabel = new QLabel(centralWidget);
    centralLayout->stretch(3);
    centralLayout->addWidget(colorLabel);
    colorLabelColor = new QColor();
    this->changeColorEvent();
    centralWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);


}

void MainWindow::changeColorEvent() {
    colorLabel->setStyleSheet("background-color: #" + QString::number(colorLabelColor->rgb(), 16));
}
