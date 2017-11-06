#include <stdio.h>
#include <stddef.h>

int offset = 0;
char *stack;

void zero_buf(char *p, size_t n)
{
	int i;
	for (i=0; i < n; i++) p[i] = 0;
}

void hide(void)
{
	char secret[] = "12345", *p;
	int a;
	printf("&secret %p &a %p\n", secret, &a);
	printf("secret = %s\n", secret);
	p = (char *) &a;
	offset = secret - p;
	stack = p;
	zero_buf(secret, 5);
}

int main()
{
	hide();
	printf("peek @%p: %d %d %d %d %d\n", stack+offset, 
		stack[offset], stack[offset+1], stack[offset+2], 
		stack[offset+3], stack[offset+4]);
	return 0;
}
