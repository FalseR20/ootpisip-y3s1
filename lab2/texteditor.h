#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QString>


QT_BEGIN_NAMESPACE
namespace Ui {
class TextEditor;
}
QT_END_NAMESPACE

class TextEditor: public QMainWindow {
Q_OBJECT

public:
    TextEditor(const QString &fileName = QString(), QWidget *parent = nullptr);

    ~TextEditor();

private slots:

    bool saveFile();

    bool saveFileAs();

private:
    void loadFile(const QString &fileName);

    void setFileName(const QString &fileName);

    Ui::TextEditor *ui;
    QString m_fileName;

protected:
    void closeEvent(QCloseEvent *e);
};


#endif // TEXTEDITOR_H
