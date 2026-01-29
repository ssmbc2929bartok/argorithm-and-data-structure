#include <stdio.h>
#include <stdlib.h>

/*グローバル変数など*/
#define G_STACK_SIZE 10     /*stackの大きさ。必要に応じて変更してね*/
typedef int stack;          /*もしint型以外を使いたいときはここを変更してね*/
stack gStack[G_STACK_SIZE]; /*stack本体*/
stack gStackNum = 0;        /*stackの末尾（＝データサイズ）を表す*/

/*関数原型宣言*/
void error(char* scr); /*エラー操作を知らせて強制停止する関数*/
void push(stack inp);  /*スタックにデータを積む(push)関数*/
stack pop(void);       /*スタックの一番上のデータを拾う(pop)関数*/
stack size(void); /*スタックのサイズを返す関数*/

/*スタックにデータを積む(push)関数*/
void push(stack inp) {
  if (gStackNum == G_STACK_SIZE) { /*gStackが範囲外参照になった場合はエラー出力*/
    error("error:push:gStack is full!");
  }
  gStack[gStackNum++] = inp;
  return;
}

/*スタックの一番上のデータを拾う(pop)関数*/
stack pop(void) {
  if (gStackNum == 0) {
    error("error:pop:gStack is empty!"); /*gStackが空の場合はエラー出力*/
  }
  return gStack[gStackNum--];
}

/*スタックのサイズを返す関数*/
stack size(void) {
  return gStackNum;
}

/*エラー操作を知らせて強制停止する関数*/
void error(char* scr) {
  fflush(stdout);
  fprintf(stderr, "%s/n", scr); /*標準エラー出力*/
  exit(1);                      /*異常強制終了*/
}
