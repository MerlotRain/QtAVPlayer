#ifndef FONTBAR_H
#define FONTBAR_H

#include <QFont>
#include <QFrame>

class FontBar : public QFrame
{
    Q_OBJECT
public:
    explicit FontBar(QFont f, QWidget *parent = nullptr);
    ~FontBar() override;

signals:
    void fontChange(QFont f);

private slots:
    void onFontFamilyChange(const QString &family);
    void onFontSizeChange(int size);
    void onBoldChange(bool b);
    void onItalicChange(bool b);
    void onUnderLineChange(bool b);
    void onStrikeOutChange(bool b);
    void onAlignChange(Qt::AlignmentFlag algn);
    void onFullBackgroundChange(bool b);

private:
    QFont m_f;
};

#endif//FONTBAR_H