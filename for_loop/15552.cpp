#include <stdio.h>
int main(){
	long long cases;
	scanf("%llu", &cases);
	for(int i = 0; i<cases; i++){
		int a,b;
		scanf("%d", &a);
		scanf("%d", &b);
		printf("%d\n", a+b);
	}
}
