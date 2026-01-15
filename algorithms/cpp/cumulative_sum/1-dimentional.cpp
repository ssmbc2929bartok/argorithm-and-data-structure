#include <cmath>
#include <iostream>
#include <vector>
// 競プロ用
// #include <bits/stdc++.h>

/*１次元累積和を計算するためのファイルだよ*/
/*    様々なことに活用してくださいな     */
/*   質問・訂正などはXまでお願いします   */
/*       アカウントなどはGithubに       */

using namespace std;
using sumType = int;  // 全体の変数の型。状況に応じて変更してね

vector<sumType> gCmlSum;  // 累積和を保存するvector

// 累積和を計算するフィールドを作る関数
void initCumulativeSum(sumType size) {
  gCmlSum.assign(size + 1, 0);
}

// 値を入れるための関数
void input(sumType index, sumType inp) {
  gCmlSum[index] = inp;
}

// 全区間累積和を計算する関数
sumType calcAllSum() {
  for (int i = 1; i < gCmlSum.size(); i++) {
    gCmlSum[i] += gCmlSum[i - 1];
  }
  return gCmlSum.back();
}

// 区間[a, b]の累積和を計算する関数
// isUp = 0:終点方向, 1:[0]に向かって進んでいくよ
sumType calcSecSum(int a, int b, bool isUp) {
  if (a > b) swap(a, b);

  if (isUp) {
    for (int i = a + 1; i <= b; i++) {
      gCmlSum[i] += gCmlSum[i - 1];
    }
    return gCmlSum[b];
  } else {
    for (int i = b - 1; i >= a; i--) {
      gCmlSum[i] += gCmlSum[i + 1];
    }
    return gCmlSum[a];
  }
}
