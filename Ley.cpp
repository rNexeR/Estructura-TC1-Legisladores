#include "Ley.h"

Ley::Ley()
{
    descripcion = "";
    buena = false;
}

Ley::Ley(QString d,bool buena){
    descripcion =d;
    this->buena = buena;
}

Ley::~Ley()
{

}

