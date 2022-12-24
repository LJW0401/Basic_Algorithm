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

#define NUM 10000000
int array[1][NUM];

int main(){
	clock_t start, finish;
	int delta;
	srand(time(NULL));
	
	printf("---快速排序---\n");
	printf("数据量：%d\n\n",NUM);
	for(long i=0;i<NUM;i++){
		array[0][i]=rand()%10000;
	}
	
	start = clock();
	Sort_Quick(array[0],0,NUM-1);
	finish = clock();
	delta=finish-start;
	printf("快速排序运行时间: %d ms\n", delta);
	
	
//	for(int i=0;i<NUM;i++){
//		printf("%d ",array[0][i]);
//	}
}
