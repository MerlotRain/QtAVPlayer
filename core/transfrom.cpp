#include "transfrom.h"

QRectF Transform::mapFromLocalRect(const QTransform &transform, const QRect &rect)
{
    return QRectF(transform.inverted().mapRect(QRectF(rect)));
}

QRectF Transform::mapToWorldRect(const QTransform &transform, const QTransform &worldT, const QRect rect)
{
    return worldT.mapRect(mapFromLocalRect(transform, rect));
}

QPointF Transform::mapFromLocalPoint(const QTransform &transform, const QPoint &point)
{
    return QPointF(transform.inverted().map(QPointF(point)));
}

QPointF Transform::mapToWorldPoint(const QTransform &transform, const QTransform &worldT,
                                   const QPoint &point)
{
    return worldT.map(mapFromLocalPoint(transform, point));
}

QPolygonF Transform::mapFromLocalPolygon(const QTransform &transform, const QRect &rect)
{
    return QPolygonF(transform.inverted().map(QPolygonF(QRectF(rect))));
}

QPolygonF Transform::mapToWorldPolygon(const QTransform &transform, const QTransform &worldT,
                                       const QRect &rect)
{
    return worldT.map(mapFromLocalPolygon(transform, rect));
}