#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct sum_monoid {
    using P = pair<T, int>;
    using value_type = P;
    P identity() { return make_pair(T(), T(0)); }
    P merge(P a, P b) {
        return make_pair(a.first + b.first, a.second + b.second);
    }
};