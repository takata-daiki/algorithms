---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: others/debug.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e2bab0ecb94c4ea40777733195abe1b">others</a>
* <a href="{{ site.github.repository_url }}/blob/master/others/debug.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 14:56:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "others/debug.hpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

