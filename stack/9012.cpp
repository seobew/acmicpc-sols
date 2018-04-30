#include <stdio.h>
char stack[50];
int front;
int size;

void push(char s){
	stack[front] = s;
	front++;
	size++;
}

char pop(){
	char temp = stack[front-1];
	front--;
	size--;
	return temp;
}

bool st_is_empty(){
	if(size<=0){
		return true;
	}else{
		return false;
	}
}
void clear (){
	while (getchar() != '\n');
}

int main(){
	int case_num;
	scanf("%d", &case_num);
	clear();
	for(int i = 0; i<case_num; i++){
		bool is_vps = true;
		bool flag = false;
		front = 0;
		size = 0;
		char c;
		while ((c = getchar()) != '\n' && c != EOF) {
			if(c=='\n'){
				break;
			}
			if(c=='('){
				push('(');
			}
			if(c==')'){
				if(st_is_empty()){
					is_vps = false;
					flag = true;
				}else{
					pop();
				}
			}
		} // end of while

		// if ) is not enough as ( exists while making paranthesis, the string is not vps
		if(flag && !is_vps){
			printf("NO\n");
			continue;
		}

		// if ( is too many, the string is not vps
		if(!st_is_empty()){
			is_vps = false;
		}

		if(is_vps){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}
