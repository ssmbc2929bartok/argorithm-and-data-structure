#include <stdio.h>
#include <stdlib.h>

/*グローバル変数など*/
typedef int linList;  /*もしint型以外を使いたいときはここを変更してね*/
typedef struct cell { /*連結リストのセル*/
  linList value;      /*実際の値*/
  struct cell* next;  /*次のセルへのポインタ*/
} LIST_CELL;
LIST_CELL gFront = {-1, NULL}; /*連結リストの先頭*/

/*関数原型宣言*/
void insert(LIST_CELL* pre, LIST_CELL* new);       /*連結リストにセルを挿入する関数*/
LIST_CELL* ns_insert(LIST_CELL* pre, linList val); /*動的に次のセルを生成する関数*/
void error(char* scr);                             /*エラー操作を知らせて強制停止する関数*/
void append(linList val);                          /*連結リストの末尾の次にセルを値valのセルを追加する関数*/
void printList();                                  /*連結リストのデータを表示する関数*/
void inputList(char* str[], int len);              /* 文字列配列からリストを作成する関数 */
void sortList();                                   /*連結リストをソートする関数*/

/*連結リストにセルを挿入する関数*/
void insert(LIST_CELL* pre, LIST_CELL* new) {
  if (pre == NULL || new == NULL) {
    error("error:insert:pre or new is NULL!");
  }
  new->next = pre->next; /*newの次ポインタをpreの次セルにつなげる*/
  pre->next = new;       /*preの次ポインタをnewにつなげる（＝preの次セルをnewに変更）*/
}

/*動的に次のセルを生成する関数*/
LIST_CELL* ns_insert(LIST_CELL* pre, linList val) {
  LIST_CELL* new; /*生成したセルを指すポインタ*/

  if (pre == NULL) {
    error("error:ns_insert:pre is NULL!"); /*基準となるセルが存在しないときエラー出力*/
  }

  new = malloc(sizeof(LIST_CELL));
  if (new == NULL) {
    error("error:ns_insert:Insufficient memory space!"); /*mallocが失敗したらエラー出力*/
  }

  new->value = val;      /*値valを格納*/
  new->next = pre->next; /*newをpreの次に挿入*/
  pre->next = new;

  return new;
}

/*連結リストの末尾の次にセルを値valのセルを追加する関数*/
void append(linList val) {
  LIST_CELL* cur = &gFront;   /*curという*/
  while (cur->next != NULL) { /*最後のセル(next = NULLのセル)までたどる*/
    cur = cur->next;
  }
  ns_insert(cur, val);
}

/*連結リストのデータを表示する関数*/
void printList() {
  LIST_CELL* cur = gFront.next;
  printf("LIST[ ");
  while (cur != NULL) { /*今いる場所が空になるまで進む*/
    printf("%d ", cur->value);
    cur = cur->next;
  }
  printf("]\n");
}

/* 文字列配列からリストを作成する関数 */
void inputList(char* str[], int len) {
  for (int i = 0; i < len; i++) {
    /* 文字列を整数に変換 */
    int val = atoi(str[i]);

    /* リストの末尾に追加 */
    append(val);
  }
}

/* 2つのソート済みリストをマージする（本体） */
LIST_CELL* merge(LIST_CELL* left, LIST_CELL* right) {
  if (left == NULL) return right;
  if (right == NULL) return left;

  LIST_CELL* result = NULL;

  /* 小さい方の値を先頭にして、再帰的に繋いでいく */
  if (left->value <= right->value) {
    result = left;
    result->next = merge(left->next, right);
  } else {
    result = right;
    result->next = merge(left, right->next);
  }
  return result;
}

/* リストを分割してソートする（司令塔） */
LIST_CELL* mergeSort(LIST_CELL* head) {
  /* 要素が0または1つなら、すでにソート済み */
  if (head == NULL || head->next == NULL) {
    return head;
  }

  /* 1. ウサギとカメで中央を見つける */
  LIST_CELL* slow = head;
  LIST_CELL* fast = head->next;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  /* 2. リストを真っ二つに切る */
  LIST_CELL* middle = slow->next;
  slow->next = NULL;

  /* 3. 左右それぞれをソートして、最後にマージ */
  return merge(mergeSort(head), mergeSort(middle));
}

/*連結リストをソートする関数*/
void sortList() {
  gFront.next = mergeSort(gFront.next);
}

/*エラー操作を知らせて強制停止する関数*/
void error(char* scr) {
  fflush(stdout);
  fprintf(stderr, "%s\n", scr); /*標準エラー出力*/
  exit(1);                      /*異常強制終了*/
}
