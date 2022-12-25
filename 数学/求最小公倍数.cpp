#include<stdio.h>
#include<time.h>
/*暴力求法，枚举*///仅限求正数的，但负数同理
long Least_Common_Multiple(long x,long y){
	long z=x>y?x:y;
	while(z%x!=0||z%y!=0){
		z++;
	}
	return z;
}

/**///仅限求正数的，但负数同理
long Least_Common_Multiple_I(long x,long y){

}

int main(){
	clock_t start,finish;
	long delta;
	long x=12  ;
	long y=18  ;
	
	start=clock();
	printf("%ld和%ld的最小公倍数是%ld\n",x,y,Least_Common_Multiple(x,y));
	finish=clock();
	delta=finish-start;
	printf("暴力法运行时间：%ld ms\n",delta);
	
	
//	start=clock();
//	printf("%ld和%ld的最小公倍数是%ld\n",x,y,Greatest_Common_Divisor_I(x,y));
//	finish=clock();
//	delta=finish-start;
//	printf("辗转相除法运行时间：%ld ms\n",delta);
	
	return 0;
}
