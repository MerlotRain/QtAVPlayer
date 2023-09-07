#pragma once

#include <QPolygonF>
#include <QTransform>

class Transform
{
public:
    static QRectF mapFromLocalRect(const QTransform &transform, const QRect &rect);
    static QRectF mapToWorldRect(const QTransform &transform, const QTransform &worldT,
                                 const QRect rect);

    static QPointF mapFromLocalPoint(const QTransform &transform, const QPoint &point);
    static QPointF mapToWorldPoint(const QTransform &transform, const QTransform &worldT,
                                   const QPoint &point);

    static QPolygonF mapFromLocalPolygon(const QTransform &transform, const QRect &rect);
    static QPolygonF mapToWorldPolygon(const QTransform &transform, const QTransform &worldT,
                                       const QRect &rect);
};