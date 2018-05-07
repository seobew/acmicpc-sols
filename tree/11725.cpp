#include <stdio.h>

class Node{
	public:
		int v1;
		int v2;
		Node*next;

		Node(){
		}
		Node(int a, int b){
			this->v1 = a;
			this->v2 = b;
		}
};

class Stack{
	public:
		Node* head;
		int size;

		Stack(){
			this->head = NULL;
			this->size = 0;
		}

		void push(int a, int b){
			Node* temp = new Node(a,b);
			if(size == 0){
				this->head = temp;
			}else{
				temp->next = this->head;
				this->head = temp;
			}
			this->size++;
		}

		void pop(){
			if(this->size == 0){
				return;
			}
			delete this->head;
			this->head = this->head->next;
			this->size--;
			return;
		}


		int top_v1(){
			return this->head->v1;
		}

		int top_v2(){
			return this->head->v2;
		}
};

int parent[100001] = {0};
int main(){
	int N;
	scanf("%d", &N);
	Stack s1, s2;
	for(int i = 0; i<N-1; i++){
		int t1, t2;
		scanf(" %d %d", &t1, &t2);
		s1.push(t1,t2);
		if(t1 == 1){
			parent[t2] = t1;
		}
		if(t2 == 1){
			parent[t1] = t2;
		}
	}

	bool discr = true;
	while(s1.size!=0 || s2.size!=0){
		if(discr){
			int temp_v1 = s1.top_v1();
			int temp_v2 = s1.top_v2();
			s1.pop();

			if(parent[temp_v2] != 0){
				parent[temp_v1] = temp_v2;
			}else if(parent[temp_v1] != 0){
				parent[temp_v2] = temp_v1;
			}else{
				s2.push(temp_v1, temp_v2);
			}

			if(s1.size == 0){
				discr = !discr;
			}
		}else{
			int temp_v1 = s2.top_v1();
			int temp_v2 = s2.top_v2();
			s2.pop();

			if(parent[temp_v2] != 0){
				parent[temp_v1] = temp_v2;
			}else if(parent[temp_v1] != 0){
				parent[temp_v2] = temp_v1;
			}else{
				s1.push(temp_v1, temp_v2);
			}

			if(s2.size == 0){
				discr = !discr;
			}
		}
	}

	for(int i = 2; i<N+1; i++){
		printf("%d\n", parent[i]);
	}

}
