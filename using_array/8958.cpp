#include <iostream>
#include <string>
using namespace std;

int main(){
	int num;
	cin>>num;
	cin.ignore();
	for(int i = 0; i<num; i++)
	{
		string str;
		getline(cin, str);
		int score = 0;
		int total_score = 0;
		for(int a = 0; a<str.length(); a++){
			char temp = str.at(a);
			if(temp == 'O'){
				score++;
				total_score += score;
			}else{
				score = 0;
			}

		}
		cout<<total_score<<endl;
	}
}
