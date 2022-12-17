#include<stdio.h>

void sort(int a[], int l,int r, int reverse = 0){
	int sign;
	if(reverse==0)sign=1;
	else sign=-1;
	
	int i=l,j=r;
	int key=a[(l+r)/2];
	while(i<=j){
		while(sign*a[i]<sign*key)
			i++;
		while(sign*a[j]>sign*key)
			j--;
		if(i<=j){
			int t=a[i];a[i]=a[j];a[j]=t;
			i++;j--;
		}
	}
	if(l<j) sort(a,l,j,reverse);
	if(r>i) sort(a,i,r,reverse);
}

int main(){
	int a[10]={13,8,74,9,6,78,25,74,13,84};
	for(int i=0;i<10;i++){
		printf("%d ",a[i]);
	}printf("\n");
	sort(a,0,9);
	for(int i=0;i<10;i++){
		printf("%d ",a[i]);
	}
}
