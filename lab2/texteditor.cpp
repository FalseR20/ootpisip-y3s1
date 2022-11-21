#include "texteditor.h"
#include "ui_texteditor.h"
#include <QCloseEvent>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <iostream>

TextEditor::TextEditor(const QString &fileName, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TextEditor) {
  ui->setupUi(this);
  this->setAttribute(Qt::WA_DeleteOnClose);
  this->setWindowTitle("Text Editor[*]");
  ui->actionCopy->setEnabled(false);
  ui->actionCut->setEnabled(false);
  ui->actionRedo->setEnabled(false);
  ui->actionUndo->setEnabled(false);
  loadFile(fileName);
}

void TextEditor::loadFile(const QString &fileName) {
  if (fileName.isEmpty()) {
    setFileName(QString());
    return;
  }
  QString fileContents;
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return;

  while (!file.atEnd()) {
    QByteArray line = file.readLine();
    fileContents = fileContents + line + "\n";
  }
  ui->textEdit->setText(fileContents);
  file.close();
  setFileName(fileName);
  this->setWindowModified(false);
}

void TextEditor::setFileName(const QString &fileName) {
  this->m_fileName = fileName;
  this->setWindowTitle(QString("%1[*] - %2")
                           .arg(m_fileName.isNull()
                                    ? "untitled"
                                    : QFileInfo(m_fileName).fileName())
                           .arg(QApplication::applicationName()));
}

bool TextEditor::saveFileAs() {
  QString fileName = QFileDialog::getSaveFileName(
      this, "Save document",
      m_fileName.isNull() ? QDir::currentPath() : m_fileName,
      "Text documents (*.txt)");
  if (fileName.isNull()) {
    return false;
  } else {
    setFileName(fileName);
    return saveFile();
  }
}

bool TextEditor::saveFile() {
  if (this->m_fileName.isNull()) {
    return saveFileAs();
  } else {
    QFile file(m_fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
      QMessageBox msgBox;
      msgBox.setIcon(QMessageBox::Warning);
      msgBox.setText("File could not be saved properly, try again.");
      msgBox.exec();
      setFileName(QString());
      return false;
    } else {
      QTextStream out(&file);
      out << ui->textEdit->toPlainText();
      file.close();
      this->setWindowModified(false);
      return true;
    }
  }
}

TextEditor::~TextEditor() { delete ui; }

void TextEditor::closeEvent(QCloseEvent *e) {
  if (this->isWindowModified()) {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText(
        "This document has been modified, do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No |
                              QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Yes:
      saveFile();
      break;
    case QMessageBox::No:
      e->accept();
      break;
    case QMessageBox::Cancel:
      e->ignore();
      break;
    default:
      e->ignore();
      break;
    }
  } else {
    e->accept();
  }
}
