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


# :heavy_check_mark: test/data_structures/lazy_segment_tree.sum_affine.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/data_structures/lazy_segment_tree.sum_affine.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-02 22:50:19+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data_structures/lazy_segment_tree.hpp.html">data_structures/lazy_segment_tree.hpp</a>
* :heavy_check_mark: <a href="../../../library/maths/mod.hpp.html">maths/mod.hpp</a>
* :heavy_check_mark: <a href="../../../library/monoids/affine.hpp.html">monoids/affine.hpp</a>
* :heavy_check_mark: <a href="../../../library/monoids/sum.hpp.html">monoids/sum.hpp</a>
* :heavy_check_mark: <a href="../../../library/monoids/sum_affine_action.hpp.html">monoids/sum_affine_action.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../data_structures/lazy_segment_tree.hpp"
#include "../../monoids/sum.hpp"
#include "../../monoids/affine.hpp"
#include "../../monoids/sum_affine_action.hpp"
#include "../../maths/mod.hpp"

#include <bits/stdc++.h>
using namespace std;
using P = pair<ModInt, int>;

ModInt operator*(int x, ModInt m) { return ModInt(x) * m; }

int main() {
    ModInt::MOD = 998244353;
    int n, q;
    cin >> n >> q;
    vector<P> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = P(x, 1);
    }
    
    LazySegmentTree<sum_monoid<ModInt>, affine_monoid<ModInt>, sum_affine_action<ModInt>> seg(begin(a), end(a));
    while (q--) {
        int com, l, r;
        cin >> com >> l >> r;
        if (com) {
            cout << seg.query(l, r).first << endl;
        } else {
            int b, c;
            cin >> b >> c;
            seg.update(l, r, P(b, c));
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/data_structures/lazy_segment_tree.sum_affine.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#line 2 "test/data_structures/../../data_structures/lazy_segment_tree.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename MonoidT, typename MonoidU, typename Action>
struct LazySegmentTree {
    using T = typename MonoidT::value_type;
    using U = typename MonoidU::value_type;

    const MonoidT monoid_t;
    const MonoidU monoid_u;
    const Action act;
    int n, height;
    vector<T> data;
    vector<U> lazy;

    LazySegmentTree() {}
    LazySegmentTree(const int _n, const MonoidT& _monoid_t = MonoidT(),
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
        data.resize(n << 1, monoid_t.identity());
        lazy.resize(n << 1, monoid_u.identity());
        copy(first, last, begin(data) + n);
        for (int i = n - 1; i > 0; i--) {
            data[i] = monoid_t.merge(data[i << 1], data[i << 1 | 1]);
        }
    }

    inline T action(int k) { return act(data[k], lazy[k]); }
    inline void eval(const int k) {
        if (lazy[k] == monoid_u.identity()) return;
        lazy[k << 1] = monoid_u.merge(lazy[k << 1], lazy[k]);
        lazy[k << 1 | 1] = monoid_u.merge(lazy[k << 1 | 1], lazy[k]);
        data[k] = action(k);
        lazy[k] = monoid_u.identity();
    }
    // [a, b)
    void update(const int a, const int b, const U x) {
        assert(0 <= a && a <= b && b <= n);
        for (int i = height; i > 0; i--) {
            eval((a + n) >> i);
            eval((b + n - 1) >> i);
        }
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = monoid_u.merge(lazy[l], x), l++;
            if (r & 1) --r, lazy[r] = monoid_u.merge(lazy[r], x);
        }
        for (int l = (a + n) >> 1; l > 0; l >>= 1) {
            data[l] = monoid_t.merge(action(l << 1), action(l << 1 | 1));
        }
        for (int r = (b + n - 1) >> 1; r > 0; r >>= 1) {
            data[r] = monoid_t.merge(action(r << 1), action(r << 1 | 1));
        }
    }
    // [a, b)
    T query(const int a, const int b) {
        assert(0 <= a && a <= b && b <= n);
        for (int i = height; i > 0; i--) {
            eval((a + n) >> i);
            eval((b + n - 1) >> i);
        }
        T vl = monoid_t.identity(), vr = monoid_t.identity();
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = monoid_t.merge(vl, action(l++));
            if (r & 1) vr = monoid_t.merge(action(--r), vr);
        }
        return monoid_t.merge(vl, vr);
    }
};
#line 2 "test/data_structures/../../monoids/sum.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct sum_monoid {
    using P = pair<T, int>;
    using value_type = P;
    P identity() const { return make_pair(T(), 0); }
    P merge(const P a, const P b) const { return make_pair(a.first + b.first, a.second + b.second); }
};
#line 2 "test/data_structures/../../monoids/affine.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct affine_monoid {
    using P = pair<T, T>;
    using value_type = P;
    P identity() const { return make_pair(1, 0); }
    P merge(const P a, const P b) const {
        T fst = a.first * b.first;
        T snd = a.second * b.first + b.second;
        return make_pair(fst, snd);
    }
};
#line 2 "test/data_structures/../../monoids/sum_affine_action.hpp"
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct sum_affine_action {
    typename sum_monoid<T>::value_type operator()(
        typename sum_monoid<T>::value_type a,
        typename affine_monoid<T>::value_type b) const {
        return make_pair(a.first * b.first + a.second * b.second, a.second);
    }
};
#line 2 "test/data_structures/../../maths/mod.hpp"
#include <bits/stdc++.h>
using namespace std;

