#include<stdio.h>
void count(int n);

int main(){
	count(10);
}

void count(int n){
	if(n > 0){
		printf("%d\n",n);
		count(n-1);
	}
}
