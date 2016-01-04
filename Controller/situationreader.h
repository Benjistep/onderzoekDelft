#ifndef SITUATIONREADER_H
#define SITUATIONREADER_H

#include <QString>
#include "../Situations/situation.h"

class SituationReader
{
public:
    static std::vector<Situation*>* Read(QString path);
};

#endif // SITUATIONREADER_H
