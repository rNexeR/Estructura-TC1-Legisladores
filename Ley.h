#ifndef LEY_H
#define LEY_H
#include <QString>

class Ley
{
public:
    Ley();
    Ley(QString d, bool buena);
    ~Ley();
    QString descripcion;
    bool buena;
};

#endif // LEY_H
