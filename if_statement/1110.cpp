#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int count = 1;
	int prev = n;
	int pre_next = n;
	int next = n;
	if(n<10){
		pre_next = prev;
	}else{
		pre_next = prev/10 + prev%10;
	}
	next = (prev%10)*10 + pre_next%10;
	prev = next;
	while(1){
		if(next == n){
			break;
		}
		if(prev<10){
			pre_next = prev;
		}else{
			pre_next = prev/10 + prev%10;
		}
		next = (prev%10)*10 + pre_next%10;
		prev = next;
		count++;
	}
	printf("%d\n", count);
	return 0;
}
