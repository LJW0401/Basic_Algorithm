#include<stdio.h>

int find_baisc(int a[],int n,int value,int reverse=0){//基础版本
	int sign;
	if(reverse==0)sign=1;
	else sign=-1;
	
	int l=0,r=n-1;
	int m;
	while(l<=r){
		m=(l+r)/2;
		if(a[m]==value){
			return m;
		}else if(sign*a[m]<sign*value){
			l=m+1;
		}else{
			r=m-1;
		}
	}
}

int main(){
	int a[10]={6, 8, 13, 13, 13, 25, 74, 74, 78, 84};

	for(int i=0;i<10;i++){
		printf("%d ",a[i]);
	}printf("\n");
	
	printf("%d",find_baisc(a,10,13));
}
