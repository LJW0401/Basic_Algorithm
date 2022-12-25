#include<stdio.h>
#include<time.h>
/*暴力求法，枚举*///仅限求正数的，但负数同理
long Greatest_Common_Divisor(long x,long y){
	if(x<y){long t=x;x=y;y=t;}
	
	for(long i=y;i>0;i--){
		if(x%i==0 && y%i==0){
			return i;
		}
	}
}

/*辗转相除法*///仅限求正数的，但负数同理
long Greatest_Common_Divisor_I(long x,long y){
	if(x<y){long t=x;x=y;y=t;}
	long r=x%y;
	if(r==0){
		return y;
	}
	return Greatest_Common_Divisor_I(y,r);
}

int main(){
	clock_t start,finish;
	long delta;
	long x=12  ;
	long y=18  ;
	
	start=clock();
	printf("%ld和%ld的最大公约数是%ld\n",x,y,Greatest_Common_Divisor(x,y));
	finish=clock();
	delta=finish-start;
	printf("暴力法运行时间：%ld ms\n",delta);
	
	
	start=clock();
	printf("%ld和%ld的最大公约数是%ld\n",x,y,Greatest_Common_Divisor_I(x,y));
	finish=clock();
	delta=finish-start;
	printf("辗转相除法运行时间：%ld ms\n",delta);
	
	return 0;
}
