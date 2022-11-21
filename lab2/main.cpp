#include <QApplication>

#include "texteditor.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  app.setApplicationName("Text Editor");
  app.setApplicationVersion("0.1");
  app.setOrganizationName("ExampleSoft");
  app.setOrganizationDomain("example.com");
  TextEditor textEditor;
  textEditor.show();
  return app.exec();
}
