#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	getline(cin, s);
	bool a = false;
	bool d = false;
	int prev = 0;
	for(int i = 0; i<s.length(); i++){
		char c = s.at(i);
		int cur;
		if(c == ' '){
			continue;
		}
		if(i==0){
			prev = c-'0';
			continue;
		}
		cur = c - '0';
		if(cur-prev >0){
			a = true;
		}else{
			d = true;
		}
		prev = cur;
	}

	if(a && d){
		cout<<"mixed"<<endl;
	}else if(a&&!d){
		cout<<"ascending"<<endl;
	}else if(!a&&d){
		cout<<"descending"<<endl;
	}else{
		cout<<"mixed"<<endl;
	}
}
