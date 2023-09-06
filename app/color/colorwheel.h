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

    void createImages(QSizeF size);
    void createWheel();
    void createTriangle();
    void setColorFromPos(QPointF pos);

private:
    bool m_IsDragging = false;
    int mM_argin = 4;
    int m_WheelThickness = 18;
    ControlPart m_ClickedPart = ColorWheel::None;
    QImage m_WheelImage;
    QImage m_TriangleImage;
    QImage m_WidgetImage;
    bool m_WheelDirty = true;
    bool m_TriangleDirty = true;
    QBrush m_WheelBrush;
};


#endif//COLORWHEEL_H