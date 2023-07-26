#include <stdio.h>
int main(){
    int i = 123,*ip;
    printf("%d\n",i);
    ip = &i;
    *ip = 456;
    printf("%d\n",i);
}