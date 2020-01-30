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


# :x: test/data_structures/binary_indexed_tree.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/data_structures/binary_indexed_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 03:44:28+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B</a>


## Depends on

* :x: <a href="../../../library/data_structures/binary_indexed_tree.hpp.html">data_structures/binary_indexed_tree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"
#include "../../data_structures/binary_indexed_tree.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    BinaryIndexedTree<long long> bit(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y, x--;
        if (com) {
            cout << bit.sum(y - 1) - bit.sum(x - 1) << endl;
        } else {
            bit.add(x, y);
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/data_structures/binary_indexed_tree.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"
#line 2 "test/data_structures/../../data_structures/binary_indexed_tree.hpp"
#include <bits/stdc++.h>
using namespace std;

// 0-indexed
template <typename T>
struct BinaryIndexedTree {
    const int n;
    vector<T> data;

    BinaryIndexedTree(const int _n) : n(_n) {
        data.assign(n + 1, 0)
    }

    inline void add(const int k, const T x) {
        assert(0 <= k && k < n);
        for (int i = k + 1; i <= n; i += i & -i) data[i] += x;
    }
    inline T sum(const int k) {
        assert(0 <= k && k < n);
        T s = 0;
        for (int i = k + 1; i > 0; i -= i & -i) s += data[i];
        return s;
    }
};
#line 3 "test/data_structures/binary_indexed_tree.test.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    BinaryIndexedTree<long long> bit(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y, x--;
        if (com) {
            cout << bit.sum(y - 1) - bit.sum(x - 1) << endl;
        } else {
            bit.add(x, y);
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

