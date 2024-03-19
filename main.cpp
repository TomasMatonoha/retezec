#include <iostream>

#include "retezec.h"

using std::endl;

int main() {
    retezec obj1;
    std::cout << "Objekt vytvoren vychozim konstruktorem" << endl << obj1;
    retezec objParam1("Text"), objParam2("String");
    std::cout << "Objekt vytvoren konstruktorem s parametrem" << endl << objParam1 << objParam2;
    retezec objKopie(objParam1);
    std::cout << "Objekt vytvoren kopirovacim konstruktorem" << endl << objKopie << endl;
    objParam2 = objParam1;
    std::cout << "Prirazeni (objParam2 = objParam1)" << endl << objParam1 << objParam2 << endl;
    objKopie = objParam1 + objParam2;
    std::cout << "Secteni (objKopie = objParam1 + objParam2)" << endl << objParam1 << objParam2 << objKopie << endl;
    objParam1 += objParam2 + objKopie;
    std::cout << "Pricteni (objParam1 += objParam2 + objKopie" << endl << objParam1 << objParam2 << objKopie << endl;
    return 0;
}
