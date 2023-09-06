#ifndef COLORDIALOG_H
#define COLORDIALOG_H

#include <QAbstractButton>
#include <QDialog>

class ColorDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ColorDialog(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags(),
                         const QColor &color = QColor());
    QColor color() const;
    void setAllowOpacity(bool allowOpacity);
    static QColor getColor(const QColor &initColor, QWidget *parent, bool allowOpacity = false);

signals:
    void currentColorChanged(const QColor &color);

public slots:
    void setColor(const QColor &color);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void onOk();
    void onCancel();
    void onButtonClicked(QAbstractButton *button);
    void discardColor();

private:
    QColor m_previous;
    bool m_allowOpacity = true;
};

#endif//COLORDIALOG_H