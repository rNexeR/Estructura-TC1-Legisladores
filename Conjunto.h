#ifndef CONJUNTO_H
#define CONJUNTO_H
#include "Legislador.h"

class Conjunto
{
public:
    Conjunto();
    ~Conjunto();
    bool insertar(int name);
    void suprimir(int name);
    bool esMiembro(int name);
    Legislador* getPos(int pos);
    Legislador* search(int name);
    Legislador* inicio;

};

#endif // CONJUNTO_H
