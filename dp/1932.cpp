#include <stdio.h>

int depth;
int cost[500][500];
int dp[500][500];

int max_func(int a, int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int solve(int i, int j){
	if(dp[i][j] != 0){
		return dp[i][j];
	}

	if(i>=depth-1){
		return cost[i][j];
	}

	return dp[i][j] = max_func(cost[i][j] + solve(i+1, j), cost[i][j] + solve(i+1, j+1));
}

int main(){
	scanf("%d\n", &depth);
	for (int i = 0; i<depth; i++){
		for(int j = 0; j<i+1; j++){
			scanf("%d", &cost[i][j]);
		}
	}
	int max = solve(0,0);
	printf("%d\n", max);
}
