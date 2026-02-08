#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1次元imos法
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int d, n;
  cin >> d >> n;
  vector<int> attend(d + 1, 0);

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    ++attend[l];      // 開始地点を+1
    --attend[r + 1];  // 終了地点の次を-1
  }

  for (int i = 1; i <= d; i++) {
    attend[i] += attend[i - 1];  // 累積和を取る
    cout << attend[i] << endl;
  }
  return 0;
}
