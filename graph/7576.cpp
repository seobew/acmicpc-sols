#include <stdio.h>
#include <stdlib.h>

int row, col;
int arr[1000][1000];
int origin_count;
int new_count;
int depth;

// using bfs
class Node{
	public:
		int r;
		int c;
		Node* next;
		Node(int row, int col){
			this->r = row;
			this->c = col;
		}
};

class Queue{
	public:
		int size;
		Node* head;
		Node* tail;
		Queue(){
			this->head = NULL;
			this->tail = NULL;
			this->size = 0;
		}
		void enqueue(int r, int c){
			this->size++;
			Node* a = new Node(r, c);
			if(this->size==1){
				this->head = this->tail = a;
				return;
			}
			this->tail->next = a;
			this->tail = a;
		}
		int* dequeue(){
			int* arr = (int*)malloc(sizeof(int)*2);
			if(size<1){
					arr[0] = -1;
					arr[1] = -1;
				return arr;
			}else{
				size--;
				arr[0] = this->head->r;
				arr[1] = this->head->c;
				this->head = head->next;
				return arr;
			}
		}

		bool is_empty(){
			if(size == 0){
				return true;
			}else{
				return false;
			}
		}
};

Queue a;

void bfs(){

	while(1){
		int* temp = a.dequeue();

		int t = temp[0];
		// depth check 분기
		if(t == -2){
			if(a.is_empty()){
				break;
			}else{
				depth++;
				temp = a.dequeue();
				a.enqueue(-2,-2);
			}
		}
		// 이제부터 체크
		int r_idx = temp[0];
		int c_idx = temp[1];

		// up case
		if(c_idx-1>=0){
			if(arr[r_idx][c_idx-1] == 0){
				a.enqueue(r_idx, c_idx-1);
				arr[r_idx][c_idx-1] = 1; // 토마토가 익은것 및 방문한 것
				new_count++;
			}
		}

		// down case
		if(c_idx+1<col){
			if(arr[r_idx][c_idx+1] == 0){
				a.enqueue(r_idx, c_idx+1);
				arr[r_idx][c_idx+1] = 1; // 토마토가 익은것 및 방문한 것
				new_count++;
			}
		}

		// left case
		if(r_idx-1>=0){
			if(arr[r_idx-1][c_idx] == 0){
				a.enqueue(r_idx-1, c_idx);
				arr[r_idx-1][c_idx] = 1; // 토마토가 익은것 및 방문한 것
				new_count++;
			}
		}

		// right case
		if(r_idx+1<row){
			if(arr[r_idx+1][c_idx] == 0){
				a.enqueue(r_idx+1, c_idx);
				arr[r_idx+1][c_idx] = 1; // 토마토가 익은것 및 방문한 것
				new_count++;
			}
		}
	}
}

int main(){
	int r_idx, c_idx;
	scanf("%d %d", &col, &row);
	for(int i =0; i<row; i++){
		for(int j = 0; j<col; j++){
			int temp;
			scanf("%d", &temp);
			if(temp == 1){
				r_idx = i;
				c_idx = j;
				a.enqueue(r_idx, c_idx);
			}else if(temp == 0){
				origin_count++;
			}
			arr[i][j] = temp;
		}
	}
	a.enqueue(-2, -2);
	bfs();
	if(new_count != origin_count){
		printf("-1\n");
	}else{
		printf("%d\n", depth);
	}
	return 0;
}
