/*
A. (30 + 8 * n) >> 4 << 4
	if n is even
		s2 = s1 - (8n + 16)
	if n is odd
		s2 = s1 - (8n + 24)
B. (s2 + 15) >> 4 << 4
C. e1 is min:1
	n is even
	s1 % 16 = 1
   e1 is max:24
   n is odd
   s1 is % 16 = 0

D. s2与s1的差值为16字节对齐   p值16字节对齐
   	
*/

#include <alloca.h>

long aframe(long n, long idx, long *q)
{
	long i;
	long **p = alloca(n * sizeof(long *));
	p[0] = &i;
	for(i = 1; i < n; i++)
	{
		p[i] = q;
	}
	return *p[idx];
}
/*p为何要16字节对齐*/
