#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	getline(cin, str);
	int arr[26];
	for(int i = 0; i<26; i++){
		arr[i] = -1;
	}
	for(int i = 0; i<str.length(); i++){
		char temp = str.at(i);
		int temp_i = (int)temp;
		temp_i = temp_i-97;
		if(arr[temp_i] !=-1){
			continue;
		}
		arr[temp_i] = i;
	}

	for(int i = 0; i<26; i++){
		if(i == 25){
			cout<<arr[i]<<endl;
		}else{
			cout<<arr[i]<<" ";
		}
	}
}
