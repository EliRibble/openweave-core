/*
 *
 *    Copyright (c) 2016-2017 Nest Labs, Inc.
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 * @file
 *
 * @brief
 *   Class declarations for a Counter base class, and a monotonically-increasing counter.
 */

#ifndef WEAVE_COUNTER_H
#define WEAVE_COUNTER_H

namespace nl {
namespace Weave {

/**
 * @class Counter
 *
 * @brief
 *   An interface for managing a counter as an integer value.
 */

class Counter
{
public:
    Counter(void) { };
    virtual ~Counter(void) { };

    /**
     *  @brief
     *  Advance the value of the counter.
     *
     *  @return A Weave error code if anything failed, WEAVE_NO_ERROR otherwise.
     */
    virtual WEAVE_ERROR Advance(void) = 0;

    /**
     *  @brief
     *  Get the current value of the counter.
     *
     *  @return The current value of the counter.
     */
    virtual uint32_t GetValue(void) = 0;

};

/**
 * @class MonotonicallyIncreasingCounter
 *
 * @brief
 *   A class for managing a monotonically-increasing counter as an integer value.
 */

class MonotonicallyIncreasingCounter : public Counter
{
public:
    MonotonicallyIncreasingCounter(void);
    virtual ~MonotonicallyIncreasingCounter(void);

    /**
     *  @brief
     *    Initialize a MonotonicallyIncreasingCounter object.
     *
     *  @param[in] aStartValue  The starting value of the counter.
     *
     *  @return A Weave error code if something fails, WEAVE_NO_ERROR otherwise
     */
    WEAVE_ERROR Init(uint32_t aStartValue);

    /**
     *  @brief
     *  Advance the value of the counter.
     *
     *  @return A Weave error code if something fails, WEAVE_NO_ERROR otherwise
     */
    virtual WEAVE_ERROR Advance(void);

    /**
     *  @brief
     *  Get the current value of the counter.
     *
     *  @return The current value of the counter.
     */
    virtual uint32_t GetValue(void);

protected:
    uint32_t mCounterValue;

};

} // Weave
} // nl

#endif // WEAVE_COUNTER_H
