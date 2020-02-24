#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct plus_monoid {
    using value_type = T;
    T identity() { return T(); };
    T merge(T a, T b) { return a + b; };
};