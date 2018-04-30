#include <stdio.h>
int main(){
	char c[100];
	fgets(c,100, stdin);
	bool flag = false;
	for(int a = 0; a<100; a+=10){
		for(int j = 0; j<10; j++){
			if(c[a+j]=='\0' || c[a+j]=='\n'){
				flag = true;
				break;
			}
			printf("%c", c[a+j]);
		}
		printf("\n");
		if(flag){
			break;
		}
	}
}
