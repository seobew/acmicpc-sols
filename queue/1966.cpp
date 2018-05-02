#include <stdio.h>

class Node{
	public:
		int index;
		int weight;
		Node* next;
		Node(int i, int w){
			this->index = i;
			this->weight = w;
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

		void enqueue(int i, int v){
			Node *n = new Node(i, v);
			if(this->length == 0){
				this->head = n;
				this->rear = n;
				this->rear->next = NULL;
			}else{
				this->rear->next = n;
				this->rear = n;
				this->rear->next = NULL;
			}
			this->length++;
		}

		int dequeue(){
			if(this->length == 0){
				return -1;
			}else{
				int temp_index = this->head->index;
				this->head = this->head->next;
				this->length--;
				return temp_index;
			}
		}

		int top(){
			if(this->length == 0){
				return -1;
			}
			else{
				return this->head->index;
			}
		}

		int top_value(){
			return this->head->weight;
		}

		bool bigger_exist(){
			int top_v = top_value();
			Node *temp = this->head;
			while(temp->next !=NULL){
				temp = temp->next;
				if(temp->weight>top_v){
					return true;
				}
			}
			return false;
		}
};

int weight_list[100];

int main(){
	int case_num;
	scanf("%d", &case_num);
	for(int i = 0; i<case_num; i++){
		int N,M;
		Queue q;
		scanf("%d %d", &N, &M);
		for(int j = 0; j<N; j++){
			int weight;
			scanf("%d", &weight);
			weight_list[j] = weight;
			q.enqueue(j, weight);
		}

		int count = 1;
		while(q.length!=0){
			if(q.bigger_exist()){
				int temp_index = q.dequeue();
				q.enqueue(temp_index, weight_list[temp_index]);
			}else{
				//print
				int temp_index = q.dequeue();
				if(temp_index == M){
					break;
				}
				count++;
			}
		}
		printf("%d\n", count);
	}
}
