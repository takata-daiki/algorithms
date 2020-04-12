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


# :heavy_check_mark: test/strings/rolling_hash.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#96cebfa45ba268d7f0532aaf888e8259">test/strings</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/strings/rolling_hash.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-24 17:58:17+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B">https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/strings/rolling_hash.hpp.html">strings/rolling_hash.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B"
#include "../../strings/rolling_hash.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    string t, p;
    cin >> t >> p;
    int lt = t.length();
    int lp = p.length();
    RollingHash rh(t + p);
    for (int i = 0; i < lt - lp + 1; i++) {
        if (rh.match(i, i + lp, lt, lt + lp)) cout << i << endl;
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/strings/rolling_hash.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B"
#line 2 "strings/rolling_hash.hpp"
#include <bits/stdc++.h>
using namespace std;

struct RollingHash {
    static int SIZE;
    static vector<uint64_t> mod;
    static vector<uint64_t> base;
    int n;
    vector<vector<unsigned>> h, pw;

    RollingHash(const string& s) : n(s.length()) {
        h.assign(SIZE, vector<unsigned>(n + 1, 0));
        pw.assign(SIZE, vector<unsigned>(n + 1, 1));
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < n; j++) {
                h[i][j + 1] = (h[i][j] * base[i] + s[j]) % mod[i];
                pw[i][j + 1] = pw[i][j] * base[i] % mod[i];
            }
        }
    }

    inline unsigned get(int l, int r, int k) const {
        return (h[k][r] + (mod[k] - h[k][l]) * pw[k][r - l]) % mod[k];
    }

    bool match(int l1, int r1, int l2, int r2) const {
        for (int i = 0; i < SIZE; i++) {
            if (get(l1, r1, i) != get(l2, r2, i)) return false;
        }
        return true;
    }

    int lcp(int i, int j) {
        int ok = 0;
        int ng = min(n - i, n - j) + 1;
        while (ng - ok > 1) {
            int m = (ok + ng) / 2;
            (match(i, i + m, j, j + m) ? ok : ng) = m;
        }
        return ok;
    }
};
int RollingHash::SIZE = 2;
vector<uint64_t> RollingHash::mod = {1000000007, 1000000009};
vector<uint64_t> RollingHash::base = {1009, 1007};
#line 3 "test/strings/rolling_hash.test.cpp"

#line 5 "test/strings/rolling_hash.test.cpp"
using namespace std;

int main() {
    string t, p;
    cin >> t >> p;
    int lt = t.length();
    int lp = p.length();
    RollingHash rh(t + p);
    for (int i = 0; i < lt - lp + 1; i++) {
        if (rh.match(i, i + lp, lt, lt + lp)) cout << i << endl;
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

