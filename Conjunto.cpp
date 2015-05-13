#include "Conjunto.h"

Conjunto::Conjunto()
{
    inicio = NULL;
}

bool Conjunto::insertar(int name){
    if (!inicio){
        cout<<"agregando inicio"<<endl;
        inicio = new Legislador(name);
        return true;
    }
    Legislador* actual = inicio;
    if (name < inicio->nombre){
        inicio = new Legislador(name);
        inicio->sig = actual;
        return true;
    }
    while(true){
        if(name == actual->nombre)
            return false;
        if (actual->sig && name > actual->sig->nombre)
            actual = actual->sig;
        if(!actual->sig)
            break;
        if (name < actual->sig->nombre)
            break;
    }
    if (actual){
        Legislador* temp = actual->sig;
        actual->sig = new Legislador(name);
        actual->sig->sig = temp;
        cout<<"Agregado despues de: "<<actual->nombre<<endl;
    }
    return true;
}

/*bool Conjunto::suprimir(int pos){
    Legislador* eliminar = getPos(pos-1);
    if (!eliminar)
        return false;
    Legislador* temp = eliminar->sig;
    eliminar->sig = temp->sig;
    delete temp;
    return true;
}*/

void Conjunto::suprimir(int name){
    Legislador* actual = inicio;
    Legislador*temp;
    if (inicio->nombre == name){
        temp = inicio;
        inicio = inicio->sig;
        delete temp;
        return;
    }
    while(actual && actual->sig->nombre != name){
        actual = actual->sig;
    }
    if(actual){
        temp = actual->sig;
        actual->sig = temp->sig;
        delete temp;
    }
}

bool Conjunto::esMiembro(int name){
    Legislador* actual = inicio;
    while(actual){
        cout<<name<<" , "<<actual->nombre<<endl;
        if (actual->nombre == name)
            return true;
        actual = actual->sig;
    }
    return false;
}

Legislador* Conjunto::getPos(int pos){
    Legislador* actual = inicio;
    int x = 0;
    while(actual && x <= pos){
        actual = actual->sig;
    }
    return actual;
}

Legislador* Conjunto::search(int name){
    Legislador* actual = inicio;
    while(actual && actual->nombre != name){
        actual = actual->sig;
    }
    return actual;
}

Conjunto::~Conjunto()
{

}

