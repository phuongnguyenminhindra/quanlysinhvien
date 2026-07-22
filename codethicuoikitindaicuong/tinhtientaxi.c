#include<stdio.h>
int main(){
	double n;
	do{
		scanf("%lf", &n);
		
	}while(n<=0 || n>= 200);
	double sum = 0;
	if(n <= 1){
		sum =15000;
	}else if((n>1) && (n<=5)){
		sum = 15000+(n-1)*13500;
		
	}else if(n>5){
		sum = 15000+13500*4+(n-5)*11000;
	}
	if(n>120){
		sum = sum *90/100;
	}
	printf("%.0lf", sum);
}
