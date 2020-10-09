#include <stdio.h>
#include "BitOperations.h"

#define byte unsigned char

int main()
{
	byte a[9] = {1,2,3,4,5,6,7};

	GetFormat(a, 3, 3);

#if 0
	byte x=3;
	SetBit(&x, 0);
	SetBit(&x, 0);

#endif
#if 0
	/*byte *x = malloc(5 * 6 * sizeof(byte) );*/
	
	if (CheckBit(x, 0))
	{
		printf("da");
	}
	else
	{
		printf("nu");
	}
#endif
	printf("%d", 5/2);
	return 0;
}

