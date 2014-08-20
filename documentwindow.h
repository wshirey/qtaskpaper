#ifndef DOCUMENTWINDOW_H
#define DOCUMENTWINDOW_H

#include "taskpaperhighlighter.h"

#include <QMainWindow>

namespace Ui {
class DocumentWindow;
}

class DocumentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DocumentWindow(QWidget *parent = 0);
    ~DocumentWindow();

private slots:
    void on_action_New_triggered();

private:
    Ui::DocumentWindow *ui;
    TaskPaperHighlighter* highlighter;
};

#endif // DOCUMENTWINDOW_H
