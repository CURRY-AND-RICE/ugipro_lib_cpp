#pragma once
#include "ugilib/base/definitions.hpp"

namespace ugilib::constants {
    template<typename T>
    inline constexpr T INF = std::numeric_limits<T>::max() / 4;
} // namespace ugilib::constants

const ll INF = ugilib::constants::INF<ll>;
