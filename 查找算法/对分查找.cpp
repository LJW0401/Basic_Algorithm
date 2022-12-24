#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <windows.h>

void Sort_Quick(long a[], long l,long r){
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

//升序
long Binary_Search(long a[],long n,long value){//基础版本
	int l=0,r=n-1;
	int m;
	while(l<=r){
		m=(l+r)/2;
		if(a[m]==value){
			return m;
		}else if(a[m]<value){
			l=m+1;
		}else{
			r=m-1;
		}
//		Sleep(1);
	}
	return -1;
}

long Binary_Search_I(long a[],long n,long value){//找对应值端点位置
	long l=0,r=n-1;
	int m;
	while(l<=r){
		m=(l+r)/2;
		if(a[m]<value){
			l=m+1;
		}else{//等于时左移，寻找左端点位置
			r=m-1;
		}
//		Sleep(1);
	}
	return l;//结束时r<l
}

#define NUM 50000
long array[NUM];

int main(){
	clock_t start, finish;
	int delta;
	int value;
	long pos;
	srand(time(NULL));
	for(long i=0;i<NUM;i++){
		array[i]=rand();
	}
	
	printf("---对分查找---\n");
	printf("数据量：%d\n\n",NUM);
	
	start = clock();
	Sort_Quick(array,0,NUM-1);
	finish = clock();
	delta=finish-start;
	printf("快速排序运行时间: %d ms\n\n", delta);
//	for(int i=0;i<NUM;i++){
//		printf("%d ",array[i]);
//	}printf("\n");
	
	value = array[rand()%NUM];
	printf("待查找的数据是 %d\n\n",value);
	start = clock();
	pos = Binary_Search(array,NUM,value);
	finish = clock();
	delta=finish-start;
	printf("找到的位置：%ld\n",pos);
	if(pos>=0){
		if(pos>0)   printf("array[%ld]=%ld, ",pos-1,array[pos-1]);
		printf("array[%ld]=%ld, ",pos,array[pos]);
		if(pos<NUM) printf("array[%ld]=%ld\n",pos+1,array[pos+1]);
	}
	printf("对分查找运行时间: %d ms\n\n", delta);
	
	
	start = clock();
	pos = Binary_Search_I(array,NUM,value);
	finish = clock();
	delta=finish-start;
	printf("找到的左端点的位置：%ld\n",pos);
	if(pos>=0){
		if(pos>0)   printf("array[%ld]=%ld, ",pos-1,array[pos-1]);
		printf("array[%ld]=%ld, ",pos,array[pos]);
		if(pos<NUM) printf("array[%ld]=%ld\n",pos+1,array[pos+1]);
	}
	printf("对分查找运行时间: %d ms\n\n", delta);
	
	return 0;
}
