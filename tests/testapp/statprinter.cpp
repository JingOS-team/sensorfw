/**
   @file statprinter.cpp
   @brief sensor statistics printer
   <p>
   Copyright (C) 2011 Nokia Corporation

   @author Antti Virtanen <antti.i.virtanen@nokia.com>

   This file is part of Sensord.

   Sensord is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License
   version 2.1 as published by the Free Software Foundation.

   Sensord is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with Sensord.  If not, see <http://www.gnu.org/licenses/>.
   </p>
*/

#include "statprinter.h"

#include <QList>
#include <QMap>
#include <QString>
#include <QDebug>

StatPrinter::StatPrinter(QList<AbstractSensorHandler*> handlers, int interval, QObject *parent) :
    QObject(parent),
    handlers(handlers),
    first(true)
{
    startTimer(interval);
}

void StatPrinter::timerEvent(QTimerEvent*)
{
    QMap<QString, int> summary;
    foreach(AbstractSensorHandler* handler, handlers)
    {
        summary[handler->sensorName()] += handler->dataCount();
    }

    QString prefixLine, dataLine;
    foreach(QString key, summary.keys())
    {
        if (first)
        {
            prefixLine.append(key);
            prefixLine.append('\t');
        }

        dataLine.append(QString::number(summary[key]));

        dataLine.append('\t');
    }

    if(first)
    {
        qDebug()<< prefixLine.trimmed();
        first = false;
    }
    qDebug() << dataLine.trimmed();
}
