#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w, n;
  cin >> h >> w >> n;

  vector<vector<int>> x(h + 2, vector<int>(w + 2, 0));

  // imos
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ++x[a][b];
    --x[a][d + 1];
    --x[c + 1][b];
    ++x[c + 1][d + 1];
  }

  // 累積和
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      x[i][j] += x[i][j - 1];  // 横向きスキャン
    }
  }

  for (int i = 1; i <= w; i++) {
    for (int j = 1; j <= h; j++) {
      x[j][i] += x[j - 1][i];  // 縦向きスキャン
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (j >= 2) {
        cout << " ";
      }
      cout << x[i][j];
    }
    cout << endl;
  }

  return 0;
}
