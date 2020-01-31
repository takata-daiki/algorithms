#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct change_monoid {
    using value_type = T;
    T identity() const { return numeric_limits<T>::max(); }
    T merge(const T a, const T b) const { return (b == identity()) ? a : b; }
};