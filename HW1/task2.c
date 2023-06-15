#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void print_binary(unsigned long long number)
{
	if (number >> 1)
	{
		print_binary(number >> 1);
	}
	putchar((number & 1) ? '1' : '0');
}

void read() {
	int i = 0;
	char c = '0';
	unsigned long long num, mask;
	num = 0;
	mask = 0x7FFFFFFFFFFFFFFE;
	while (c != '\n' && i < 8) {
		c = getchar();
		i++;
		num = num << 8;
		num += c;
	}
	if ((num & 1) == 1) {
		num = num ^ mask;
	}
	else {
		unsigned long long numnum, fir, sec, bit;
		numnum = num & mask;
		fir = numnum << 31;
		sec = numnum >> 31;
		bit = ~mask;
		bit = bit & num;
		num = fir | sec;
		num = num | bit;
	}
	printf("%llu", num);
	printf("%c", '\n');
	if (c != '\n') {
		read();
	}
}


int main() {
	read();
	//print_binary(0x7FFFFFFFFFFFFFFE);
}
