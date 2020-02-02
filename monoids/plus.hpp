#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct plus_monoid {
    using value_type = T;
    T identity() const { return T(); };
    T merge(const T a, const T b) const { return a + b; };
};