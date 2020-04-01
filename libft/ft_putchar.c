#include <unistd.h>
void	ft_putchar(int a)
{
	write(1, &a, 1);
}
