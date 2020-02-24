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


# :heavy_check_mark: test/data_structures/lazy_segment_tree.max_update.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/data_structures/lazy_segment_tree.max_update.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-24 18:12:30+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data_structures/lazy_segment_tree.hpp.html">data_structures/lazy_segment_tree.hpp</a>
* :heavy_check_mark: <a href="../../../library/monoids/change.hpp.html">monoids/change.hpp</a>
* :heavy_check_mark: <a href="../../../library/monoids/max.hpp.html">monoids/max.hpp</a>
* :heavy_check_mark: <a href="../../../library/monoids/max_change_action.hpp.html">monoids/max_change_action.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F"
#include "../../data_structures/lazy_segment_tree.hpp"
#include "../../monoids/max.hpp"
#include "../../monoids/change.hpp"
#include "../../monoids/max_change_action.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 1 << 31 | 1);
    LazySegmentTree<max_monoid<int>, change_monoid<int>, max_change_action<int>> seg(begin(a), end(a));
    while (q--) {
        int com, s, t;
        cin >> com >> s >> t, t++;
        if (com) {
            cout << -seg.query(s, t) << endl;
        } else {
            int x;
            cin >> x;
            seg.update(s, t, -x);
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/data_structures/lazy_segment_tree.max_update.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F"
#line 2 "test/data_structures/../../data_structures/lazy_segment_tree.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename MonoidT, typename MonoidU, typename Action>
struct LazySegmentTree {
    using T = typename MonoidT::value_type;
    using U = typename MonoidU::value_type;

    int n, height;
    vector<T> data;
    vector<U> lazy;
    MonoidT monoid_t;
    MonoidU monoid_u;
    Action act;

    LazySegmentTree() {}
    LazySegmentTree(int _n, const MonoidT& _monoid_t = MonoidT(),
                    const MonoidU& _monoid_u = MonoidU(),
                    const Action& _act = Action())
        : monoid_t(_monoid_t), monoid_u(_monoid_u), act(_act) {
        n = 1, height = 0;
        while (n < _n) n <<= 1, height++;
        data.assign(n << 1, monoid_t.identity());
        lazy.assign(n << 1, monoid_u.identity());
    }
    // with initialization of given data
    template <class InputIterator>
    LazySegmentTree(InputIterator first, InputIterator last,
                    const MonoidT& _monoid_t = MonoidT(),
                    const MonoidU& _monoid_u = MonoidU(),
                    const Action& _act = Action())
        : monoid_t(_monoid_t), monoid_u(_monoid_u), act(_act) {
        int size = distance(first, last);
        n = 1, height = 0;
        while (n < size) n <<= 1, height++;
        data.assign(n << 1, monoid_t.identity());
        lazy.assign(n << 1, monoid_u.identity());
        copy(first, last, begin(data) + n);
        for (int i = n - 1; i > 0; i--) {
            data[i] = monoid_t.merge(data[i << 1], data[i << 1 | 1]);
        }
    }

    inline T action(int k) { return act(data[k], lazy[k]); }
    inline void eval(int k) {
        if (lazy[k] == monoid_u.identity()) return;
        lazy[k << 1] = monoid_u.merge(lazy[k << 1], lazy[k]);
        lazy[k << 1 | 1] = monoid_u.merge(lazy[k << 1 | 1], lazy[k]);
        data[k] = action(k);
        lazy[k] = monoid_u.identity();
    }
    // [a, b)
    void update(int a, int b, U x) {
        assert(0 <= a && a <= b && b <= n);
        a += n;
        b += n - 1;
        for (int i = height; i > 0; i--) {
            eval(a >> i);
            eval(b >> i);
        }
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = monoid_u.merge(lazy[l], x), l++;
            if (r & 1) --r, lazy[r] = monoid_u.merge(lazy[r], x);
        }
        for (int l = a >> 1; l > 0; l >>= 1) {
            data[l] = monoid_t.merge(action(l << 1), action(l << 1 | 1));
        }
        for (int r = b >> 1; r > 0; r >>= 1) {
            data[r] = monoid_t.merge(action(r << 1), action(r << 1 | 1));
        }
    }
    // [a, b)
    T query(int a, int b) {
        assert(0 <= a && a <= b && b <= n);
        a += n;
        b += n - 1;
        for (int i = height; i > 0; i--) {
            eval(a >> i);
            eval(b >> i);
        }
        T vl = monoid_t.identity(), vr = monoid_t.identity();
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = monoid_t.merge(vl, action(l++));
            if (r & 1) vr = monoid_t.merge(action(--r), vr);
        }
        return monoid_t.merge(vl, vr);
    }
};
#line 2 "test/data_structures/../../monoids/max.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct max_monoid {
    using value_type = T;
    T identity() { return numeric_limits<T>::min(); }
    T merge(T a, T b) { return max(a, b); }
};
#line 2 "test/data_structures/../../monoids/change.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct change_monoid {
    using value_type = T;
    T identity() { return numeric_limits<T>::max(); }
    T merge(T a, T b) { return (b == identity()) ? a : b; }
};
#line 2 "test/data_structures/../../monoids/max_change_action.hpp"
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct max_change_action {
    typename max_monoid<T>::value_type operator()(
        typename max_monoid<T>::value_type a,
        typename change_monoid<T>::value_type b) {
        return (b == change_monoid<T>().identity()) ? a : b;
    }
};
#line 6 "test/data_structures/lazy_segment_tree.max_update.test.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 1 << 31 | 1);
    LazySegmentTree<max_monoid<int>, change_monoid<int>, max_change_action<int>> seg(begin(a), end(a));
    while (q--) {
        int com, s, t;
        cin >> com >> s >> t, t++;
        if (com) {
            cout << -seg.query(s, t) << endl;
        } else {
            int x;
            cin >> x;
            seg.update(s, t, -x);
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

