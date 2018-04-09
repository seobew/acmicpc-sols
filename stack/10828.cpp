#include <iostream>
#include <string>
using namespace std;

class Node{
	public:
		int value;
		Node* next;
		Node(int val);
};

Node::Node(int val){
	this->value = val;
}


class Stack{

	public:
		Node* head;
		int length;
		Stack(){
			this->head = NULL;
			this->length = 0;
		}
		void push(int num){
			if(this->head==NULL){
				this->head = new Node(num);
			}else{
				Node* n = new Node(num);
				n->next = this->head;
				this->head = n;
			}
			this->length++;
		}

		int top(){
			if(this->length == 0){
				return -1;
			}else{
				return this->head->value;
			}
		}

		int pop(){
			if(this->length == 0){
				return -1;
			}else{
				int temp_val = this->head->value;
				if(this->length == 1){
					this->head = NULL;
				}else{
					this->head = this->head->next;
				}
				this->length--;
				return temp_val;
			}
		}

		int size(){
			return this->length;
		}

		int empty(){
			if(this->length == 0){
				return 1;
			}else{
				return 0;
			}
		}
};

int main(){
	int command_num; // number of commands
	cin>>command_num;
	Stack st;
	// to solve cin issue
	string garbage;
	getline(cin, garbage);
	for(int i =0; i<command_num; i++){
		string command;
		getline(cin, command);
		if(command == "top"){
			cout<<st.top()<<endl;
		}else if(command == "size"){
			cout<<st.size()<<endl;
		}else if(command == "empty"){
			cout<<st.empty()<<endl;
		}else if(command == "pop"){
			cout<<st.pop()<<endl;
		}else{
			string num = command.substr(5);
			int val = stoi(num);
			st.push(val);
		}
	}
	return 0;
}
