#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *v;
	int n; 
	printf("Digite a qauntidade de vetores: \n");
	scanf("%d", &n);
	
	v = malloc (n* sizeof(int));
	
	// printf("%d", sizeof(*v));
	
	printf("-------------------------------- \n");
	
	printf("Inserção de valores: \n");
	
	for (int i = 0; i < n; i++){
		printf("%d \n", v[i]);
	}
	
	free(v);
	return 0;
}