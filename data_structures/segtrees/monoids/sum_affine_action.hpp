#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct sum_affine_action {
    typename sum_monoid<T>::value_type operator()(
        typename sum_monoid<T>::value_type a,
        typename affine_monoid<T>::value_type b) const {
        return make_pair(a.first * b.first + a.second * b.second, a.second);
    }
};