#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BSIZE 256
struct sCell {
  char buf[BSIZE] ;
  struct sCell *next;
};
struct sCell *top;
int main() {
  struct sCell *p,*p1,*p2;
  char ibuf[BSIZE];
  top=NULL;
  int cnt = 0;
  while (scanf("%s",ibuf)>0) {
    p=(struct sCell*)malloc(sizeof(struct sCell));
    strncpy(p->buf,ibuf,BSIZE);
    p->next=top;
    top=p;
  }
  printf("\n\n");

  // 最後の要素を先頭に移動
  p=top;
  while(p->next->next != NULL) p = p->next;
  p2 = p->next;
  p2->next = NULL;
  p->next = NULL;
  printf("last %s",p2);
  p2->next = top;
  top = p2;
  // --------------------
  
  p=top;
  while(p) {
  printf("%s\n",p->buf); p=p->next;
  }
}
