#include "srcs/ft_printf.h"

int main()
{
    ft_printf("\n%d\n", ft_printf("%d", -7));
    ft_printf("\n%d\n", ft_printf("42 - 84 is %d", (int)-42));
    ft_printf("\n%d\n", ft_printf("%d %d", 2147483647, (int)-2147483648));
    return (0);
}