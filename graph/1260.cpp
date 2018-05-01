#include <stdio.h>

class Node{
	public:
		int value;
		Node* next;

		Node(int a){
			this->value = a;
		}
};

class Queue{
	public:
		Node* head;
		Node* rear;
		int length;

		Queue(){
			this->head = NULL;
			this->rear = NULL;
			this->length = 0;
		}

		void enqueue(int a){
			Node* n = new Node(a);
			if(empty()){
				this->head = n;
				this->rear = n;
			}else{
				this->rear->next = n;
				this->rear = n;
			}
			this->length++;
		}

		int dequeue(){
			if(empty()){
				return -1;
			}else{
				int temp = this->head->value;
				this->head = this->head->next;
				this->length--;
				return temp;
			}
		}

		bool empty(){
			if(this->length == 0){
				return true;
			}else{
				return false;
			}
		}
};

bool edges[1000][1000]={false};
bool visited[1000]={false};

void dfs(int start_v, int vNum){
	for(int i = 0; i<vNum; i++){
		if(visited[i]){
			continue;
		}
		// edge exist
		if(edges[start_v][i] || edges[i][start_v]){
			visited[i] = true;
			printf(" %d", i+1);
			dfs(i, vNum);
		}
	} // end for loop
}

Queue q;

void bfs(int vNum){
	while(!q.empty()){
		int v = q.dequeue();
		printf("%d ", v+1);
		for(int i = 0; i<vNum; i++){
			if(visited[i]){
				continue;
			}
			// edge exist
			if(edges[v][i] || edges[i][v]){
				q.enqueue(i);
				visited[i] = true;
			}
		} // end for loop for edge check
	} // end while
}

int main(){
	int vNum;
	long eNum;
	int start_v;

	scanf("%d %ld %d", &vNum, &eNum, &start_v);

	for(long i = 0; i<eNum; i++){
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		edges[v1-1][v2-1] = true;
		edges[v2-1][v1-1] = true;
	}

	visited[start_v-1] = true;
	// start dfs
	printf("%d", start_v);
	dfs(start_v-1, vNum);
	printf("\n");

	// reinitialize visited arr
	for(int a = 0; a<vNum; a++){
		visited[a] = false;
	}
	visited[start_v-1] = true;
	// start bfs
	q.enqueue(start_v-1);
	bfs(vNum);
	printf("\n");
}
