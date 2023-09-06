#ifndef COLORWIDGET_H
#define COLORWIDGET_H

#include <QWidget>

class ColorWidget : public QWidget
{
    Q_OBJECT
public:
    enum ColorComponent
    {
        Multiple,
        Red,
        Green,
        Blue,
        Hue,
        Saturation,
        Value,
        Alpha
    };

    ColorWidget(QWidget *parent = nullptr, ColorComponent component = Multiple);

    QColor color() const;

    ColorComponent component() const;

    int componentValue() const;

    static QPixmap createDragIcon(const QColor &color);

public slots:
    virtual void setColor(const QColor &color, bool emitSignals = false);

    virtual void setComponent(ColorWidget::ColorComponent component);

    virtual void setComponentValue(int value);

signals:
    void colorChanged(const QColor &color);

    void hovered();

protected:
    int componentRange() const;
    int componentRange(ColorComponent component) const;
    int componentValue(ColorComponent component) const;
    int hue() const;
    void alterColor(QColor &color, ColorWidget::ColorComponent component, int newValue) const;

    static const QPixmap &transparentBackground();

    void dragEnterEvent(QDragEnterEvent *e) override;
    void dropEvent(QDropEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

protected:
    QColor m_CurrentColor;
    ColorComponent m_Component;
    int m_ExplicitHue = 0;
};

#endif// COLORWIDGET_H