#include <stdio.h>
#include <stdlib.h>

void QS(int *A, int min, int max){
	int Lft, Rht;
	int Avr, Val;
	if(min < max){
		Lft = min;
		Rht = max;
		Avr = 0.5*(A[Lft]+A[Rht]);
		do{
			while(A[Lft] < Avr) Lft++;
			while(A[Rht] > Avr) Rht--;
			if(Lft <= Rht){
				Val=A[Lft];
				A[Lft]=A[Rht];
				A[Rht]=Val;
				Lft++;
				Rht--;
			}
		}while(Lft<=Rht);
		QS(A, min, Rht);
		QS(A, Lft, max);
	}
}

int main(void){
	int i, n;
	scanf("%d", &n);
	int *X;
	X = (int*)malloc(n*sizeof(int));
	
	for(i=0; i<n; i++){
		scanf("%d", &X[i]);
	}
	
	QS(X, 0, n-1);
	
	for(i=0; i<n; i++){
		printf("%d ", X[i]);
	}
	
	return 0;
}