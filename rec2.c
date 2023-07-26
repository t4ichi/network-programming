#include<stdio.h>
int sum(int n);

int main(){
	printf("%d\n",sum(10));
}

int sum(int i){
	if(i > 0){
		 return i + sum(i-1);

	}
	else{
		return 0;
	}
}

