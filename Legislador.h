#ifndef LEGISLADOR_H
#define LEGISLADOR_H
#include <iostream>
using namespace std;
#include <QString>
#include "Ley.h"

class Legislador
{
public:
    Legislador();
    Legislador(int name);
    void evaluar(Ley ev);

    ~Legislador();
    int nombre;
    Legislador* sig;

};

#endif // LEGISLADOR_H
