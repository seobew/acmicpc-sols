#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	for(int i =0; i<n; i++){
		int students;
		scanf("%d", &students);
		int arr[1000] = {0};
		int sum = 0;
		for(int j = 0; j<students; j++){
			int temp;
			scanf("%d", &temp);
			arr[j] = temp;
			sum += temp;
		}
		float mean = (float)sum/(float)students;
		int up=0;
		int down=0;
		for(int j = 0; j<students; j++){
			if(mean < (float)arr[j]){
				up++;
			}
		}
		float percentage = (float)up/(float)students;
		printf("%.3f%%\n", percentage*100);
	}
}
