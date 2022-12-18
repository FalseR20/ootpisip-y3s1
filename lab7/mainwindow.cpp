#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_pushButton_3_clicked() {
    QCoreApplication::quit();
}


void MainWindow::on_pushButton_clicked() {
    verticalText = new VerticalText();
    verticalText->show();
}


void MainWindow::on_pushButton_2_clicked() {
    snowflake = new Snowflake();
    snowflake->show();
}

