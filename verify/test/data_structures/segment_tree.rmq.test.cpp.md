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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/data_structures/segment_tree.rmq.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/data_structures/segment_tree.rmq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-24 18:12:30+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data_structures/segment_tree.hpp.html">data_structures/segment_tree.hpp</a>
* :heavy_check_mark: <a href="../../../library/monoids/min.hpp.html">monoids/min.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"
#include "../../data_structures/segment_tree.hpp"
#include "../../monoids/min.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    SegmentTree<min_monoid<int>> seg(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com) {
            cout << seg.query(x, y + 1) << endl;
        } else {
            seg.update(x, y);
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/data_structures/segment_tree.rmq.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"
#line 2 "test/data_structures/../../data_structures/segment_tree.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename Monoid>
struct SegmentTree {
    using T = typename Monoid::value_type;

    int n;
    vector<T> data;
    Monoid monoid;

    SegmentTree() {}
    SegmentTree(int _n, const Monoid& _monoid = Monoid()) : monoid(_monoid) {
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

    void update(int k, T x) {
        assert(0 <= k && k < n);
        k += n;
        data[k] = x;
        for (int i = k >> 1; i > 0; i >>= 1) {
            data[i] = monoid.merge(data[i << 1], data[i << 1 | 1]);
        }
    }
    // [a, b)
    T query(int a, int b) {
        assert(0 <= a && a <= b && b <= n);
        a += n;
        b += n - 1;
        T vl = monoid.identity(), vr = monoid.identity();
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = monoid.merge(vl, data[l++]);
            if (r & 1) vr = monoid.merge(data[--r], vr);
        }
        return monoid.merge(vl, vr);
    }
};
#line 2 "test/data_structures/../../monoids/min.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct min_monoid {
    using value_type = T;
    T identity() { return numeric_limits<T>::max(); }
    T merge(T a, T b) { return min(a, b); }
};
#line 4 "test/data_structures/segment_tree.rmq.test.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    SegmentTree<min_monoid<int>> seg(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com) {
            cout << seg.query(x, y + 1) << endl;
        } else {
            seg.update(x, y);
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

