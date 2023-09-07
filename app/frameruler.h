#ifndef FRAMERULER_H
#define FRAMERULER_H

#include <QWidget>

class FrameRuler : public QWidget
{
    Q_OBJECT

public:
    explicit FrameRuler(QWidget *parent = nullptr, Qt::Orientation orientation = Qt::Horizontal);
    ~FrameRuler() override;

    QSize minimumSizeHint() const override;

    void setSceneTransform(const QTransform &transfrom);
};

#endif//FRAMERULER_H