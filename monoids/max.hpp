#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct max_monoid {
    using value_type = T;
    T identity() { return numeric_limits<T>::min(); }
    T merge(T a, T b) { return max(a, b); }
};