#ifndef QTAV_H
#define QTAV_H

#include <QApplication>
#include <QDebug>
#include <QMainWindow>
#include <QVideoWidget>
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
#include <QAbstractVideoSurface>
#include <QMediaObject>
#include <QMediaService>
#include <QVideoRendererControl>
#include <QVideoSurfaceFormat>
#else
#include <QVideoSink>
#endif

class QAVPlayer;
class QtAV : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtAV(QWidget *parent = nullptr);
    ~QtAV();

private:
    QAVPlayer *mAVPlayer;
    QVideoWidget *mVideoWidget;
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QVideoRendererControl *mVR;
#endif
};

#endif