#pragma once
#include <bits/stdc++.h>
using namespace std;

/////////////////////////
#ifdef DEBUG
#define DEB
#define dump(...)                                                       \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                     \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]" \
            << endl                                                     \
            << "    ",                                                  \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

#define DUMPOUT cerr
#define LINE(v)                                       \
    os << "{";                                        \
    for (auto itr = begin(v); itr != end(v); itr++) { \
        os << *itr;                                   \
        itr++;                                        \
        if (itr != end(v)) os << ", ";                \
        itr--;                                        \
    }                                                 \
    os << "}"

void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}

// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    LINE(vec);
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &mat) {
    int len = mat.size();
    os << "{" << endl;
    for (int i = 0; i < len; ++i) {
        os << "     " << mat[i] << endl;
    }
    os << "    }";
    return os;
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &map_var) {
    LINE(map_var);
    return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, const set<T> &set_var) {
    LINE(set_var);
    return os;
}
/////////////////////////