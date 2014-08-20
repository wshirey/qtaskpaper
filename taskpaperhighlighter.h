#ifndef TASKPAPERHIGHLIGHTER_H
#define TASKPAPERHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class TaskPaperHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    TaskPaperHighlighter(QTextDocument *document = 0);

signals:

public slots:
private:
    struct HighlightingRule {
        QString pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;
    QTextCharFormat projectFormat;
    QTextCharFormat tagFormat;
    QTextCharFormat listFormat;

    // QSyntaxHighlighter interface
protected:
    void highlightBlock(const QString &text);
};

#endif // TASKPAPERHIGHLIGHTER_H
