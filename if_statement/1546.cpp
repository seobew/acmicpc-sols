#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	float new_score[1000] = {0.0};
	for(int i = 0; i<n; i++){
		int temp;
		scanf("%d", &temp);
		new_score[i] = (float)temp;
	}
	float max = 1.0;
	int max_index=0;
	for(int i = 0; i<n; i++){
		if(new_score[i]>max){
			max = new_score[i];
			max_index = i;
		}
	}
	for(int i = 0; i<n; i++){
		new_score[i] =(float)((float)new_score[i]/(float)max)*100;
	}
	float sum;
	for(int i = 0; i<n; i++){
		sum += new_score[i];
	}
	float mean = sum/(float)n;
	printf("%.2f\n", mean);
}
