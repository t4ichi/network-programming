#include <stdio.h>
int sum(int i){
    if(i < 1) return 0;
    printf("%p\n",&i);
    return sum(i-1) + i;
}

int main(){
    printf("%d\n",sum(10));
}