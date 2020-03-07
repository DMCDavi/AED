#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int a, b, q, r;
	
	scanf("%d %d", &a, &b);
	
	if(a >= -1000 && b < 1000 && b != 0){
		
		if(a > 0 && b != 0){
			
			q = a / b;
			
			r = a % b;
			
		}else if(a < 0 && b > 0){
			
			q = (a / b) - 1;
			
			r = (a % b) + b;
			
			if(q == 0 || r == abs(b)){
				
				q = a / b;
			
				r = a % b;
				
			}
			
		}else if(a < 0 && b < 0){
			
			q = (a / b) + 1;
			
			r = (a % b) - b;
			
			if(q == 0 || r == abs(b)){
				
				q = a / b;
			
				r = a % b;
				
			}
			
		}printf("%d %d\n", q, r);
			
	}
	
	return 0;
}
