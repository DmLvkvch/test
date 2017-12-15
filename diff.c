#include "diff.h"
#include "abs_max.h"
#include "abs_min.h"
#include <stdlib.h>
int diff(int *A, int N){
	int diff;
	int max=abs_max(A, N);
	int min=abs_min(A, N);
	int d=max-min;
return d;
}
