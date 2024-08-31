#include "qtav.h"
#include <qavaudiooutput.h>
#include <qavplayer.h>

QtAV::QtAV(QWidget *parent) : QMainWindow(parent)
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    mVR = new QVideoRendererControl(this);
    QMedit

            VideoWidget w;
    w.show();

    MediaObject mo(&vr);
    w.setMediaObject(&mo);
#else
    mVideoWidget = new QVideoWidget(this);
#endif
    setCentralWidget(mVideoWidget);
    mAVPlayer = new QAVPlayer(this);

    QAVAudioOutput audioOutput;
    connect(
            mAVPlayer, &QAVPlayer::audioFrame, &audioOutput,
            [&audioOutput](const QAVAudioFrame &frame) {
                audioOutput.play(frame);
            },
            Qt::DirectConnection);

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    connect(
            mAVPlayer, &QAVPlayer::videoFrame, &p,
            [&](const QAVVideoFrame &frame) {
                if (vr.m_surface == nullptr)
                    return;
                QVideoFrame videoFrame = frame.convertTo(AV_PIX_FMT_RGB32);
                if (!vr.m_surface->isActive() ||
                    vr.m_surface->surfaceFormat().frameSize() != videoFrame.size())
                {
                    QVideoSurfaceFormat f(videoFrame.size(), videoFrame.pixelFormat(),
                                          videoFrame.handleType());
                    vr.m_surface->start(f);
                }
                if (vr.m_surface->isActive())
                    vr.m_surface->present(videoFrame);
            },
            Qt::DirectConnection);
#else
    connect(
            mAVPlayer, &QAVPlayer::videoFrame, mAVPlayer,
            [&](const QAVVideoFrame &frame) {
                QVideoFrame videoFrame = frame;
                mVideoWidget->videoSink()->setVideoFrame(videoFrame);
            },
            Qt::DirectConnection);
#endif

    QObject::connect(mAVPlayer, &QAVPlayer::mediaStatusChanged, [&](auto status) {
        qDebug() << "mediaStatusChanged" << status << mAVPlayer->state();
        if (status == QAVPlayer::LoadedMedia)
        {
            qDebug() << "Video streams:" << mAVPlayer->currentVideoStreams().size();
            for (const auto &s: mAVPlayer->currentVideoStreams())
                qDebug() << "[" << s.index() << "]" << s.metadata() << s.framesCount() << "frames,"
                         << s.frameRate() << "frame rate";
            qDebug() << "Audio streams:" << mAVPlayer->currentAudioStreams().size();
            for (const auto &s: mAVPlayer->currentAudioStreams())
                qDebug() << "[" << s.index() << "]" << s.metadata() << s.framesCount() << "frames,"
                         << s.frameRate() << "frame rate";
        }
        else if (status == QAVPlayer::EndOfMedia)
        {
            audioOutput.stop();
        }
    });
}

QtAV::~QtAV()
{
}
