#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void Sort_Quick(int a[], long l,long r){
	long i=l,j=r;
	long key=a[(l+r)/2];
	while(i<=j){
		while(a[i]<key)
			i++;
		while(a[j]>key)
			j--;
		if(i<=j){
			int t=a[i];a[i]=a[j];a[j]=t;
			i++;j--;
		}
	}
	if(l<j) Sort_Quick(a,l,j);
	if(r>i) Sort_Quick(a,i,r);
}


void Sort_Bubble(int a[], long n){
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


void Sort_Choose(int a[], long n){
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


void Sort_Insert(int a[], long n){
	for(long i=1;i<n;i++){//升序
		//查找插入位置
		int l=0,r=i-1;
		int m;
		while(l<=r){
			m=(l+r)/2;
			if(a[m]<=a[i]){
				l=m+1;
			}else{
				r=m-1;
			}
		}//要插入的位置是l
		
		//腾出空位
		int t=a[i];
		for(int j=i;j>l;j--){
			a[j]=a[j-1];
		}
		a[l]=t;
	}
}
#define MAX 50000
int array[4][MAX];

int main(){
	clock_t start, finish;
	int delta;
	srand(time(NULL));
	printf("---各种排序算法效果对比---\n");
	printf("创建随机数据ing...\n");
	printf("待排序数据总量: %d\n\n",MAX);
	for(long i=0;i<MAX;i++){
		array[0][i]=rand()%10000;
		array[1][i]=rand()%10000;
		array[2][i]=rand()%10000;
		array[3][i]=rand()%10000;
//		printf("%d\n",a[i]);
	}
	//快速排序运行时间
	start = clock();
	Sort_Quick(array[0],0,MAX-1);
	finish = clock();
	delta=finish-start;
	printf("快速排序运行时间: %d ms\n", delta);
	//冒泡排序运行时间
	start = clock();
	Sort_Bubble(array[1],MAX);
	finish = clock();
	delta=finish-start;
	printf("冒泡排序运行时间: %d ms\n", delta);
	//选择排序运行时间
	start = clock();
	Sort_Choose(array[2],MAX);
	finish = clock();
	delta=finish-start;
	printf("选择排序运行时间: %d ms\n", delta);
	//插入排序运行时间
	start = clock();
	Sort_Insert(array[3],MAX);
	finish = clock();
	delta=finish-start;
	printf("插入排序运行时间: %d ms\n", delta);
	return 0;
}
