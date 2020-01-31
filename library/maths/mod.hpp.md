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


# :heavy_check_mark: maths/mod.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d939e7a6b17e374c1e3db59b4df2ae97">maths</a>
* <a href="{{ site.github.repository_url }}/blob/master/maths/mod.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-01 03:17:28+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/data_structures/lazy_segment_tree.sum_affine.test.cpp.html">test/data_structures/lazy_segment_tree.sum_affine.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/maths/mod.combination.test.cpp.html">test/maths/mod.combination.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "maths/mod.hpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

