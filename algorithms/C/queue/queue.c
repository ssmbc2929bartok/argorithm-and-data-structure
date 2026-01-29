#include <stdio.h>
#include <stdlib.h>

/*グローバル変数など*/
#define G_QUEUE_SIZE 10         /*queueの大きさ。必要に応じて変更してね*/
typedef int queue;              /*もしint型以外を使いたいときはここを変更してね*/
queue gQueue[G_QUEUE_SIZE + 1]; /*queue本体*/
queue gQueueFront = 0;          /*queueの先頭を表す*/
queue gQueueTail = 0;           /*queueの末尾を表す*/
queue gQueueSize = 0;           /*queueのサイズを表す*/

/*関数原型宣言*/
void enqueue(queue inp);  /*待ち行列の末尾にデータを格納する関数*/
queue dequeue(void);      /*待ち行列の末尾にデータを格納する関数*/
queue size(void);         /*待ち行列の大きさを返す関数*/
void ringBuff(queue end); /*リングバッファ実現用関数*/
void error(char* scr);    /*エラー操作を知らせて強制停止する関数*/

/*待ち行列の末尾にデータを格納する関数*/
void enqueue(queue inp) {
  if (gQueueFront + 1 == gQueueTail) {
    error("error:dequeue:gQueue is full!"); /*gQueueがいっぱいの場合はエラー出力*/
  }
  gQueue[gQueueTail++] = inp;
  ringBuff(gQueueTail);
  return;
}

/*待ち行列の末尾にデータを格納する関数*/
queue dequeue(void) {
  if (gQueueFront == gQueueTail) {
    error("error:dequeue:gQueue is empty!"); /*gQueueが空の場合はエラー出力*/
  }
  int dq = gQueue[gQueueFront++];
  ringBuff(gQueueFront);
  return dq;
}

/*待ち行列の大きさを返す関数*/
queue size(void) {
  return gQueueSize;
}

/*リングバッファ実現用関数*/
void ringBuff(queue end) {
  if (end == G_QUEUE_SIZE) { /*もしgQueueの終端まで来たら、先頭へ送り返す*/
    end = 0;                 /*この終端のようなデータを「番兵(sentinel)」という*/
  }
}

/*エラー操作を知らせて強制停止する関数*/
void error(char* scr) {
  fflush(stdout);
  fprintf(stderr, "%s\n", scr); /*標準エラー出力*/
  exit(1);                      /*異常強制終了*/
}
