#include "taskpaperhighlighter.h"

TaskPaperHighlighter::TaskPaperHighlighter(QTextDocument *document) :
    QSyntaxHighlighter(document)
{
    HighlightingRule projectRule;
    projectRule.pattern = "^\\s*\\S*:\\s*$";
    projectFormat.setFontWeight(QFont::Bold);
    projectFormat.setForeground(Qt::black);
    projectRule.format = projectFormat;
    highlightingRules.append(projectRule);


    HighlightingRule listRule;
    listRule.pattern = "^- .*$";
    listFormat.setFontWeight(QFont::Bold);
    listRule.format = listFormat;
    highlightingRules.append(listRule);


    HighlightingRule tagRule;
    tagRule.pattern = "\\s@\\S*\\b";
    tagFormat.setForeground(Qt::lightGray);
    tagRule.format = tagFormat;
    highlightingRules.append(tagRule);

}


void TaskPaperHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules)
    {
        QRegExp expression(rule.pattern);
        int index = text.indexOf(expression);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = text.indexOf(expression, index + length);
        }
    }
}
