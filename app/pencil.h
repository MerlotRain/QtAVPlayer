#ifndef PENCIL_H
#define PENCIL_H

#include <QApplication>

class Pencil2D : public QApplication
{
    Q_OBJECT
public:
    explicit Pencil2D(int argc, char **argv);
    ~Pencil2D() override;
    
};

#endif//PENCIL_H