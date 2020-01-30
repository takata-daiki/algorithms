#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct plus_min_action {
    typename min_monoid<T>::T operator()(typename plus_monoid<T>::T f,
                                         typename min_monoid<T>::T x) const {
        return (x == min_monoid<T>().identity()) ? x : f + x;
    }
};