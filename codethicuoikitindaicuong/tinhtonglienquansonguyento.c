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
	int sum = 0;
	int k;
	for(i =0;i<n;i++){
		int j;
		k = 1;
		for(  j=2 ;j<a[i];j++){
			if((a[i]%j == 0) && (a[i] >0)){
				k = 0;
				break;
			
			}
		}
		
		if(k == 0 && a[i] > 1){
			s[i] = 'K';
		}
		else if(k ==1 && a[i] > 1){
			s[i] = 'T';
		}
		else if (k ==1 && a[i] <= 0){
			s[i] = 'A';
		}else if(a[i]==1){
			s[i] = 'K';
		} 
    }
	printf("\n");
	for(i = 0;i<n;i++){
		printf("%c ", s[i]);
		sum += s[i];
	}
	printf("\n%d", sum);
}
