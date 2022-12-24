#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/*基础版选择排序*/
void Sort_Choose(int a[], long n){
	for(long i=0;i<n-1;i++){
		long k = i;
		for(long j=i+1;j<n;j++){
			if(a[k]>a[j])
				k=j;
		}
		if(k!=i){
			int t=a[i];a[i]=a[k];a[k]=t;
		}
	}
}

/*改进1，在一次选择中同时确定最大和最小值*/
void Sort_Choose_I(int a[], long n){
	long l=0,r=n-1;
	while(l<r){
		long p=l,q=r;
		
		for(long i=l;i<=r;i++){
			if(a[p]>a[i]){
				p=i;
			}
			if(a[q]<a[i]){
				q=i;
			}
		}
		if(l!=p){
			int t=a[p];a[p]=a[l];a[l]=t;
		}
		if(q==l){
			q=p;
		}
		if(r!=q){
			int t=a[q];a[q]=a[r];a[r]=t;
		}
		r--;l++;
	}
}

#define NUM 100000
int main(){
	clock_t start, finish;
	int delta;
	srand(time(NULL));
	int array[3][NUM];
	
	printf("---选择排序---\n");
	printf("数据量：%d\n\n",NUM);
	for(long i=0;i<NUM;i++){
		array[0][i]=rand()%10000;
		array[1][i]=rand()%10000;
		array[2][i]=rand()%10000;
	}
	
	start = clock();
	Sort_Choose(array[0],NUM);
	finish = clock();
	delta=finish-start;
	printf("选择排序改进0次序运行时间: %d ms\n", delta);
	
	start = clock();
	Sort_Choose_I(array[1],NUM);
	finish = clock();
	delta=finish-start;
	printf("选择排序改进1次序运行时间: %d ms\n", delta);

	
//	for(int i=0;i<10;i++){
//		printf("%d ",array[1][i]);
//	}
}
