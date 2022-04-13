#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10
#define INVALID_VAL 255
unsigned char sp = 0;
unsigned char st[MAX_STACK_SIZE];

unsigned char Push(unsigned char *st, unsigned char val, unsigned char *sp);  //st = stack; sp = stack pointer;
unsigned char Pop(unsigned char *st, unsigned char *sp);
unsigned char IsStackFull(unsigned char *sp);
unsigned char IsStackEmpty(unsigned char *sp);

unsigned char Push(unsigned char *st, unsigned char val, unsigned char *sp)  //st = stack; sp = stack pointer;
{
	if (IsStackFull(sp) == 1) {
		return 0;
	}
	else {
		*(st + *sp) = val;
		(*sp)++;
		return 1;
	}

}
unsigned char Pop(unsigned char *st, unsigned char *sp)
{
	unsigned char val;

	if (IsStackEmpty(sp) == 1) {
		return INVALID_VAL;															//invalid
	}
	else {
		val = *(st + *sp - 1);
		*(st + *sp - 1) = 0;
		(*sp)--;
		return val;
	}
}
unsigned char IsStackFull(unsigned char *sp)
{
	return(*(sp) >= MAX_STACK_SIZE);
}
unsigned char IsStackEmpty(unsigned char *sp)
{
	return(*(sp) == 0);
}
int main()
{
	Push(st, 1, &sp);
	Push(st, 2, &sp);
	Push(st, 3, &sp);
	Push(st, 4, &sp);
	Push(st, 5, &sp);
	Pop(st, &sp);
	_getch();
	return 0;
}