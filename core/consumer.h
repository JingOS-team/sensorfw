/**
   @file consumer.h
   @brief Consumer

   <p>
   Copyright (C) 2009-2010 Nokia Corporation

   @author Semi Malinen <semi.malinen@nokia.com
   @author Joep van Gassel <joep.van.gassel@nokia.com>
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

#ifndef CONSUMER_H
#define CONSUMER_H

#include <QString>
#include <QHash>

class SinkBase;

/**
 * Base class for data consumers.
 */
class Consumer
{
public:
    /**
     * Locate sink with given name.
     *
     * @param name sink name.
     * @return pointer to sink or NULL if not found.
     */
    SinkBase* sink(const QString& name) const;

protected:
    /**
     * Add sink with given name.
     *
     * @param sink sink.
     * @param name sink name.
     */
    void addSink(SinkBase* sink, const QString& name);

    QHash<QString, SinkBase*>   sinks_; /**< sinks */
};

#endif
