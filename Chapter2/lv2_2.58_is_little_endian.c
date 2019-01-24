#include <stdio.h>


int is_little_endian()
{
	int x = 0x1;
	unsigned char *start =(unsigned char *) &x;
	return (int)(start[0]);
}

int main(int argc, char* argv[])
{
	if(is_little_endian() == 1)
	{
		printf("This computer is little endian\n");
	}
	else
	{
		printf("This computer is big endian\n");
	}
	
	return 0;
}
