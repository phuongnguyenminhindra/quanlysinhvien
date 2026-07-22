#include<stdio.h>
int main(){
	int n;
	do{
	
	scanf("%d",&n);
    }while((n<0) || (n==0));
    int a= n%10;
    n/=10;
    int b;
    int k =0;
    while(n!=0){
    
    	b = n%10;
    	if(b<=a){
    		k =1;
    		break;
		}
		a=b;
		n/=10;
	}
	if(k==1){
		printf("Khong phai la so lui");
	}else if(k == 0){
		printf("La so lui");
	}
}
