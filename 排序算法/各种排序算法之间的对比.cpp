#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void Sort_Quick(int a[], int l,int r, int reverse = 0){
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
	if(l<j) Sort_Quick(a,l,j,reverse);
	if(r>i) Sort_Quick(a,i,r,reverse);
}


void Sort_Bubble(int a[], int n, int reverse = 0){
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


void Sort_Choose(int a[], int n, int reverse = 0){
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


void Sort_Insert(int a[], int n, int reverse = 0){
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
#define MAX 20000
int array[4][MAX];

int main(){
	clock_t start, finish;
	int delta;
	srand(time(NULL));
	printf("---各种排序算法效果对比---\n");
	printf("创建随机数据ing...\n");
	printf("待排序数据总量: %d\n\n",MAX);
	for(int i=0;i<MAX;i++){
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
