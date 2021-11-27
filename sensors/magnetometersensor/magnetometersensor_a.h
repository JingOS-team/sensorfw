/**
   @file magnetometersensor_a.h
   @brief D-Bus adaptor for MagnetometerSensor

   <p>
   Copyright (C) 2009-2010 Nokia Corporation

   @author Timo Rongas <ext-timo.2.rongas@nokia.com>
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

#ifndef MAGNETOMETER_SENSOR_H
#define MAGNETOMETER_SENSOR_H

#include <QtDBus/QtDBus>

#include "datatypes/magneticfield.h"
#include "abstractsensor_a.h"

class MagnetometerSensorChannelAdaptor : public AbstractSensorChannelAdaptor
{
    Q_OBJECT
    Q_DISABLE_COPY(MagnetometerSensorChannelAdaptor)
    Q_CLASSINFO("D-Bus Interface", "local.MagnetometerSensor")
    Q_PROPERTY(MagneticField magneticField READ magneticField)

public:
    MagnetometerSensorChannelAdaptor(QObject* parent);

public Q_SLOTS:
    void reset();
    MagneticField magneticField() const;

Q_SIGNALS:
    void dataAvailable(const MagneticField& data);
};

#endif
