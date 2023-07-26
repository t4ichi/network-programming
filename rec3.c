#include<stdio.h>
int perm(int kn,int n,int pn);
int koma[100];

int main(){
	int i,kn,pn;
	for(kn = 2;kn <= 4;kn++){
		for(i = 0;i < kn;i++){
			koma[i] = i + 1;
		}
		printf("--N=%02d -- \n",kn);
		pn = perm(kn,kn,0);
		printf("\t<%d>\n\n",pn);
	}
}

int perm(int kn,int n,int pn){
	int i,n1,w;
	if(n > 1){
		for(n1 = 0;n1 < n;n1++){
			w = koma[0];
			for(i = 0;i < n-1;i++){
				koma[i] = koma[i+1];
			}
			koma[n-1] = w;
			pn = perm(kn,n-1,pn);
		}
	}
	else{
		for(i = 0;i < kn;i++){
			printf("%1d",koma[i]);
		}
		printf("\n");
		pn++;
	}
	return pn;
}

