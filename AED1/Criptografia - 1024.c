#include <stdio.h>
#include <string.h>

int main() {
	
	int cont, tam, M, N, i, j = 0;
	
	scanf("%d", &N);
		
	M = N;
		
	char text[N+1][1001], aux[N+1][1001];		

	if(N >= 1 && N <= 10000){
		
		for(i = 0; i < N; i++){
		
			scanf(" %[^\n]s", &text[i]);	
		
			tam = (strlen(text[i])) - 1;
		
			while(text[i][j] != '\0'){
				
				if((text[i][j] >= 65 && text[i][j] <= 90) || (text[i][j] >= 97 && text[i][j] <= 122)){
					
					text[i][j] = text[i][j] + 3;

				}j++;	
						
			}j = 0;
			
			strcpy(aux[i], text[i]);
			
			while(text[i][j] != '\0'){
				
				text[i][j] = aux[i][tam];
			
				tam--;
			
				j++;
				
			}j = 0;
			
			tam = strlen(text[i]);
			
			while(text[i][j] != '\0'){
					
				if(j >= tam / 2){
					
					text[i][j] = text[i][j] - 1;

				}j++;
						
			}j = 0;	
			
		}
		
		for(cont = 0; cont < M; cont++){
			
			printf("%s\n", text[cont]);
			
		}
		
	}
	
	system ("pause");
	
	return 0;
}
