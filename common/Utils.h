#ifndef UTILS_H
#define UTILS_H

/**
 * \file Utils.h
 * \brief Utilitaires génériques
 */

#pragma once

#include <random>

namespace Sensor
{
namespace Utils
{
/**
 * \brief Nombre réel uniforme entre \p min et \p max.
 */
inline double randomBetween(double min, double max)
{
    static thread_local std::mt19937 rng(static_cast<unsigned int>(
        std::random_device()()));
    std::uniform_real_distribution<double> dist(min, max);
    return dist(rng);
}
} // namespace Utils
} // namespace Sensor


#endif // UTILS_H
