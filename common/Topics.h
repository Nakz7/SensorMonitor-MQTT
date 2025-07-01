#ifndef TOPICS_H
#define TOPICS_H

/**
 * \file Topics.h
 * \brief Topics MQTT (sans variables inline)
 */

#pragma once

namespace Sensor
{
namespace Mqtt
{
namespace Topics
{
static const char temp[]     = "sensors/temp";     //!< Température (°C)
static const char humidity[] = "sensors/hum";      //!< Humidité (%)
static const char pressure[] = "sensors/pressure"; //!< Pression  (hPa)
} // namespace Topics
} // namespace Mqtt
} // namespace Sensor


#endif // TOPICS_H
