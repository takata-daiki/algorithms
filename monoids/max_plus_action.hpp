#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct max_plus_action {
    typename max_monoid<T>::value_type operator()(
        typename max_monoid<T>::value_type a,
        typename plus_monoid<T>::value_type b) const {
        return (b == plus_monoid<T>().identity()) ? a : a + b;
    }
};