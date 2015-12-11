#ifndef SITUATION_H
#define SITUATION_H

#include <QString>
#include <map>
#include "Settings/setting.h"

class Situation
{
private:
    QString name;
    std::map<QString, Setting*> settings;

public:
    Situation(QString name);
    ~Situation();
    QString getName() const;
    void addSetting(Setting* setting, QString& name);
    Setting* getSetting(const QString& name);
    QString toString();
};

#endif // SITUATION_H
