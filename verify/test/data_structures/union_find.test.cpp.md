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


# :heavy_check_mark: test/data_structures/union_find.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/data_structures/union_find.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-24 17:58:17+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data_structures/union_find.hpp.html">data_structures/union_find.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A"
#include "../../data_structures/union_find.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com) {
            cout << uf.same(x, y) << endl;
        } else {
            uf.unite(x, y);
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/data_structures/union_find.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A"
#line 2 "test/data_structures/../../data_structures/union_find.hpp"
#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> data;

    UnionFind(int n) : data(n, -1) {}

    inline int root(int x) {
        return (data[x] < 0) ? x : data[x] = root(data[x]);
    }
    inline int size(int x) { return -data[root(x)]; }
    inline bool same(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
};
#line 3 "test/data_structures/union_find.test.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com) {
            cout << uf.same(x, y) << endl;
        } else {
            uf.unite(x, y);
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
