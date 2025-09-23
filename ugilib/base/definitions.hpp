#pragma once
#include <cstdint>

// old (compat)
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// new
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128_t;
using f32 = float;
using f64 = double;
using f128 = long double;

#define rep(i, n) for(size_t i = 0; i < n; i++)  // rep macro
#define all(v) begin(v), end(v)  // all iterator
