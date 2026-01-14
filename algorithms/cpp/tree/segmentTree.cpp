#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
//競プロ用
//#include <bits/stdc++.h>

using namespace std;
using segType = int;  // セグメント木全体の型。必要に応じて書き換えてね

/*    セグメント木を実装出来るファイルだよ      */
/*  vectorの型名は状況に応じて自由に変更してね  */
/*        質問・不備などはXやDiscordまで       */
/*       @ssmbc2929_bartok(X:ssmbc2929bartok)*/
/*                implemented on 2026/01/08  */

// グローバル変数
const bool SERECTUD = 1;      //セグメント木の昇順、降順を決める。0:昇順、1:降順になる。
const segType INI = INT_MAX;  // 初期化変数（必要に応じて変更可）
vector<segType> segTree;      // セグメント木のvector
int BASE;                     // 葉の開始位置（1-index）

// セグメント木を作る関数
void initSegmentTree(segType n) {
  BASE = 1;
  while (BASE < n) {
    BASE <<= 1;
  }
  segTree.assign(BASE * 2, INI);
}

// セグメント木に値を追加する関数
void update(segType index, segType inp) {
  int idx = BASE + index;  // 0-index入力 → 内部1-index葉
  segTree[idx] = inp;

  while (idx > 1) {
    idx >>= 1;
    if (!SERECTUD) {
      segTree[idx] = max(segTree[idx << 1], segTree[idx << 1 | 1]);
    } else {
      segTree[idx] = min(segTree[idx << 1], segTree[idx << 1 | 1]);
    }
  }
}

// 区間[left, right]の最大値または最小値を返す関数
segType query(segType left, segType right) {
  int l = BASE + left;
  int r = BASE + right;

  segType wl = segTree[l];
  segType wr = segTree[r];

  while ((l >> 1) != (r >> 1)) {
    if ((l & 1) == 0) {
      if (!SERECTUD) {
        wl = max(wl, segTree[l + 1]);
      } else {
        wl = min(wl, segTree[l + 1]);
      }
    }
    if ((r & 1) == 1) {
      if (!SERECTUD) {
        wr = max(wr, segTree[r - 1]);
      } else {
        wr = min(wr, segTree[r - 1]);
      }
    }
    l >>= 1;
    r >>= 1;
  }
  if (!SERECTUD) {
    return max(wl, wr);
  } else {
    return min(wl, wr);
  }
}

// 区間[left, right]の区間和を求める関数
segType querySum(segType left, segType right) {
  int l = BASE + left;
  int r = BASE + right;

  segType res = 0;

  while (l <= r) {
    if (l & 1)
      res += segTree[l++];
    if (!(r & 1))
      res += segTree[r--];
    l >>= 1;
    r >>= 1;
  }
  return res;
}

// セグメント木を表示する関数
void printSegmentTree() {
  int i = 0;
  int level = 1;
  while (i < (int)segTree.size()) {
    int cnt = 1 << (level - 1);
    cout << "level" << level << "[ ";
    for (int k = 0; k < cnt && i < (int)segTree.size(); k++, i++) {
      cout << segTree[i] << " ";
    }
    cout << "]\n";
    level++;
  }
}
