#include <stdio.h>
int fin;
int cost[300];
int dp[300];

// a b c d
// -> a c d or b d
// -> dp[i] = MAX(dp[i-3] + cost[i-1] + cost[i], dp[i-2] + cost[i])

int max_func(int a, int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int main(){
	scanf("%d\n", &fin);
	for(int i = 0; i<fin; i++){
		scanf("%d", &cost[i]);
	}

	// initialize
	dp[0] = cost[0];
	dp[1] = cost[0] + cost[1];
	dp[2] = max_func(cost[1] + cost[2], cost[0] + cost[2]);

	for(int i = 3; i<fin; i++){
		dp[i] = max_func(dp[i-3] + cost[i-1] + cost[i], dp[i-2] + cost[i]);
	}
	printf("%d\n", dp[fin-1]);
}
