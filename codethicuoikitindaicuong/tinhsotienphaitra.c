#include<stdio.h>
//Phuong phap vet can
/*
int main(){
	int n;
	do{
		scanf("%d", &n);
	}while(n<0 || n > 100000 || n%100 !=0);
	int x,y,z;
	for(x = 0; x<= n/500;x++){
		for(y= 0; y<= n/200;y++){
			for(z= 0 ; z<= n/100;z++){
				if(500*x+200*y+100*z==n){
					printf("%d %d %d\n", x,y,z);
				}
			}
		}
	}
	
}
*/
//Cach 2 toi uu
int main(){
	int n;
	do{
		scanf("%d", &n);
	}while(n<0 || n > 100000 || n%100 !=0);
	int x,y,z;
	for(x = 0; x<= n/500;x++){
		for(y= 0; y<= (n-500*x)/200;y++){
			z = (n-500*x-200*y)/100;
			if((z > 0) || (z ==0)){
			
				if(500*x+200*y+100*z==n){
					printf("%d %d %d\n", x,y,z);
				}
			}
		}
	}

}
	

