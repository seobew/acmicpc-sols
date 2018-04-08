#include <iostream>
using namespace std;

// Problem : coding fibonacci with dp, print 0th call, 1th call
// Description : using memoization to reduce calculating time

int memo[41];

int fibonacci(int n) {
	if(n==0){
		return memo[n];
	}

	if(n==1){
		return memo[n];
	}

	if(memo[n] == -1){
		// need to calculate
		memo[n] = fibonacci(n-1) + fibonacci(n-2);
		return memo[n];
	}
	else{
		// already calculated
		return memo[n];
	}
}


int main(){
	int testcase;
	cin>>testcase;
	for(int i =0; i<testcase; i++){
		int input;
		// initailize memos to -1
		for(int j =0; j<41; j++){
			memo[j] = -1;
		}
		memo[0] = 1;
		memo[1] = 1;
		cin>>input;
		fibonacci(input);
		if(input == 0){
			cout<<1<<" "<<0<<endl;
		}else if(input==1){
			cout<<0<<" "<<1<<endl;
		}else{
			cout<<memo[input-2]<<" "<<memo[input-1]<<endl;
		}
	}
	return 0;
}
