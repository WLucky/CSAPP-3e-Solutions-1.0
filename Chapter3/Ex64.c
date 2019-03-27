/*
A. &A[i][j][k] = A + (T(S * i + j) + k)L

B. 
	%rdx = 13(5i + j) + k
	so  T = 13 S = 5
	size = L * R * T * S = 3640  L = 8 is known
	get R = 7

	so R = 7, T = 13, S = 5

*/

#define R 7
#define T 13
#define S 5

long A[R][S][T];

long store_ele(long i, long j, long k, long *dest)
{
	*dest = A[i][j][k];
	return sizeof(A);
}
