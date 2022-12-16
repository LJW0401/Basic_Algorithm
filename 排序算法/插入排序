#include<stdio.h>

void sort(int a[], int n, int reverse = 0){
	int sign;
	if(reverse==0)sign=1;
	else sign=-1;
	
	for(int i=0;i<n;i++){
		int j=i;
		while(j>0 && sign*a[j]<sign*a[j-1]){
			int t=a[j-1];a[j-1]=a[j];a[j]=t;
			j--;
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
