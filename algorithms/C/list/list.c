#include <stdio.h>
#include <stdlib.h>

/*グローバル変数など*/
#define G_LIST_SIZE 10       /*listの大きさ。必要に応じて変更してね*/
typedef int list;            /*もしint型以外を使いたいときはここを変更してね*/
list gList[G_LIST_SIZE + 1]; /*List本体*/
list gListTail = 0;          /*Listの末尾を表す*/
list gListSize = 0;          /*Listのサイズを表す*/

/*関数原型宣言*/
void insert(list index, list ins);  /*リストの任意の場所に値を挿入する関数*/
void append(list app);              /*リストの末尾に値を挿入する関数*/
list retrieve(list index);          /*指定インデックスの要素を取得する関数*/
void replace(list index, list rep); /*指定インデックスの要素を変更する関数*/
void delete(list index);            /*指定インデックスの要素を削除する関数*/
void error(char* scr);              /*エラー操作を知らせて強制停止する関数*/
list size(void);                    /*リストのサイズを返す関数*/

/*リストの任意の場所に値を挿入する関数*/
void insert(list index, list ins) { /*0-indexed形式で指定すること*/
  if (index > gListTail) {
    error("error:insert:gList size exceeded!"); /*listの末端より先のインデックスを指定した場合はエラー出力*/
  }
  if (gListTail == G_LIST_SIZE) { /*listがいっぱいの時はエラー出力*/
    error("error:insert:gList is full!");
  }
  list i;
  for (i = gListTail; i > index; i--) { /*indexまでずらす*/
    gList[i + 1] = gList[i];
  }
  gList[index] = ins;
  ++gListTail;
}

/*リストの末尾に値を挿入する関数*/
void append(list app) { /*listがいっぱいの時はエラー出力*/
  if (gListTail == G_LIST_SIZE) {
    error("error:append:gList is full!");
  }
  gList[gListTail++] = app;
}

/*指定インデックスの要素を取得する関数*/
list retrieve(list index) { /*0-indexed形式で指定すること*/
  if (index > gListTail) {
    error("error:retrieve:gList size exceeded!"); /*listの末端より先のインデックスを指定した場合はエラー出力*/
  }
  return gList[index];
}

/*指定インデックスの要素を変更する関数*/
void replace(list index, list rep) { /*0-indexed形式で指定すること*/
  if (index > gListTail) {
    error("error:replace:gList size exceeded!"); /*listの末端より先のインデックスを指定した場合はエラー出力*/
  }
  gList[index] = rep;
}

/*指定インデックスの要素を削除する関数*/
void delete(list index) {
  if (gListTail == 0) {
    error("error:delete:gList is empty!"); /*listが空の場合はエラー出力*/
  }
  list i;
  for (int i = index; i < gListTail; i++) {
    gList[i] = gList[i + 1];
  }
  --gListTail;
}

/*リストのサイズを返す関数*/
list size(void) {
  return gListTail;
}

/*エラー操作を知らせて強制停止する関数*/
void error(char* scr) {
  fflush(stdout);
  fprintf(stderr, "%s\n", scr); /*標準エラー出力*/
  exit(1);                      /*異常強制終了*/
}
