#include <stdio.h>
int stack[100000];
char queue[200000];
int stack_front;
int stack_size;
int queue_front;
int queue_rear;
int queue_size;

void st_push(int num){
	stack[stack_front] = num;
	stack_front++;
	stack_size++;
}

int st_top(){
	return stack[stack_front-1];
}

int st_pop(){
	int temp = stack[stack_front-1];
	stack_front--;
	stack_size--;
	return temp;
}

bool st_is_empty(){
	if(stack_size <=0){
		return true;
	}else{
		return false;
	}
}

void enqueue(char c){
	queue[queue_rear] = c;
	queue_rear++;
	queue_size++;
}

char dequeue(){
	char temp = queue[queue_front];
	queue_front++;
	queue_size--;
	return temp;
}

bool q_is_empty(){
	if(queue_size <=0){
		return true;
	}else{
		return false;
	}
}

int main(){
	int input_num;
	scanf("%d", &input_num);
	int temp = 1;
	for(int i = 0; i<input_num; i++){
		int d;
		scanf("%d", &d);
		while(st_top() != d){
			if(temp >=input_num+1){
				printf("NO\n");
				return 0;
			}
			st_push(temp);
			temp++;
			enqueue('+');
		}
		st_pop();
		enqueue('-');
	}

	while(!q_is_empty()){
		printf("%c\n", dequeue());
	}
}
