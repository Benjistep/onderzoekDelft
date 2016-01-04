#include "situationreader.h"
#include <QtXml>
#include <iostream>
#include "../Situations/Settings/co2setting.h"
#include "../Situations/Settings/airflowsetting.h"
#include "../Situations/Settings/lightsetting.h"
#include "../Situations/Settings/pirsetting.h"
#include "../Situations/Settings/temperaturesetting.h"

std::vector<QDomElement> ListElements(QDomElement root, QString tagname)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    std::vector<QDomElement> elements;
    for (int i = 0; i < items.count(); i++)
    {
        QDomNode itemnode = items.at(i);

        //convert to element
        if(itemnode.isElement())
        {
            QDomElement itemEl = itemnode.toElement();
                elements.push_back(itemEl);
        }
    }
    return elements;
}

bool ToBool(QString string)
{
   if(string == "true" || string == "TRUE")
        return true;

   return false;
}

Situation* ElementToSituation(QDomElement root)
{
    Situation* situation = new Situation(root.attribute("name", "new Situation"));

    std::vector<QDomElement> settings = ListElements(root, "setting");

    for (unsigned int i = 0; i < settings.size(); i++)
    {
        QString type = settings[i].attribute("type", "");
        if(type != "")
        {
            if(type == "CO2Sensor")
            {
                int maxAcceptableC02 = settings[i].attribute("maxAcceptable", "1400").toInt();
                int deviationC02 = settings[i].attribute("maxDeviation", "400").toInt();
                bool C02maxAcceptViolated = ToBool(QString(settings[i].attribute("maxAcceptableViolated", "false")));
                bool C02devViolated = ToBool(QString(settings[i].attribute("maxDeviationViolated", "false")));
                bool C02notNull = ToBool(QString(settings[i].attribute("isFunctioning", "false")));
                bool C02const = ToBool(QString(settings[i].attribute("hasConstantValue", "false")));
                CO2Setting* co2Setting = new CO2Setting(maxAcceptableC02, deviationC02, C02maxAcceptViolated, C02devViolated, C02notNull, C02const);
                QString name = "CO2Sensor";
                situation->addSetting(co2Setting, name);
            }
            else if(type == "Temperature")
            {
                int maxTemperature = settings[i].attribute("maxAcceptable", "22").toInt();
                bool maxTempViolated = ToBool(QString(settings[i].attribute("maxAcceptableViolated", "false")));
                bool tempNotNull = ToBool(QString(settings[i].attribute("isFunctioning", "false")));
                TemperatureSetting* temperatureSetting = new TemperatureSetting(maxTemperature, maxTempViolated, tempNotNull);
                QString settingName = "Temperature";
                situation->addSetting(temperatureSetting, settingName);
            }
            else if(type == "Airflow")
            {
                int maxAirflowDev = settings[i].attribute("maxDeviation", "50").toInt();
                bool maxAirflowDevV = ToBool(QString(settings[i].attribute("maxDeviationViolated", "false")));
                bool airflowNotNull = ToBool(QString(settings[i].attribute("isFunctioning", "false")));
                AirflowSetting* airflowSetting = new AirflowSetting(maxAirflowDev, maxAirflowDevV, airflowNotNull);
                QString settingName = "Airflow";
                situation->addSetting(airflowSetting, settingName);
            }
            else if(type == "Lightstate")
            {
                bool lightsOn = ToBool(QString(settings[i].attribute("isFunctioning", "false")));
                LightSetting* lightSetting = new LightSetting(lightsOn);
                QString settingName = "Lightstate";
                situation->addSetting(lightSetting, settingName);
            }
            else if(type == "PIRSensor")
            {
                bool pirOn = ToBool(QString(settings[i].attribute("isFunctioning", "false")));
                PIRSetting* pirSetting = new PIRSetting(pirOn);
                QString settingName = "PIRSensor";
                situation->addSetting(pirSetting, settingName);
            }
        }
    }

    return situation;
}

std::vector<Situation*>* SituationReader::Read(QString path)
{
    std::vector<Situation*>* situations = NULL;

    QDomDocument document;
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << "Failed to open file";
        return situations;
    }
    else if(!document.setContent(&file))
    {
        std::cout << "failed to load document";
        return situations;
    }

    //get root element
    QDomElement root = document.firstChildElement();

    if(root.tagName() == "situations")
    {
       //create space on heap
       situations = new std::vector<Situation*>();
       //list all elements which are situation elements
       std::vector<QDomElement> elements = ListElements(root, "situation");
       //convert all elements to situation
       for (unsigned int i = 0; i < elements.size(); i++)
       {
           QDomElement tempEl = elements[i];
           situations->push_back(ElementToSituation(tempEl));
       }
    }

    return situations;
}
