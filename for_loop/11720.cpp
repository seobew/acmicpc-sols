#include <stdio.h>
int main(){
	int cases;
	scanf("%d", &cases);
	char c[cases];
	fgets(c, 2, stdin);
	fgets(c, cases+1, stdin);
	int sum = 0;
	for(int a = 0; a<cases; a++){
		int temp = c[a] - '0';
		sum +=temp;
	}
	printf("%d\n", sum);
}
