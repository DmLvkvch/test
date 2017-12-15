#include "sum.h"
#include "abs_max.h"

int sum(int *A, int N){

	int m,i,last, s=0;
	m=abs_max(A, N);
	for(i=0;i<N;i++){
		if(m==A[i]) {
			last=i;
			break;
		}
	}

	for(i=last;i<N;i++){
		s=s+A[i];
	}
return s;
}
