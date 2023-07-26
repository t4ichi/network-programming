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
  struct sCell *p,*p1,*p2,*pw;
  int n = 0;
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

  // ----- delete -------
  p = p1 = top;
  p2 = NULL;

  if(p != NULL){
    if(p->next != NULL){
      p->next = p->next->next;
    }
  }
  // --------------------
  p=top;
  while(p) {
  printf("%s\n",p->buf); p=p->next;
  }
}
