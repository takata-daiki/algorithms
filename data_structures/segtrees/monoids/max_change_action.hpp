#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct max_change_action {
    typename max_monoid<T>::value_type operator()(
        typename max_monoid<T>::value_type a,
        typename change_monoid<T>::value_type b) const {
        return (b == change_monoid<T>().identity()) ? a : b;
    }
};