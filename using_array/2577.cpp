#include <stdio.h>
#include <string>
using namespace std;
int main(){
	int a,b,c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	int mult = a*b*c;
	string s = to_string(mult);
	int num[10] = {0};
	for(int i = 0; i<s.length(); i++)
	{
		char c = s.at(i);
		int temp = c - '0';
		if(temp == 0){
			num[0]++;
		}else if(temp == 1){
			num[1]++;
		}else if(temp == 2){
			num[2]++;
		}else if(temp == 3){
			num[3]++;
		}else if(temp == 4){
			num[4]++;
		}else if(temp == 5){
			num[5]++;
		}else if(temp == 6){
			num[6]++;
		}else if(temp == 7){
			num[7]++;
		}else if(temp == 8){
			num[8]++;
		}else if(temp == 9){
			num[9]++;
		}
	}
	for(int i = 0; i<10; i++){
		printf("%d\n", num[i]);
	}
}
