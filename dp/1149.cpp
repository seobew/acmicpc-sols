// D[n] = D[n-3] + n-2th + n-1th + nth

#include <stdio.h>

int D[1000][3];

int min(int a, int b){
	if(a>b){
		return b;
	}else{
		return a;
	}
}

int three_min(int a, int b, int c){
	int min;
	if(a>b){
		if(b>c){
			min = c;
		}else{
			min = b;
		}
	}else{
		if(a>c){
			min = c;
		}else{
			min = a;
		}
	}
	return min;
}

int main(){
	int numOfhouse;
	int result;
	scanf("%d", &numOfhouse);
	for(int i = 0; i<numOfhouse; i++){
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		if(i==0){
			D[i][0] = a;
			D[i][1] = b;
			D[i][2] = c;
		}else{
			D[i][0] = min(D[i-1][1], D[i-1][2]) + a;
			D[i][1] = min(D[i-1][0], D[i-1][2]) + b;
			D[i][2] = min(D[i-1][1], D[i-1][0]) + c;
		}
	}
	result = three_min(D[numOfhouse-1][0], D[numOfhouse-1][1], D[numOfhouse-1][2]);

	printf("%d\n", result);
	return 0;
}
