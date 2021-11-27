/**
   @file deviceadaptorringbuffer.h
   @brief RingBuffer for DeviceAdaptors

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

#ifndef DEVICEADAPTORRINGBUFFER_H
#define DEVICEADAPTORRINGBUFFER_H

#include "ringbuffer.h"

/**
 * Ring buffer specialization for sensor adaptors.
 * @tparam TYPE data type in buffer.
 */
template <class TYPE>
class DeviceAdaptorRingBuffer : public RingBuffer<TYPE>
{
public:
    /**
     * Constructor.
     *
     * @param size how many elements fit into buffer.
     */
    DeviceAdaptorRingBuffer(unsigned size) :
        RingBuffer<TYPE>(size)
    {}

    using RingBuffer<TYPE>::nextSlot;
    using RingBuffer<TYPE>::commit;
    using RingBuffer<TYPE>::wakeUpReaders;
};

#endif
