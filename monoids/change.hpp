#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct change_monoid {
    using value_type = T;
    T identity() { return numeric_limits<T>::max(); }
    T merge(T a, T b) { return (b == identity()) ? a : b; }
};