#include <iostream>
#include <string>
using namespace std;
int main(){
	int cases;
	cin>>cases;
	cin.clear();
	for(int i = 0; i<cases; i++){
		int it;
		cin>>it;
		cin.clear();
		string str;
		getline(cin, str);
		for(int j = 0; j<str.length(); j++){
			if(str.at(j)==' '){
				continue;
			}
			for(int k=0; k<it; k++){
				cout<<str.at(j);
			}
		}
		cout<<endl;
	}
}
