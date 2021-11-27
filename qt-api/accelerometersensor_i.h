/**
   @file accelerometersensor_i.h
   @brief Interface for AccelerometerSensor

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

#ifndef ACCELEROMETERSENSOR_I_H
#define ACCELEROMETERSENSOR_I_H

#include <QtDBus/QtDBus>
#include <QVector>
#include "abstractsensor_i.h"
#include <datatypes/xyz.h>

/**
 * Client interface for accessing accelerometer sensor.
 */
class AccelerometerSensorChannelInterface : public AbstractSensorChannelInterface
{
    Q_OBJECT
    Q_DISABLE_COPY(AccelerometerSensorChannelInterface)
    Q_PROPERTY(XYZ value READ get)

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
     * Get latest accelerometer reading from sensor daemon.
     *
     * @return accelerometer reading.
     */
    XYZ get();

    /**
     * Constructor.
     *
     * @param path      path.
     * @param sessionId session ID.
     */
    AccelerometerSensorChannelInterface(const QString& path, int sessionId);

    /**
     * Request a listening interface to the sensor.
     *
     * @param id sensor ID.
     * @return Pointer to interface, or NULL on failure.
     * @deprecated use interface(const QString&) instead.
     */
    static const AccelerometerSensorChannelInterface* listenInterface(const QString& id);

    /**
     * Request a control interface to the sensor.
     *
     * @param id sensor ID.
     * @return Pointer to interface, or NULL on failure.
     * @deprecated use interface(const QString&) instead.
     */
    static AccelerometerSensorChannelInterface* controlInterface(const QString& id);

    /**
     * Request an interface to the sensor.
     *
     * @param id sensor ID.
     * @return Pointer to interface, or NULL on failure.
     */
    static AccelerometerSensorChannelInterface* interface(const QString& id);

protected:

    virtual void connectNotify(const QMetaMethod & signal);
    virtual bool dataReceivedImpl();

private:
    bool frameAvailableConnected; /**< has applicaiton connected slot for frameAvailable signal. */

Q_SIGNALS:
    /**
     * Sent when new measurement data has become available.
     *
     * @param data New measurement data.
     */
    void dataAvailable(const XYZ& data);

    /**
     * Sent when new measurement frame has become available.
     * If app doesn't connect to this signal content of frames
     * will be sent through dataAvailable signal.
     *
     * @param frame New measurement frame.
     */
    void frameAvailable(const QVector<XYZ>& frame);
};

namespace local {
  typedef ::AccelerometerSensorChannelInterface AccelerometerSensor;
}

#endif
