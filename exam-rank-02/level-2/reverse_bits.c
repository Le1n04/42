#include <stdio.h>
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write (1, &bit, 1);
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit = 0;

	while (i > 0)
	{
		bit = bit * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (bit);
}

int main(void)
{
	unsigned char octet = 'B';

	print_bits(octet);
	write (1, "\n", 1);
	unsigned char k = reverse_bits(octet);
	print_bits(k);

	return 0;
}