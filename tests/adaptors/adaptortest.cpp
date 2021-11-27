/**
   @file adaptortest.cpp
   @brief Automatic tests for adaptors

   <p>
   Copyright (C) 2009-2010 Nokia Corporation

   @author Timo Rongas <ext-timo.2.rongas@nokia.com>
   @author Ustun Ergenoglu <ext-ustun.ergenoglu@nokia.com>
   @author Matias Muhonen <ext-matias.muhonen@nokia.com>

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

#include <QtDebug>
#include <QTest>
#include <QVariant>

#include "adaptortest.h"

#include "accelerometeradaptor.h"
#include "magnetometeradaptor.h"
#include "alsadaptor.h"
#include "touchadaptor.h"
#include "tapadaptor.h"
#include "kbslideradaptor.h"
#include "proximityadaptor.h"
#include "gyroscopeadaptor.h"
#include "lidsensoradaptor-evdev.h"

#include "config.h"

void AdaptorTest::initTestCase()
{
    SensorFrameworkConfig::loadConfig("/etc/sensorfw/sensord.conf", "/etc/sensorfw/sensord.conf.d");
}

void AdaptorTest::init() {}

void AdaptorTest::cleanup() {}
void AdaptorTest::cleanupTestCase() {}

void AdaptorTest::testAccelerometerAdaptor()
{
    QString sensorName("accelerometer");
    AccelerometerAdaptor* adaptor = dynamic_cast<AccelerometerAdaptor*>(AccelerometerAdaptor::factoryMethod("accelerometeradaptor"));
    QVERIFY( adaptor );

    QVERIFY(adaptor->startAdaptor());
    QVERIFY(adaptor->startSensor());

    adaptor->stopSensor();
    adaptor->stopAdaptor();
}

void AdaptorTest::testMagnetometerAdaptor()
{
    QString sensorName("magnetometer");
    MagnetometerAdaptor* adaptor = dynamic_cast<MagnetometerAdaptor*>(MagnetometerAdaptor::factoryMethod("magnetometeradaptor"));
    QVERIFY( adaptor );

    QVERIFY(adaptor->startAdaptor());
    QVERIFY(adaptor->startSensor());

    adaptor->stopSensor();
    adaptor->stopAdaptor();
}


void AdaptorTest::testALSAdaptor()
{
    QString sensorName("als");
    ALSAdaptor* adaptor = dynamic_cast<ALSAdaptor*>(ALSAdaptor::factoryMethod("alsadaptor"));
    QVERIFY( adaptor );

    QVERIFY(adaptor->startAdaptor());
    QVERIFY(adaptor->startSensor());

    adaptor->stopSensor();
    adaptor->stopAdaptor();
}

void AdaptorTest::testTapAdaptor()
{
    QString sensorName("tap");
    TapAdaptor* adaptor = dynamic_cast<TapAdaptor*>(TapAdaptor::factoryMethod("tapadaptor"));
    QVERIFY( adaptor );

    QVERIFY(adaptor->startAdaptor());
    QVERIFY(adaptor->startSensor());

    adaptor->stopSensor();
    adaptor->stopAdaptor();
}

void AdaptorTest::testTouchAdaptor()
{
    QString sensorName("touch");
    TouchAdaptor* adaptor = dynamic_cast<TouchAdaptor*>(TouchAdaptor::factoryMethod("touchadaptor"));
    QVERIFY( adaptor );

    QVERIFY(adaptor->startAdaptor());
    QVERIFY(adaptor->startSensor());

    adaptor->stopSensor();
    adaptor->stopAdaptor();
}

void AdaptorTest::testKeyboardSliderAdaptor()
{
    QString sensorName("keyboardslider");
    KeyboardSliderAdaptor* adaptor = dynamic_cast<KeyboardSliderAdaptor*>(KeyboardSliderAdaptor::factoryMethod("kbslideradaptor"));
    QVERIFY( adaptor );

    QVERIFY(adaptor->startAdaptor());
    QVERIFY(adaptor->startSensor());

    adaptor->stopSensor();
    adaptor->stopAdaptor();
}

void AdaptorTest::testProximityAdaptor()
{
    QString sensorName("proximity");
    ProximityAdaptor* adaptor = dynamic_cast<ProximityAdaptor*>(ProximityAdaptor::factoryMethod("proximityadaptor"));
    QVERIFY( adaptor );

    QVERIFY(adaptor->startAdaptor());
    QVERIFY(adaptor->startSensor());

    adaptor->stopSensor();
    adaptor->stopAdaptor();
}

void AdaptorTest::testGyroscopeAdaptor()
{
    GyroscopeAdaptor* adaptor = dynamic_cast<GyroscopeAdaptor*>(GyroscopeAdaptor::factoryMethod("gyroscopeadaptor"));
    QVERIFY( adaptor );

    QVERIFY(adaptor->startAdaptor());
    QVERIFY(adaptor->startSensor());

    adaptor->stopSensor();
    adaptor->stopAdaptor();
}

void AdaptorTest::testLidSensorAdaptor()
{
    LidSensorAdaptorEvdev* adaptor =
            dynamic_cast<LidSensorAdaptorEvdev*>(LidSensorAdaptorEvdev::factoryMethod("lidsensoradaptor"));
    QVERIFY( adaptor );

    QVERIFY(adaptor->startAdaptor());
    QVERIFY(adaptor->startSensor());

    adaptor->stopSensor();
    adaptor->stopAdaptor();
}

QTEST_MAIN(AdaptorTest)
