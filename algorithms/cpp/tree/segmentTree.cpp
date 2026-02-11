#include <algorithm>
#include <climits>
#include <functional>
#include <vector>

using namespace std;
using ll = long long;

struct SegmentTree {
  int n;
  vector<ll> tree;
  ll unit;                  // 単位元（初期値）
  function<ll(ll, ll)> op;  // 演算（min, max, sumなど）

  // コンストラクタ: サイズ、初期値、演算を指定
  SegmentTree(int _n, ll _unit, function<ll(ll, ll)> _op)
      : unit(_unit), op(_op) {
    n = 1;
    while (n < _n) n <<= 1;
    tree.assign(n * 2, unit);
  }

  // 値の更新: i番目をxに変更
  void update(int i, ll x) {
    i += n;
    tree[i] = x;
    while (i > 1) {
      i >>= 1;
      tree[i] = op(tree[i << 1], tree[i << 1 | 1]);
    }
  }

  void build(const vector<ll>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
      tree[n + i] = v[i];
    }
    // 下の段から順番に親を計算していく
    for (int i = n - 1; i >= 1; i--) {
      tree[i] = op(tree[i << 1], tree[i << 1 | 1]);
    }
  }

  // 区間クエリ: [l, r) の範囲を計算（半開区間）
  ll query(int l, int r) {
    ll res_l = unit;
    ll res_r = unit;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res_l = op(res_l, tree[l++]);
      if (r & 1) res_r = op(tree[--r], res_r);
    }
    return op(res_l, res_r);
  }
};

// how to use
/*
// 最小値を求めたいとき（単位元は「十分大きい値」）
SegmentTree st_min(n, LLONG_MAX, [](ll a, ll b){ return min(a, b); });

// 最大値を求めたいとき（単位元は「十分小さい値」）
SegmentTree st_max(n, LLONG_MIN, [](ll a, ll b){ return max(a, b); });

// 和を求めたいとき（単位元は「0」）
SegmentTree st_sum(n, 0, [](ll a, ll b){ return a + b; });

// 3番目の要素（0-indexed）を 100 に変更
st_min.update(3, 100);

// 2番目から 5番目まで（[2, 6)）の最小値をゲット※半開区間
ll result = st_min.query(2, 6);
*/
