#include<stdio.h>

void sort(int a[], int n, int reverse = 0){
	int sign;
	if(reverse==0)sign=1;
	else sign=-1;
	
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--){
			if(sign*a[j-1]>sign*a[j]){
				int t=a[j];a[j]=a[j-1];a[j-1]=t;
			}
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
