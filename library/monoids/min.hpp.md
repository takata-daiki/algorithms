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


# :heavy_check_mark: monoids/min.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#315142c884fa9bdd2be3b42923ffe964">monoids</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoids/min.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-24 17:58:17+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/data_structures/lazy_segment_tree.min_add.test.cpp.html">test/data_structures/lazy_segment_tree.min_add.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/data_structures/lazy_segment_tree.min_update.test.cpp.html">test/data_structures/lazy_segment_tree.min_update.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/data_structures/segment_tree.rmq.test.cpp.html">test/data_structures/segment_tree.rmq.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct min_monoid {
    using value_type = T;
    T identity() { return numeric_limits<T>::max(); }
    T merge(T a, T b) { return min(a, b); }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "monoids/min.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct min_monoid {
    using value_type = T;
    T identity() { return numeric_limits<T>::max(); }
    T merge(T a, T b) { return min(a, b); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
