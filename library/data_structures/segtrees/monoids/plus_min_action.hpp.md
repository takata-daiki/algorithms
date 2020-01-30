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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: data_structures/segtrees/monoids/plus_min_action.hpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3530283758733456883f81bc5e73deb0">data_structures/segtrees/monoids</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structures/segtrees/monoids/plus_min_action.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 03:44:28+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/data_structures/lazy_segment_tree.rmq_and_raq.test.cpp.html">test/data_structures/lazy_segment_tree.rmq_and_raq.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct plus_min_action {
    typename min_monoid<T>::T operator()(typename plus_monoid<T>::T f,
                                         typename min_monoid<T>::T x) const {
        return (x == min_monoid<T>().identity()) ? x : f + x;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structures/segtrees/monoids/plus_min_action.hpp"
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct plus_min_action {
    typename min_monoid<T>::T operator()(typename plus_monoid<T>::T f,
                                         typename min_monoid<T>::T x) const {
        return (x == min_monoid<T>().identity()) ? x : f + x;
    }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
