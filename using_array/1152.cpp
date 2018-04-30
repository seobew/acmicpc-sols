#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	getline(cin, str);
	int count = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == ' '){
			count++;
		}
	}
	if (str.front() == ' '){
		count--;
	}
	if (str.back() == ' '){
		count--;
	}
	cout<<count<<endl;
}
