/*
B in {5， 6， 7， 8}
A in {7, 8 , 9, 10}
A*B in {45, 46}

so A = 9 B = 5
*/

#define A 9
#define B 5

typedef struct
{
	int x[A][B];
	long y;
}str1;

typedef struct
{
	char array[B];
	int t;
	short s[A];
	long u;
}str2;

void setVal(str1 *p, str2 *q)
{
	long v1 = q->t;
	long v2 = q->u;
	p->y = v1 + v2;
}
