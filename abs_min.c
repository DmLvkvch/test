#include "abs_min.h"
#include <stdlib.h>

int abs_min(int *A, int N){
	int min;
	min=A[1];
	for(int i=2;i<N;i++){
		if(abs(min)>abs(A[i])) min=A[i];
	} 
return min;
}
