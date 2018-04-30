#include <stdio.h>
#include <string>
int main(){
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	std::string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int x,y;
	scanf("%d", &x);
	scanf("%d", &y);
	int month_sum = 0;
	for(int i = 1; i<x; i++){
		month_sum += month[i-1];
	}
	int whole_sum = month_sum + y;
	printf("%s\n", day[whole_sum%7].c_str());
}
