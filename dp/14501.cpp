#include <stdio.h>

int period[15];
int cost[15];
int dp[16];
int end_day;
int max;

int max_func(int a, int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int recur(int day){
	if(day == end_day){
		return 0;
	}

	if(day>end_day){
		return -10000;
	}

	if(dp[day] != 0){
		return dp[day];
	}

	return dp[day] = max_func(recur(day+1), recur(day + period[day]) + cost[day]);
}


int main(){
	scanf("%d\n", &end_day);
	for(int i = 0; i<end_day; i++){
		scanf("%d %d", &period[i], &cost[i]);
		dp[i] = 0;
	}
	max = 0;
	max = recur(0);
	printf("%d\n", max);
}
