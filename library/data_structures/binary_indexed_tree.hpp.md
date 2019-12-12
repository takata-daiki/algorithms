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


# :heavy_check_mark: data_structures/binary_indexed_tree.hpp
<a href="../../index.html">Back to top page</a>

* category: data_structures
* <a href="{{ site.github.repository_url }}/blob/master/data_structures/binary_indexed_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-12 01:50:18 +0900




## Verified With
* :heavy_check_mark: <a href="../../verify/test/data_structures/binary_indexed_tree.test.cpp.html">test/data_structures/binary_indexed_tree.test.cpp</a>


## Code
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryIndexedTree {
    vector<T> data;

    BinaryIndexedTree(const int n) : data(n + 1, 0) {}

    inline T sum(const int k) {
        T s = 0;
        for (int i = k + 1; i > 0; i -= i & -i) s += data[i];
        return s;
    }
    inline void add(const int k, const T x) {
        for (int i = k + 1; i < (int)data.size(); i += i & -i) data[i] += x;
    }
};
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

