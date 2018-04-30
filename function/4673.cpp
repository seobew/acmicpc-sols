#include <stdio.h>
bool check_self_num(int n){
	int index;
	if(n>1000){
		for(int a = 0; a<10; a++){
			for(int b = 0; b<10; b++){
				for(int i = 0; i<10; i++){
					for(int j =0; j<10; j++){
						if((1001*a + 101*b + 11*i + 2*j) == n){
							return false;
						}
					}
				}
			}
		}
	}else if(n>100){
		for(int a = 0; a<10; a++){
			for(int i = 0; i<10; i++){
				for(int j =0; j<10; j++){
					if((101*a + 11*i + 2*j) == n){
						return false;
					}
				}
			}
		}
	}else{
		for(int i = 0; i<10; i++){
			for(int j =0; j<10; j++){
				if((11*i + 2*j) == n){
					return false;
				}
			}
		}
	}
	return true;
}

int main(){
	for(int i = 0; i<10000; i++){
		if(check_self_num(i)){
			printf("%d\n", i);
		}
	}
	return 0;
}
