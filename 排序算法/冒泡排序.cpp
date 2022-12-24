#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/*基础版冒泡排序*/
void Sort_Bubble(int a[], long n){
	for(long i=0;i<n-1;i++){
		for(long j=n-1;j>i;j--){
			if(a[j-1]>a[j]){
				int t=a[j];a[j]=a[j-1];a[j-1]=t;
			}
		}
	}
}

/*第1次改进，没有交换时停止*/
void Sort_Bubble_I(int a[], long n){
	int flag=0;
	
	for(long i=0;i<n-1;i++){
		for(long j=n-1;j>i;j--){
			if(a[j-1]>a[j]){
				int t=a[j];a[j]=a[j-1];a[j-1]=t;
				flag=1;
			}
		}
		if(!flag) break;
	}
}

/*第2次改进，双向冒泡，一次确定2个值*/
void Sort_Bubble_II(int a[], long n){
	int flag=0;
	
	long l=0,r=n-1;
	while(l<r){
		for(long i=l;i<r;i++){
			if(a[i]>a[i+1]){
				int t=a[i];a[i]=a[i+1];a[i+1]=t;
				flag=1;
			}
		}
		r--;
		for(long i=r-1;i>=l;i--){
			if(a[i]>a[i+1]){
				int t=a[i];a[i]=a[i+1];a[i+1]=t;
				flag=1;
			}
		}
		l++;
		if(!flag) break;
	}
}

#define MAX 5000
int main(){
	clock_t start, finish;
	int delta;
	srand(time(NULL));
	int array[3][MAX];
	
	printf("---冒泡排序---\n");
	printf("数据量：%d\n\n",MAX);
	for(long i=0;i<MAX;i++){
		array[0][i]=rand()%10000;
		array[1][i]=rand()%10000;
		array[2][i]=rand()%10000;
	}
	
	start = clock();
	Sort_Bubble(array[0],MAX);
	finish = clock();
	delta=finish-start;
	printf("原始冒泡排序运行时间: %d ms\n", delta);
	
	start = clock();
	Sort_Bubble_I(array[1],MAX);
	finish = clock();
	delta=finish-start;
	printf("冒泡排序改进1次运行时间: %d ms\n", delta);
	
	start = clock();
	Sort_Bubble_II(array[2],15);
	finish = clock();
	delta=finish-start;
	printf("冒泡排序改进2次运行时间: %d ms\n", delta);
	
//	for(int i=0;i<15;i++){
//		printf("%d ",array[2][i]);
//	}
}
