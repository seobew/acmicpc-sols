#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int index = n;
	while(n-->0){
		printf("%d\n", index--);
	}
}
