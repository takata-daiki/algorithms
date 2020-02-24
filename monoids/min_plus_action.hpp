#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct min_plus_action {
    typename min_monoid<T>::value_type operator()(
        typename min_monoid<T>::value_type a,
        typename plus_monoid<T>::value_type b) {
        return (b == plus_monoid<T>().identity()) ? a : a + b;
    }
};