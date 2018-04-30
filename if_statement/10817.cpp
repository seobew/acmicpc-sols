#include <stdio.h>
int main(){
	int a,b,c;
	scanf("%d %d %d", &a,&b,&c);
	if(a>b){
		if(b>c){
			printf("%d\n", b);
		}else{
			if(a>c){
				printf("%d\n", c);
			}else{
				printf("%d\n", a);
			}
		}
	}else{
		if(a>c){
			printf("%d\n", a);
		}else{
			if(b>c){
				printf("%d\n", c);
			}else{
				printf("%d\n", b);
			}
		}
	}
}
