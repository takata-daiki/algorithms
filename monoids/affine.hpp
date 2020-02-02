#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct affine_monoid {
    using P = pair<T, T>;
    using value_type = P;
    P identity() const { return make_pair(1, 0); }
    P merge(const P a, const P b) const {
        T fst = a.first * b.first;
        T snd = a.second * b.first + b.second;
        return make_pair(fst, snd);
    }
};