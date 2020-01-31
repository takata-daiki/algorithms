#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct max_monoid {
    using value_type = T;
    T identity() const { return numeric_limits<T>::min(); }
    T merge(const T a, const T b) const { return max(a, b); }
};