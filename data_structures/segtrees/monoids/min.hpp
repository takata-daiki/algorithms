#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename ValueType>
struct min_monoid {
    using T = ValueType;
    T identity() const { return numeric_limits<T>::max(); };
    T merge(const T a, const T b) const { return min(a, b); };
};