#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int a,b;
	cin>>a;
	cin>>b;
	double temp = (double)a/(double)b;
	cout<<setprecision(9)<<temp<<endl;
	return 0;
}
