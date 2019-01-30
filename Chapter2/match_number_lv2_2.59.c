#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);    //line:data:show_bytes_printf
    printf("\n");
}

int main(int argc, char* argv[])
{
	int x, y, x1, y1, result;
	int mask_x = 0xFF;
	int mask_y = ~mask_x;
	printf("input x:\n");
	scanf("%d", &x);
	printf("input y:\n");
	scanf("%d", &y);
	
	printf("x, y:\n");
	show_bytes((byte_pointer)&x, sizeof(int));
	show_bytes((byte_pointer)&y, sizeof(int));
	
	/*x取低两个字节*/
	x1 = x & mask_x;
	/*y取剩下字节*/
	y1 = y & mask_y;
	
	result = x1 | y1;
	
	printf("the result is:\n");
	show_bytes((byte_pointer)&result, sizeof(int));
	
	return 0;
}