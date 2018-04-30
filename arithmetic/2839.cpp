#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int five;
	if(n-5<5){
		five = 0;
	}else{
		five = n/5;
	}
	bool flag = false;
	int idx;
	int idx2 = 0;
	int five_remain;
	for(idx = five; idx>=0; idx--){
		if(idx ==0){
			five_remain = n;
		}else{
			five_remain = n-(5*idx);
		}
		if(five_remain%3 == 0){
			idx2 = five_remain/3;
			flag = true;
			break;
		}
	}
	if(flag){
		cout<<idx+idx2<<endl;
	}else{
		cout<<-1<<endl;
	}
	return 0;
}
