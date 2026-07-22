#include<stdio.h>
int main(){
	int n;
	do{
		scanf("%d", &n);
	}while(n<=0 || n >= 100000 );
	int a[10];
	int i;
	int count =0;
	for(i = 0;i<10;i++){
		if(n!=0){
			a[i] = n%10;
			n/=10;
			count =i;
			if(n==0){
				break;
			}
			
			
		}
		
		
		
	}
	for(i = 0; i<=count;i++){
		printf("%d",a[i]);
	}
}
