#include <stdio.h>
bool check_hansu(int num){
	if(num<100){
		return true;
	}else{
		int diff;
		int prev;
		//prev = num%10;
		diff = (num%10)-(num%100)/10;
		while(num/10 >0){
			if((num%10-(num%100)/10)!=diff){
				return false;
			}
			num = num/10;
		}
		return true;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int count = 0;
	for(int i = 1; i<=n; i++){
		if(check_hansu(i)){
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
