#include "documentwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DocumentWindow w;
    w.show();

    return a.exec();
}
