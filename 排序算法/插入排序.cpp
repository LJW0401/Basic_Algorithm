#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/*原始算法*/
void Sort_Insert(int a[], long n){
	for(long i=1;i<n;i++){
		int j=i;
		while(j>0 && a[j]<a[j-1]){
			int t=a[j-1];a[j-1]=a[j];a[j]=t;
			j--;
		}
	}
}

/*第1次改进，采用对分查找的思想*/
void Sort_Insert_I(int a[], long n){
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

#define NUM 100000
int main(){
	clock_t start, finish;
	int delta;
	srand(time(NULL));
	int array[3][NUM];
	
	printf("---插入排序---\n");
	printf("数据量：%d\n\n",NUM);
	for(long i=0;i<NUM;i++){
		array[0][i]=rand()%10000;
		array[1][i]=rand()%10000;
		array[2][i]=rand()%10000;
	}
	
	start = clock();
	Sort_Insert(array[0],NUM);
	finish = clock();
	delta=finish-start;
	printf("插入排序第0次改进运行时间: %d ms\n", delta);

	start = clock();
	Sort_Insert_I(array[1],NUM);
	finish = clock();
	delta=finish-start;
	printf("插入排序第1次改进运行时间: %d ms\n", delta);
	
//	for(int i=0;i<NUM;i++){
//		printf("%d ",array[1][i]);
//	}
}
