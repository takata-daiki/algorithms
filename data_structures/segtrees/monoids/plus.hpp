#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename ValueType>
struct plus_monoid {
    using T = ValueType;
    T identity() const { return T(); };
    T merge(const T a, const T b) const { return a + b; };
};