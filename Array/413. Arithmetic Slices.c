/*
413. Arithmetic Slices

A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.

Example:

A = [1, 2, 3, 4]
return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*/
// #define A413
#ifdef A413

int numberOfArithmeticSlices(int* A, int ASize) {
	int i = 0, j = i + 1, k = i + 2, P = -1, Q = -1,x=0,ret =0 ;
	if (ASize < 3){
		return 0;
	}
	
	for (i = 0; i < ASize-2; i++,j++,k++)
	{
		printf("%d,%d,%d ==> %d,%d,%d,\n", i, j, k, A[i], A[j], A[k]);

		if (A[k]+A[i] == A[j]*2)
		{
			if (P == -1)
			{
				P = i;
			}
			Q = k;
		}
		else
		{
			if (Q > 0)
			{
				x = (Q - P + 1) - 3 + 1;
				ret += x*(x + 1) / 2;
				printf("\n%d,%d\n", P, Q);
				P = -1;
				Q = -1;
			}
		}
	}
	if (Q > 0)
	{
		x = (Q - P + 1) - 3 + 1;
		ret += x*(x + 1) / 2;
		printf("\n%d,%d\n", P, Q);
	}
	return ret;
}

int main(){
	int a[] = { 1, 2, 3, 4 ,6, 8, 7, 8, 9, 10};
	printf("%d", numberOfArithmeticSlices(a, 10));	
	getchar();
}
#endif