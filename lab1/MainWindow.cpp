#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

#include "MainWindow.hpp"


MainWindow::MainWindow() {
    this->resize(400, 400);
    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    centralWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    centralLayout = new QVBoxLayout(centralWidget);

    colorChangers[0] = new ColorChanger(QString("red"), centralWidget);
    QObject::connect(
            colorChangers[0]->slider, &QSlider::valueChanged, [=](int value) {
                coloredWidgetColor.setRed(value);
                this->changeColorEvent();
            }
    );
    colorChangers[1] = new ColorChanger(QString("green"), centralWidget);
    QObject::connect(
            colorChangers[1]->slider, &QSlider::valueChanged, [=](int value) {
                coloredWidgetColor.setGreen(value);
                this->changeColorEvent();
            }
    );
    colorChangers[2] = new ColorChanger(QString("blue"), centralWidget);
    QObject::connect(
            colorChangers[2]->slider, &QSlider::valueChanged, [=](int value) {
                coloredWidgetColor.setBlue(value);
                this->changeColorEvent();
            }
    );

    for (
        auto &colorChanger: colorChangers
            ) {
        centralLayout->addWidget(colorChanger);
    }

    auto resetButton = new QPushButton(centralWidget);
    centralLayout->addWidget(resetButton);
    resetButton->setText(QString("Reset"));
    QObject::connect(
            resetButton, &QPushButton::clicked, [=]() {
                for (
                    auto &colorChanger: colorChangers
                        ) {
                    colorChanger->slider->setValue(0);
                }
            }
    );

    auto setPinkButton = new QPushButton(centralWidget);
    centralLayout->addWidget(setPinkButton);
    setPinkButton->setText(QString("Ret pink"));
    QObject::connect(
            setPinkButton, &QPushButton::clicked, [=]() {
                colorChangers[0]->slider->setValue(255);
                colorChangers[1]->slider->setValue(0);
                colorChangers[2]->slider->setValue(255);
            }
    );

    coloredWidget = new QWidget(centralWidget);
    centralLayout->addWidget(coloredWidget);
    coloredWidget->setAutoFillBackground(true);
    coloredWidget->setPalette(QPalette(coloredWidgetColor));
}

void MainWindow::changeColorEvent() {
    coloredWidget->setPalette(QPalette(coloredWidgetColor));
}
