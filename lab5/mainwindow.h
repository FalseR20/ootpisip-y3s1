#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSql>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QTableView>
#include <QApplication>
#include <QTabWidget>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>

namespace Ui {
    class MainWindow;
}
class MainWindow : public QMainWindow {
Q_OBJECT
    //QSqlQuery query;
    QSqlDatabase sdb;
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:

    void on_id_but_pressed();

    void on_title_but_pressed();

    void on_year_but_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H