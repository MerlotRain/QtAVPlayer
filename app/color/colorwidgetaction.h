#ifndef COLORWIDGETACTION_H
#define COLORWIDGETACTION_H

#include "colorwidget.h"
#include <QWidgetAction>

class ColorWidgetAction : public QWidgetAction
{
    Q_OBJECT

public:
    explicit ColorWidgetAction(ColorWidget *colorWidget, QMenu *menu = nullptr,
                               QWidget *parent = nullptr);

                               
};

#endif//COLORWIDGETACTION_H