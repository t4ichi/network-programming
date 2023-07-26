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

  //-----reverse--------
  p = p1 = top;
  p2 = NULL;

  if(p != NULL){
    n = 0;
    while(p->next){
      p1 = p->next;
      p->next = p2;
      p2 = p;
      p = p1;

      printf("n:%d\n",n);    
      pw = p1;
      printf("p1:");
      while(pw) {
        printf("%s ",pw->buf); pw=pw->next;
      }
      printf("\n");
      
      pw = p2;
      printf("p2:");
      while(pw) {
        printf("%s ",pw->buf); pw=pw->next;
      }
      printf("\n----------\n");
      n++;
    }
    p->next = p2;
    top = p;
  }
  // --------------------
  p=top;
  while(p) {
  printf("%s\n",p->buf); p=p->next;
  }
}
