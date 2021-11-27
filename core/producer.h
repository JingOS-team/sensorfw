/**
   @file producer.h
   @brief Producer

   <p>
   Copyright (C) 2009-2010 Nokia Corporation

   @author Semi Malinen <semi.malinen@nokia.com
   @author Joep van Gassel <joep.van.gassel@nokia.com>

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

#ifndef PRODUCER_H
#define PRODUCER_H

#include <QString>
#include <QHash>

class SourceBase;

/**
 * Data producer base-class.
 */
class Producer
{
public:
    /**
     * Locate source with given name.
     *
     * @param name source name.
     * @return pointer to source or NULL if not found.
     */
    SourceBase* source(const QString& name);

protected:
    /**
     * Destructor.
     */
    virtual ~Producer();

    /**
     * Add source with given name.
     *
     * @param source source to add.
     * @param name name of the source.
     */
    void addSource(SourceBase* source, const QString& name);

private:
    QHash<QString, SourceBase*> sources_; /**< map of sources */
};

#endif
