//
// Created by babi on 14.3.2024.
//

#ifndef RETEZEC_RETEZEC_H
#define RETEZEC_RETEZEC_H

#include <iostream>

using std::ostream;

class retezec {
public:
    retezec();

    retezec(const retezec &);

    retezec(const char *);

    ~retezec();

    unsigned int delka() const;

    void set(const char *);

    friend ostream &operator<<(ostream &, const retezec &);

    bool operator==(const retezec &) const;

    retezec &operator=(const retezec &);

    char &operator[](unsigned int);

    char operator[](unsigned int) const;

    retezec &operator+=(const retezec &);

    retezec operator+(const retezec &) const;

private:
    char *charArray;

    unsigned int charLength(const char * &);

    void kopirujObjekt(const retezec &);

    void kopirujChar(const char *);
};


#endif //RETEZEC_RETEZEC_H
