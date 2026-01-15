#include <cmath>
#include <iostream>
#include <vector>
// 競プロ用
// #include <bits/stdc++.h>

/*2次元累積和を計算するためのファイルだよ*/
/*    様々なことに活用してくださいな    */
/*   質問・訂正などはXまでお願いします  */
/*       アカウントなどはGithubに      */

using namespace std;
using sumType = int;  // 状況に応じて変更してね

vector<vector<sumType>> gCmlSum;  // 累積和を保存するvector

// 累積和を計算するフィールドを作る関数
void initCumulativeSum(sumType h, sumType w) {
  gCmlSum.assign(h + 1, vector<sumType>(w + 1, 0));
  cout << "ok" << endl;
}

// 値を入れるための関数
void input(sumType indH, sumType indW, sumType inp) {
  gCmlSum[indH][indW] = inp;
}

// 全区間累積和を計算する関数
void calcAllSum() {
  for (int i = 0; i <= gCmlSum.size(); i++) {
    for (int j = 1; j <= gCmlSum[i].size(); j++) {
      gCmlSum[i][j] = gCmlSum[i][j] + gCmlSum[i][j - 1];
    }
  }

  for (int i = 1; i <= gCmlSum.size(); i++) {
    for (int j = 0; j <= gCmlSum[i].size(); j++) {
      gCmlSum[i][j] = gCmlSum[i][j] + gCmlSum[i - 1][j];
    }
  }
}

// 区間[(a, b), (c, d)]の累積和を計算する関数
sumType calcSecSum(int a, int b, int c, int d) {
  return gCmlSum[c][d] + gCmlSum[a - 1][b - 1] - gCmlSum[a - 1][d] - gCmlSum[c][b - 1];
}

// フィールドを出力する関数
void printGCulSum() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << gCmlSum[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  initCumulativeSum(5, 5);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      input(i, j, rand());
    }
  }

  printGCulSum();
  cout << gCmlSum.size() << endl;
  return 0;
}
