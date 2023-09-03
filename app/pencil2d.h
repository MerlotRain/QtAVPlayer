#ifndef PENCIL2D_H
#define PENCIL2D_H

#include <QApplication>
#include <memory>

class MainWindow2;
class QLockFile;

#define pencil2D \
static_cast<Pencil2D *>(QCoreApplication::instance())

class Pencil2D : public QApplication
{
    Q_OBJECT

    explicit Pencil2D(int& argc, char** argv);
    ~Pencil2D() override;
};

#endif//PENCIL2D_H