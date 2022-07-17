#ifndef PRINT_F
# define PRINT_F

# include <stdarg.h>
# include <stdlib.g>
# include <unistd.h>
#include "libft/libft.h"

typedef struct v_lst
{
    size_t width;
    int precision;
    int hash;
    int zero;
    int minus;
    int space;
    int plus;
    int dot;
    va_list args;

}   w_lst;

int     ft_printf(const char *format, ...);

void    