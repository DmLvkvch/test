#include <stdio.h>
#include <stdlib.h>
#include "abs_max.h"
#include "abs_min.h"
#include "diff.h"
#include "sum.h"

int main(){
	int A[100],N=0, min, max, d, s, i;
	char stop;

	for(i=0;i<100;i++){
		N++;
		scanf("%d%c",&A[i], &stop);
		if (stop=='\n') 
		break;
	}
	switch(A[0]){
		case 0:
			max = abs_max(A, N);
			printf("%d\n", max);
			break;
		case 1:
			min = abs_min(A, N); 
			printf("%d\n", min);
			break;
		case 2: 
			d = diff(A, N);
			printf("%d\n", d);
			break;
		case 3: 
			s = sum(A, N);
			printf("%d\n", s);
			break;
		default: printf("Данные некорректны\n");
		break;
	}
return 0;
}
