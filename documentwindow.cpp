#include "documentwindow.h"
#include "ui_documentwindow.h"

DocumentWindow::DocumentWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DocumentWindow)
{
    ui->setupUi(this);
    highlighter = new TaskPaperHighlighter(ui->textEdit->document());
}

DocumentWindow::~DocumentWindow()
{
    delete ui;
    delete highlighter;
}

void DocumentWindow::on_action_New_triggered()
{
    DocumentWindow *w = new DocumentWindow();
    w->show();
}
