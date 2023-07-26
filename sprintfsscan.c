#include <stdio.h>
void main(){
  char buf[128];
  int a=123,b=456;
  sprintf(buf,"%d %d",a,b);
  printf("%s\n",buf);
  sscanf(buf,"%d %d",&b,&a);
  sprintf(buf,"%d %d",a,b);
  printf("%s\n",buf);
}
