#include "abs_max.h"
#include <stdlib.h>

int abs_max(int *A, int N){
	int max;
	max=A[1];
	for(int i=2;i<N;i++){
		if(abs(max)<abs(A[i])){ 
	
			max=A[i];
		}
	} 
return max;
}
