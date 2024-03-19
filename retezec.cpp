//
// Created by babi on 14.3.2024.
//

#include "retezec.h"

#include <iomanip>


retezec::retezec() {
    this->charArray = new char[1];
    this->charArray[0] = '\0';
}

retezec::retezec(const retezec &ciziObjekt) {
    kopirujObjekt(ciziObjekt);
}

retezec::retezec(const char *ciziChar) {
    kopirujChar(ciziChar);
}

retezec::~retezec() {
    delete[]this->charArray;
    this->charArray = nullptr;
}

ostream &operator<<(ostream &os, const retezec &ciziObjekt) {
    os << std::setw(3) << ciziObjekt.delka() << " || ";
    for (int i = 0; i < ciziObjekt.delka(); ++i) {
        os << ciziObjekt[i];
    }
    os << std::endl;
    return os;
}


unsigned int retezec::charLength(const char *&ciziRetezec) {
    int i;
    for (i = 0; ciziRetezec[i] != '\0'; ++i);
    return i;
}

char &retezec::operator[](unsigned int index) {
    if (index >= 0 && index < this->delka()) {
        return this->charArray[index];
    }
    throw "Index out of bound";
}

unsigned int retezec::delka() const {
    int i;
    for (i = 0; this->charArray[i] != '\0'; ++i);
    return i;
}

char retezec::operator[](unsigned int index) const {
    if (index >= 0 && index < this->delka()) {
        return this->charArray[index];
    }
    throw "Index out of bound";
}

void retezec::set(const char *ciziChar) {
    delete[]this->charArray;
    kopirujChar(ciziChar);
}

retezec &retezec::operator=(const retezec &ciziObjekt) {
    if (this != &ciziObjekt) {
        delete[]this->charArray;
        kopirujObjekt(ciziObjekt);
    }
    return *this;
}

void retezec::kopirujObjekt(const retezec &ciziObjekt) {
    try {
        // vytvoreni pole
        this->charArray = new char[ciziObjekt.delka()];
        // naplneni nove vytvoreneho pole prichazejicim objektem
        for (int i = 0; i < ciziObjekt.delka(); ++i) {
            this->charArray[i] = ciziObjekt[i];
        }
        // binarni nula na konec
        this->charArray[ciziObjekt.delka()] = '\0';
    }
    catch (std::bad_alloc &ba) {
        std::cout << "bad_alloc caught: " << ba.what() << '\n';
    }
}

void retezec::kopirujChar(const char *ciziRetezec) {
    try {
        // vytvoreni pole o jedno vetsi nez je prichazejici string
        this->charArray = new char[charLength(ciziRetezec) + 1];
        // naplneni nove vytvoreneho pole prichazejicim stringem
        for (int i = 0; i <= charLength(ciziRetezec); ++i) {
            this->charArray[i] = ciziRetezec[i];
        }
        // prirazeni binarni nuly do bonusoveho mista
        this->charArray[charLength(ciziRetezec) + 1] = '\0';
    }
    catch (std::bad_alloc &ba) {
        std::cout << "bad_alloc caught: " << ba.what() << '\n';
    }
}

bool retezec::operator==(const retezec &ciziObjekt) const {
    if (this->delka() != ciziObjekt.delka()) {
        return false;
    }
    for (int i = 0; i < ciziObjekt.delka(); ++i) {
        if (this->charArray[i] != ciziObjekt[i]) {
            return false;
        }
    }
    return true;
}

retezec retezec::operator+(const retezec &ciziPole) const {
    retezec kopie(*this);
    kopie += ciziPole;
    return kopie;
}

retezec &retezec::operator+=(const retezec &ciziObjekt) {
    try {
        // docasne pole o velikosti tohoto a ciziho pole, do ktereho se ulozi data obou poli
        char *tmp = new char[this->delka() + ciziObjekt.delka() + 1];
        // scitani obou poli do docasneho pole
        for (int i = 0; i < this->delka(); ++i) {
            tmp[i] = this->charArray[i];
        }

        for (int i = this->delka(); i < this->delka() + ciziObjekt.delka(); ++i) {
            tmp[i] = ciziObjekt[i - this->delka()];
        }
        // binarni nula na konec
        tmp[this->delka() + ciziObjekt.delka() + 1] = '\0';
        // smazani stareho pole a nahrazeni ho docasnym sectenym polem
        delete[]this->charArray;
        this->charArray = tmp;
        // smazani docasneho pole
        delete[]tmp;
    }
    catch (std::bad_alloc &ba) {
        std::cout << "bad_alloc caught: " << ba.what() << '\n';
    }
    return *this;
}
