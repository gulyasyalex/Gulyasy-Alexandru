#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void SetBit( unsigned int *val, unsigned char bitPos)
{
	*val = *val |(1 << bitPos);
	}

void ClearBit(unsigned int *val, unsigned char bitPos)
{
	*val = *val & ~(1 << bitPos);
}

unsigned char GetBitValue(unsigned int val, unsigned char bitPos)
{
	return ((val>> bitPos) & 1);
}

int main() 
{
	unsigned int value;
	unsigned char bitpos;
	printf("Value =");
	scanf("%d", &value);
	printf("Bitpos =");
	scanf("%hhu", &bitpos);

	SetBit(&value, bitpos);

	printf("%d", value);
	system("pause");
	return(0);
}