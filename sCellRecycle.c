#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BSIZE 256
struct sCell {
  char buf[BSIZE] ;
  struct sCell *next; /////
};
struct sCell *top,*recycle;

void main() {
  struct sCell *p,*p1,*p2,*pw;
  char ibuf[BSIZE];
  recycle=NULL;      /////
  while(1){
    top=NULL;
    while (scanf("%s",ibuf)>0) {
      if(recycle) {
        printf("Recycle\n");
        p=recycle;
	recycle=recycle->next;
      } else {
        printf("New\n");
        p=(struct sCell*)malloc(sizeof(struct sCell));
      }
      strncpy(p->buf,ibuf,BSIZE);
      p->next=top;
      top=p;
      if(ibuf[0] == 'q') break;
    }

    printf("\n\n");

////////
    p=p1=top;
    p2=NULL;
    if(p!=NULL) {
      while(p->next) {
        p1=p->next;
        p->next=p2;
        p2=p;
        p=p1;
      }
      p->next=p2; 
      top=p;
    }
////////
    printf("\n==Top==================\n");
    p=top;
    while(p) {
      printf("%s\n",p->buf); p=p->next;
    }
    printf("\n====================\n");
 
    //char key='n';          ///// 
    //printf("ReTry(y/n)");  /////
    //scanf("%c",&key);      /////
    //if(key!='y') break;    /////

    p=top;
    while(p) {
      top=p->next;
      p1=p->next;
      p->next=recycle;
      recycle=p;
      p=p1;
    }
    printf("\n==Recycle==================\n");
    p=recycle;
    while(p) {
      printf("%s\n",p->buf); p=p->next;
    }
    printf("\n====================\n");

  }
}

