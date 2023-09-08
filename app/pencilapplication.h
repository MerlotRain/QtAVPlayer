#ifndef PENCILAPPLICATION_H
#define PENCILAPPLICATION_H

#include "mainwindow.h"
#include <QApplication>

#ifdef pApp
    #undef pApp
#endif

#define pApp (qobject_cast<PencilApplication *>(QCoreApplication::instance()))

class PencilApplication : public QApplication
{
    Q_OBJECT
public:
    explicit PencilApplication(int &argc, char **argv);
    ~PencilApplication() override;

    bool event(QEvent *event) override;

    static MainWindow2 *newWindow();

private:
    QList<MainWindow2 *> m_lastActiveWindows;
};

#endif//PENCILAPPLICATION_H