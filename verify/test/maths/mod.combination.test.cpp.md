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


# :heavy_check_mark: test/maths/mod.combination.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/maths/mod.combination.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 03:44:28+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/maths/mod.hpp.html">maths/mod.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D"
#include "../../maths/mod.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    ModInt::build(2000);
    cout << ModInt::comb(n + k - 1, n) << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/maths/mod.combination.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D"
#line 2 "test/maths/../../maths/mod.hpp"
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
#line 3 "test/maths/mod.combination.test.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    ModInt::build(2000);
    cout << ModInt::comb(n + k - 1, n) << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

