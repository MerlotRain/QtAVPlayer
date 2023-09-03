#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <QPoint>
#include <QtMath>

namespace MathUtils {

inline qreal getDifferenceAngle(const QPointF &a, const QPointF &b)
{
    return qAtan2(b.y() - a.y(), b.x() - a.x());
}

}// namespace MathUtils

#endif//MATHUTILS_H