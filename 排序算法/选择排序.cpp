#include<stdio.h>

void sort(int a[], int n, int reverse = 0){
	int sign;
	if(reverse==0)sign=1;
	else sign=-1;
	
	for(int i=0;i<n-1;i++){
		int k = i;
		for(int j=i+1;j<n;j++){
			if(sign*a[k]>sign*a[j]){
				k=j;
			}
		}
		if(k!=i){
			int t=a[i];a[i]=a[k];a[k]=t;
		}
	}
}

int main(){
	int a[10]={13,8,74,9,6,78,25,74,13,84};
	for(int i=0;i<10;i++){
		printf("%d ",a[i]);
	}printf("\n");
	sort(a,10);
	for(int i=0;i<10;i++){
		printf("%d ",a[i]);
	}
}
