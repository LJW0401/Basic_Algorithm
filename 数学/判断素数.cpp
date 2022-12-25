#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*基础版本*/
int Is_Prime(long x){
	if(x<2)
		return 0;
	for(long i=2;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}

/*改进1，先判断偶数，将判断次数减半*/
int Is_Prime_I(long x){
	if(x<2)
		return 0;
	if(x==2)
		return 1;
	if(x%2==0)
		return 0;
	for(long i=3;i*i<=x;i+=2){
		if(x%i==0) return 0;
	}
	return 1;
}

int main(){
	srand(time(NULL));
	clock_t start, finish;
	int delta;
	
	long x=rand();
	printf("待判断数：%ld\n",x);
	
	start=clock();
	printf("%s",Is_Prime(x)==1?"is prime\n":"is not prime\n");
	finish=clock();
	delta=finish-start;
	printf("第0次改进运行时间：%d ms\n",delta);
	
	start=clock();
	printf("%s",Is_Prime(x)==1?"is prime\n":"is not prime\n");
	finish=clock();
	delta=finish-start;
	printf("第1次改进运行时间：%d ms\n",delta);
	
	
	return 0;
}
