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


# :warning: data_structures/union_find.hpp
<a href="../../index.html">Back to top page</a>

* category: data_structures
* <a href="{{ site.github.repository_url }}/blob/master/data_structures/union_find.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-12 01:50:18 +0900




## Required By
* :warning: <a href="../graphs/kruskal.hpp.html">graphs/kruskal.hpp</a>


## Verified With
* :warning: <a href="../../verify/test/data_structures/union_find.test.cpp.html">test/data_structures/union_find.test.cpp</a>


## Code
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> data;

    UnionFind(const int n) : data(n, -1) {}

    inline int root(const int x) {
        return (data[x] < 0) ? x : data[x] = root(data[x]);
    }
    inline int size(const int x) { return -data[root(x)]; }
    inline bool same(const int x, const int y) { return root(x) == root(y); }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
};
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

