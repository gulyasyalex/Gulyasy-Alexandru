#include<stdio.h>
#include<stdlib.h>

int main(){

	int A[] = { 3, 7, 12, 21, 25, 26, 27, 29, 37, 39};
	int li, lf, k, x, i;

	li = 0;
	lf = sizeof(A) / sizeof(int);

	printf("%d %d \n", li, lf);
	for (i = li; i < lf; i++){
		printf("%d ", A[i]);
	}
	printf("\nIntroduceti elementul cautat:");
	scanf("%d", &x);

	i = 0;
	while (li <= lf ) {
		k = (li + lf) / 2;
		printf("Pasul %d si k = %d\n", ++i, k+1);
		if (A[k] == x) {
			printf("%d este pe pozitia %d", x, k + 1);
			break;
		}
		else if (x < A[k]){
			lf = k - 1;
		}
		else {
			li = k + 1;
		}
	}
	return 0;
}