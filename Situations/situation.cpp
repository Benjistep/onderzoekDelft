#include "situation.h"

Situation::Situation(QString name): name(name)
{

}

//possible memory leak here, no deletions
Situation::~Situation()
{
}

void Situation::addSetting(Setting* setting, QString& name)
{
    settings[name] = setting;
}

Setting* Situation::getSetting(const QString& name)
{
    if(settings.find(name) != settings.end())
        return settings[name];
    else
        return NULL;
}

QString Situation::getName() const
{
    return name;
}

QString Situation::toString()
{
    QString output = "------------------------------------------------------------- \n"
            "Situation: " + name + '\n' + "--------------------------------------\n";

    std::map<QString, Setting*>::const_iterator it = settings.begin();

    while(it != settings.end())
    {
        output += it->second->toString() + '\n';
        it++;
    }

    output += "------------------------------------------------------------- \n";

    return output;
}
