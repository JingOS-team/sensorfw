/**
   @file orientationsensor_i.h
   @brief Interface for OrientationSensor

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

#ifndef ORIENTATIONSENSOR_I_H
#define ORIENTATIONSENSOR_I_H

#include <QtDBus/QtDBus>

#include <datatypes/unsigned.h>
#include "abstractsensor_i.h"

/**
 * Client interface for listening device orientation changes.
 */
class OrientationSensorChannelInterface : public AbstractSensorChannelInterface
{
    Q_OBJECT
    Q_DISABLE_COPY(OrientationSensorChannelInterface)
    Q_PROPERTY(Unsigned orientation READ orientation)
    Q_PROPERTY(int threshold READ threshold WRITE setThreshold)

public:
    /**
     * Name of the D-Bus interface for this class.
     */
    static const char* staticInterfaceName;

    /**
     * Create new instance of the class.
     *
     * @param id Sensor ID.
     * @param sessionId Session ID.
     * @return Pointer to new instance of the class.
     */
    static AbstractSensorChannelInterface* factoryMethod(const QString& id, int sessionId);

    /**
     * Get latest orientation reading from sensor daemon.
     *
     * @return Current device orientation. The given integer
     *         value is enumeration from #PoseData::Orientation.
     */
    Unsigned orientation();

    /**
     * Gets the currently used threshold value. Value is in mG.
     *
     * @return Current threshold value.
     * @deprecated Not used.
     */
    int threshold();

    /**
     * Sets the currently used threshold value. Value is in mG.
     *
     * @param value threshold value.
     * @deprecated Not used.
     */
    void setThreshold(int value);

    /**
     * Constructor.
     *
     * @param path      path.
     * @param sessionId session ID.
     */
    OrientationSensorChannelInterface(const QString& path, int sessionId);

    /**
     * Request a listening interface to the sensor.
     *
     * @param id sensor ID.
     * @return Pointer to interface, or NULL on failure.
     * @deprecated use interface(const QString&) instead.
     */
    static const OrientationSensorChannelInterface* listenInterface(const QString& id);

    /**
     * Request a control interface to the sensor.
     *
     * @param id sensor ID.
     * @return Pointer to interface, or NULL on failure.
     * @deprecated use interface(const QString&) instead.
     */
    static OrientationSensorChannelInterface* controlInterface(const QString& id);

    /**
     * Request an interface to the sensor.
     *
     * @param id sensor ID.
     * @return Pointer to interface, or NULL on failure.
     */
    static OrientationSensorChannelInterface* interface(const QString& id);

protected:
    virtual bool dataReceivedImpl();

Q_SIGNALS:
    /**
     * Sent when device orientation has changed.
     *
     * @param orientation Current device orientation. The given integer
     *                    value is enumeration from #PoseData::Orientation.
     */
    void orientationChanged(const Unsigned& orientation);
};

namespace local {
  typedef ::OrientationSensorChannelInterface OrientationSensor;
}

#endif /* ORIENTATIONSENSOR_I_H */
