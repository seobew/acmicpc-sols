#include <stdio.h>

class Node{
	public:
		long value;
		Node* next;

		Node(long d){
			this->value = d;
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

	void push(long d){
		Node* n = new Node(d);
		// first push
		if(this->length==0){
			this->head = n;
			this->rear = n;
		}else{
			this->rear->next = n;
			this->rear = n;
		}
		this->length++;
	}

	long pop(){
		if(empty()){
			return -1;
		}else{
			long temp = this->head->value;
			this->head = this->head->next;
			this->length--;
			return temp;
		}
	}

	int size(){
		return this->length;
	}

	int empty(){
		if(size()==0){
			return 1;
		}else{
			return 0;
		}
	}

	long front(){
		if(empty()){
			return -1;
		}else{
			long temp = this->head->value;
			return temp;
		}
	}

	long back(){
		if(empty()){
			return -1;
		}else{
			long temp = this->rear->value;
			return temp;
		}
	}
};

int main(){
	Queue q;
	int N;
	long input_num;
	scanf("%d", &N);
	for(int i = 0; i<N; i++){
		input_num = 0;
		char string [256];
		//gets (string);
		scanf("%s", string);
		if(string[1] == 'u'){
			// push called
			scanf("%ld", &input_num);
			q.push(input_num);
		}else if(string[1] == 'r'){
			// front called
			printf("%ld\n", q.front());
		}else if(string[1] == 'a'){
			// back called
			printf("%ld\n", q.back());
		}else if(string[1] == 'i'){
			// size called
			printf("%d\n", q.size());
		}else if(string[1] == 'm'){
			// empty called
			printf("%d\n", q.empty());
		}else if(string[1] == 'o'){
			// pop called
			printf("%ld\n", q.pop());
		}
	}
}
