#include <stdio.h>
#include <stdlib.h>

int map[500][500];
int N,M;

int max;

void dfs(int x, int y, int d, int sum, int dir, int len){


	// to find +++  <- these shapes
	//          +
	if(len == 2 && d==3){
		// up
		if(dir==0){
			// left
			if(y!=0){
				dfs(x+1, y-1, d+1, sum + map[x+1][y-1], 2, len++);
			}
			// right
			if(y!=M-1){
				dfs(x+1, y+1, d+1, sum + map[x+1][y+1], 3, len++);
			}
		}

		// down
		if(dir==1){
			// left
			if(y!=0){
				dfs(x-1, y-1, d+1, sum + map[x-1][y-1], 2, len++);
			}
			// right
			if(y!=M-1){
				dfs(x-1, y+1, d+1, sum + map[x-1][y+1], 3, len++);
			}
		}

		// left
		if(dir==2){
			// up
			if(x!=0){
				dfs(x-1, y+1, d+1, sum + map[x-1][y+1], 0, len++);
			}
			// down
			if(x!=N-1){
				dfs(x+1, y+1, d+1, sum + map[x+1][y+1], 1, len++);
			}
		}

		// right
		if(dir==3){
			// up
			if(x!=0){
				dfs(x-1, y-1, d+1, sum + map[x-1][y-1], 0, len++);
			}
			// down
			if(x!=N-1){
				dfs(x+1, y-1, d+1, sum + map[x+1][y-1], 1, len++);
			}
		}
	}

	// fin cond
	if(d ==4){
		if(sum>=max){
			max = sum;
		}
		return;
	}

	// up
	if(x!=0 && dir !=1){
		// when same direction adding
		if(dir ==0){
			dfs(x-1, y, d+1, sum + map[x-1][y], 0, len+1);
		}else{
			dfs(x-1, y, d+1, sum + map[x-1][y], 0, len);
		}
	}
	// down
	if(x!=N-1 && dir != 0){
		// when same direction adding
		if(dir ==1){
			dfs(x+1, y, d+1, sum + map[x+1][y], 1, len+1);
		}else{
			dfs(x+1, y, d+1, sum + map[x+1][y], 1, len);
		}
	}
	// left
	if(y!=0 && dir !=3){
		// when same direction adding
		if(dir ==2){
			dfs(x, y-1, d+1, sum+ map[x][y-1], 2, len+1);
		}else{
			dfs(x, y-1, d+1, sum+ map[x][y-1], 2, len);
		}
	}
	// right
	if(y!=M-1 && dir!=2){
		// when same direction adding
		if(dir ==3){
			dfs(x, y+1, d+1, sum + map[x][y+1], 3, len+1);
		}else{
			dfs(x, y+1, d+1, sum + map[x][y+1], 3, len);
		}
	}
}

int main(){
	scanf("%d %d\n", &N, &M);
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			int val;
			scanf("%d", &val);
			map[i][j] = val;
		}
	}
	max = map[0][0] + map[0][1] + map[0][2] + map[0][3];
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			dfs(i,j,1, map[i][j], -1, 1);
		}
	}
	printf("%d\n", max);
}
