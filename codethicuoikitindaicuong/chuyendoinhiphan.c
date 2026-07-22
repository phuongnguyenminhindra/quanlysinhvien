#include<stdio.h>
#include<string.h>
#define MAX_LEN 100
int kiemtra(const char str[]){
	int len = strlen(str);
	if(len == 0) return 0;
	int i;
	for(i = 0;i<len;i++){
		if(str[i] != '0' && str[i] != '1'){
			return 0;
		}
	}
	return 1;
}
long long chuyendoi(const char str[]){
	long long decimalValue = 0;
	int len = strlen(str);
	int i;
	for(i = 0;i<len;i++){
		decimalValue = (decimalValue << 1) + (str[i]-'0');
	}
	return decimalValue;
}
int main(){
	char nhiphan[MAX_LEN];
	
	while(1){
		fgets(nhiphan,sizeof(nhiphan),stdin);
		nhiphan[strcspn(nhiphan,"\n")] = '\0';//chuyen\n thanh\0
		if(kiemtra(nhiphan) == 1){
			break;
			
		
		}
	}
	long long result = chuyendoi(nhiphan);
	printf("%lld",result);
}
