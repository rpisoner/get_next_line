#include <stdio.h>

void	func(void)
{
	static int	x = 3;

	printf("%d\n", x);
	x = x + 1;
}

int	main(void)
{
	func();
	func();
	func();
	return (0);
}
