#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <time.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int num, letras, cont, i, comp;
	
	char palpite, hashtag[15] = "###############", word[11][16] = {"flamingo", "avestruz", "macaco", "dromedario", "gueopardo", "cachorro", "lagarto", "baleia", "tartaruga", "camelo"};
	
	srand(time(NULL));
	
	num = rand() % 10;
	
	letras = strlen(word[num]);
	
	printf("Aperte qualquer botão para iniciar o jogo da forca\n");
	
	system("pause");
	
	printf("Sua palavra é um animal que contém %d letras\n", letras);
	
	printf("Você tem direito a 10 palpites. Vamos começar!\n");
	
	printf("=========================================================================================\n\n");
	
	for(cont = 0; cont < 10; cont++){
	
		printf("Digite uma letra: ");
		
		scanf("%c", &palpite);
		
		fflush(stdin);
		
		hashtag[letras] = '\0';
		
		for(i = 0; i < 15; i++){
			
			if(word[num][i] == palpite){
				
				hashtag[i] = palpite;
				
			}
			
		}printf("%s\n", hashtag);
	
		comp = strcmp(hashtag, word[num]);
	
		if(comp == 0){
			
			printf("Acertou, miseravi!!\n");
			
			break;
			
		}
	
	}if(comp != 0){
		
		printf("Errrroooou, burro do carai!!");
		
	}
	
	system("pause");
	
	return 0;
}
