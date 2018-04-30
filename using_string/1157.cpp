#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	getline(cin, str);
	int arr[26] = {};
	for(int i = 0; i<str.length(); i++){
		char temp_c = str.at(i);
		if(temp_c >'Z'){
			int temp_i = (int)(temp_c-32);
			temp_i = temp_i-65;
			arr[temp_i]++;
		}else{
			int temp_i = (int)(temp_c);
			temp_i = temp_i-65;
			arr[temp_i]++;
		}
	}
	int max = 0;
	int max_index = 0;
	for(int i = 0; i<26; i++){
		if(max<=arr[i]){
			max = arr[i];
			max_index = i;
		}
	}
	bool eq = false;
	for(int j = 0; j<26; j++){
		if(max == arr[j] && j != max_index){
			eq = true;
		}
	}

	if(eq){
		cout<<"?"<<endl;
	}else{
		char c = 65 + max_index;
		cout<<c<<endl;
	}
}
