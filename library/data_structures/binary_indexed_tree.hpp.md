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

* category: <a href="../../index.html#9466edd02bad586f9ccf200a84a4dafd">data_structures</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structures/binary_indexed_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 04:22:36+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/data_structures/binary_indexed_tree.test.cpp.html">test/data_structures/binary_indexed_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

// 0-indexed
template <typename T>
struct BinaryIndexedTree {
    const int n;
    vector<T> data;

    BinaryIndexedTree(const int _n) : n(_n) {
        data.assign(n + 1, 0);
    }

    inline void add(const int k, const T x) {
        assert(0 <= k && k < n);
        for (int i = k + 1; i <= n; i += i & -i) data[i] += x;
    }
    // [0, k)
    inline T sum(const int k) {
        assert(0 <= k && k <= n);
        T s = 0;
        for (int i = k; i > 0; i -= i & -i) s += data[i];
        return s;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structures/binary_indexed_tree.hpp"
#include <bits/stdc++.h>
using namespace std;

// 0-indexed
template <typename T>
struct BinaryIndexedTree {
    const int n;
    vector<T> data;

    BinaryIndexedTree(const int _n) : n(_n) {
        data.assign(n + 1, 0);
    }

    inline void add(const int k, const T x) {
        assert(0 <= k && k < n);
        for (int i = k + 1; i <= n; i += i & -i) data[i] += x;
    }
    // [0, k)
    inline T sum(const int k) {
        assert(0 <= k && k <= n);
        T s = 0;
        for (int i = k; i > 0; i -= i & -i) s += data[i];
        return s;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

