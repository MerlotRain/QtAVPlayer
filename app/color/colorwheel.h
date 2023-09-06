#ifndef COLORWHEEL_H
#define COLORWHEEL_H

#include "colorwidget.h"

class ColorWheel : public ColorWidget
{
    Q_OBJECT

public:
    explicit ColorWheel(QWidget *parent = nullptr);
    ~ColorWheel() override;

    QSize sizeHint() const override;
    void paintEvent(QPaintEvent *event) override;

public slots:
    void setColor(const QColor &color, bool emitSignals = false) override;

protected:
    void resizeEvent(QResizeEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    enum ControlPart
    {
        None,
        Wheel,
        Triangle
    };
};


#endif//COLORWHEEL_H