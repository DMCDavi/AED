#include <stdio.h>
#include <stdlib.h>

int fibo (int n){
	if(n == 0|| n == 1){
		return 1;
	}
	
	return fibo(n-2) + fibo(n-1);
}


main(){
	int n = 0, i;
	
	for(i = 0;i<6;i++){
		printf("%d\n",fibo(i));	
	}
		
	
	
	
	system("pause");
}
