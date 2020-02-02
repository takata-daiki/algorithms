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


# :heavy_check_mark: data_structures/segment_tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#9466edd02bad586f9ccf200a84a4dafd">data_structures</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structures/segment_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-02 22:50:19+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/data_structures/segment_tree.rmq.test.cpp.html">test/data_structures/segment_tree.rmq.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename Monoid>
struct SegmentTree {
    using T = typename Monoid::value_type;

    const Monoid monoid;
    int n;
    vector<T> data;

    SegmentTree() {}
    SegmentTree(const int _n, const Monoid& _monoid = Monoid())
        : monoid(_monoid) {
        n = 1;
        while (n < _n) n <<= 1;
        data.assign(n << 1, monoid.identity());
    }
    // with initialization of given data
    template <class InputIterator>
    SegmentTree(InputIterator first, InputIterator last,
                const Monoid& _monoid = Monoid())
        : monoid(_monoid) {
        int size = distance(first, last);
        n = 1;
        while (n < size) n <<= 1;
        data.assign(n << 1, monoid.identity());
        copy(first, last, begin(data) + n);
        for (int i = n - 1; i > 0; i--) {
            data[i] = monoid.merge(data[i << 1], data[i << 1 | 1]);
        }
    }

    void update(const int k, const T x) {
        assert(0 <= k && k < n);
        data[k + n] = x;
        for (int i = (k + n) >> 1; i > 0; i >>= 1) {
            data[i] = monoid.merge(data[i << 1], data[i << 1 | 1]);
        }
    }
    // [a, b)
    T query(const int a, const int b) {
        assert(0 <= a && a <= b && b <= n);
        T vl = monoid.identity(), vr = monoid.identity();
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = monoid.merge(vl, data[l++]);
            if (r & 1) vr = monoid.merge(data[--r], vr);
        }
        return monoid.merge(vl, vr);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structures/segment_tree.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename Monoid>
struct SegmentTree {
    using T = typename Monoid::value_type;

    const Monoid monoid;
    int n;
    vector<T> data;

    SegmentTree() {}
    SegmentTree(const int _n, const Monoid& _monoid = Monoid())
        : monoid(_monoid) {
        n = 1;
        while (n < _n) n <<= 1;
        data.assign(n << 1, monoid.identity());
    }
    // with initialization of given data
    template <class InputIterator>
    SegmentTree(InputIterator first, InputIterator last,
                const Monoid& _monoid = Monoid())
        : monoid(_monoid) {
        int size = distance(first, last);
        n = 1;
        while (n < size) n <<= 1;
        data.assign(n << 1, monoid.identity());
        copy(first, last, begin(data) + n);
        for (int i = n - 1; i > 0; i--) {
            data[i] = monoid.merge(data[i << 1], data[i << 1 | 1]);
        }
    }

    void update(const int k, const T x) {
        assert(0 <= k && k < n);
        data[k + n] = x;
        for (int i = (k + n) >> 1; i > 0; i >>= 1) {
            data[i] = monoid.merge(data[i << 1], data[i << 1 | 1]);
        }
    }
    // [a, b)
    T query(const int a, const int b) {
        assert(0 <= a && a <= b && b <= n);
        T vl = monoid.identity(), vr = monoid.identity();
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = monoid.merge(vl, data[l++]);
            if (r & 1) vr = monoid.merge(data[--r], vr);
        }
        return monoid.merge(vl, vr);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

