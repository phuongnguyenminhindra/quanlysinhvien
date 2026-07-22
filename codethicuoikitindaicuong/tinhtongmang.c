#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int i=0;
	for( i=0;i<n;i++){
		scanf("%d", &a[i]);
		
	}
	for( i=0;i<n;i++){
		printf("%d ",a[i]);
	
	}
	int s[n];
	int sum =0;
	for( i =0;i<n;i++){
		if((a[i]%2==0) && (a[i] !=0)){
			s[i] = 'C';
		}
		else if(a[i] == 0){
			s[i] = 'K';
		}
		else if(a[i] % 2 != 0){
			s[i] = 'L';
		}
		
	}
	printf("\n");
	for( i = 0; i<n;i++){
		printf("%c ", s[i]);
		sum += s[i];
	}
	printf("\n%d", sum);
	
}
