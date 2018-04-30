#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int index = 0;
	while(n-->0){
		printf("%d\n", ++index);
	}
}
