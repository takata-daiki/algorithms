#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct min_index_monoid {
    using P = pair<T, int>;
    using value_type = P;
    P identity() { return make_pair(numeric_limits<T>::max(), INT_MAX); }
    P merge(P a, P b) { return min(a, b); }
};