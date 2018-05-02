#include <stdio.h>

class Node{
	public:
		int value;
		Node* next;
		Node(int v){
			this->value = v;
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

		void enqueue(int v){
			Node* n = new Node(v);
			if(is_empty()){
				this->head = n;
				this->rear = n;
			}else{
				this->rear->next = n;
				this->rear = n;
			}
			this->length++;
		}

		int dequeue(){
			if(is_empty()){
				return -1;
			}else{
				int temp = this->head->value;
				delete this->head;
				this->head = this->head->next;
				this->length--;
				return temp;
			}
		}

		int front(){
			return this->head->value;
		}

		bool is_empty(){
			if(this->length<=0){
				return true;
			}else{
				return false;
			}
		}
};

Queue q;

void solve(int n, int m){
	printf("<");
	while(q.length>1){
		for(int i = 0; i<m-1; i++){
			int t = q.dequeue();
			q.enqueue(t);
		}
		int x = q.dequeue();
		printf("%d, ", x);
	}
	printf("%d>\n", q.front());
}

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i<n+1; i++){
		q.enqueue(i);
	}
	solve(n,m);
}
