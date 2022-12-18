#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("../db.sqlite");

    if (!sdb.open()) {
        qDebug() << "DB can't be open";
    }

    QSqlQuery query;
    query.prepare("INSERT INTO artist (id, name, country) "
                  "VALUES (:id, :name, :country)");
    query.bindValue(":id", 4);
    query.bindValue(":name", "Ariana Grande");
    query.bindValue(":country", "USA");
    query.exec();

    query.bindValue(":id", 5);
    query.bindValue(":name", "Kendrick Lamar");
    query.bindValue(":country", "USA");
    query.exec();

    query.prepare("INSERT INTO cd (id, artistid, title, year) "
                  "VALUES (:id, :artistid, :title, :year);");
    query.bindValue(":id", 4);
    query.bindValue(":artistid", 4);
    query.bindValue(":title", "Sweetener");
    query.bindValue(":year", 2018);
    query.exec();

    query.bindValue(":id", 5);
    query.bindValue(":artistid", 5);
    query.bindValue(":title", "DAMN.");
    query.bindValue(":year", 2017);
    query.exec();

    query.prepare("INSERT INTO track (id, cdid, number, title, duration) "
                  "VALUES (:id, :cdid, :number, :title, :duration);");
    query.bindValue(":id", 4);
    query.bindValue(":cdid", 4);
    query.bindValue(":number", 10);
    query.bindValue(":title", "No Tears Left to Cry");
    query.bindValue(":duration", "3:25");
    query.exec();

    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("artist");
    model->select();
    ui->tableView->setModel(model);

    QSqlTableModel *model2 = new QSqlTableModel;
    model2->setTable("cd");
    model2->select();
    ui->tableView_2->setModel(model2);

    QSqlTableModel *model3 = new QSqlTableModel;
    model3->setTable("track");
    model3->select();
    ui->tableView_3->setModel(model3);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_id_but_pressed() {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM cd WHERE artistid=?");
    query.bindValue(0, ui->artistid_text->text());
    query.exec();
    query.next();
    ui->artistid_res->setText(query.value(0).toString());
}

void MainWindow::on_title_but_pressed() {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM cd WHERE title=?");
    query.bindValue(0, ui->title_text->text());
    query.exec();
    query.next();
    ui->title_res->setText(query.value(0).toString());
}

void MainWindow::on_year_but_pressed() {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM cd WHERE year=?");
    query.bindValue(0, ui->year_text->text().toInt());
    query.exec();
    query.next();
    ui->year_res->setText(query.value(0).toString());
}
