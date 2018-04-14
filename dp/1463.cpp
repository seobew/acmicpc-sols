#include <stdio.h>
int dp[1000000];

int min_func(int a, int b){
	if(a>b){
		return b;
	}else{
		return a;
	}
}

int main(){
	int num;
	scanf("%d", &num);
	dp[1] = 0; // 1
	dp[2] = 1; // 2
	dp[3] = 1; // 3
	for(int i = 4; i<num+1; i++){
		int temp1 = 100;
		int temp2 = 100;
		if(i%3 == 0){
			temp1 = dp[i/3] + 1;
		}
		else if(i%2 == 0){
			temp1 = dp[i/2] + 1;
		}
		temp2 = dp[i-1] + 1;
		dp[i] = min_func(temp1, temp2);
	}
	printf("%d\n", dp[num]);
}
