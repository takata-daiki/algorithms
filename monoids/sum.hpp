#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct sum_monoid {
    using P = pair<T, int>;
    using value_type = P;
    P identity() const { return make_pair(T(), 0); }
    P merge(const P a, const P b) const { return make_pair(a.first + b.first, a.second + b.second); }
};