struct ModInt {
    using M = ModInt;

    static vector<M> fact, finv;
    static long long MOD;
    long long v;

    // norm: [-MOD, MOD**2] -> [0, MOD)
    ModInt(const long long _v = 0) : v((_v < 0) ? _v % MOD + MOD : _v % MOD) {}
    
    M operator+(const M& x) const { return M(v + x.v); }
    M operator-(const M& x) const { return M(v - x.v); }
    M operator*(const M& x) const { return M(v * x.v); }
    M operator/(const M& x) const { return M(v * x.inv().v); }
    M& operator+=(const M& x) { return *this = *this + x; }
    M& operator-=(const M& x) { return *this = *this - x; }
    M& operator*=(const M& x) { return *this = *this * x; }
    M& operator/=(const M& x) { return *this = *this / x; }
    bool operator==(const M& x) const { return v == x.v; }
    bool operator!=(const M& x) const { return v != x.v; }
    friend istream& operator>>(istream& input, M& x) {
        return input >> x.v, x = M(x), input;
    }
    friend ostream& operator<<(ostream& output, const M& x) {
        return output << x.v;
    }
    inline M pow(long long n) const {
        M x(v), res(1);
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    inline M inv() const { return this->pow(MOD - 2); }
    static void build(const int n) {
        fact.assign(n + 1, 1);
        for (int i = 1; i < n + 1; i++) fact[i] = fact[i - 1] * M(i);
        finv.assign(n + 1, fact[n].inv());
        for (int i = n; i > 0; i--) finv[i - 1] = finv[i] * M(i);
    }
    static M comb(const int n, const int k) {
        if (n < k || k < 0) return M(0);
        return fact[n] * finv[n - k] * finv[k];
    }
    static M extgcd(const int a, const int b, int* x, int* y) {
        M d(a);
        if (b) {
            d = extgcd(b, a % b, y, x);
            *y -= (a / b) * *x;
        } else {
            *x = 1, *y = 0;
        }
        return d;
    }
};
vector<ModInt> ModInt::fact = vector<ModInt>();
vector<ModInt> ModInt::finv = vector<ModInt>();
long long ModInt::MOD = 1e9 + 7;
#line 7 "test/data_structures/lazy_segment_tree.sum_affine.test.cpp"

#include <bits/stdc++.h>
using namespace std;
using P = pair<ModInt, int>;

ModInt operator*(int x, ModInt m) { return ModInt(x) * m; }

int main() {
    ModInt::MOD = 998244353;
    int n, q;
    cin >> n >> q;
    vector<P> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = P(x, 1);
    }
    
    LazySegmentTree<sum_monoid<ModInt>, affine_monoid<ModInt>, sum_affine_action<ModInt>> seg(begin(a), end(a));
    while (q--) {
        int com, l, r;
        cin >> com >> l >> r;
        if (com) {
            cout << seg.query(l, r).first << endl;
        } else {
            int b, c;
            cin >> b >> c;
            seg.update(l, r, P(b, c));
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

