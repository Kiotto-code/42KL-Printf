#include "printf.h"

static void state_setup(w_lst *fmt)
{
    fmt->width = 0;
    fmt->precision = 0;
    fmt->hash = 0;
    fmt->zero = 0;
    fmt->minus = 0;
    fmt->space = 0;
    fmt->plus = 0;
    fmt->dot = 0;
}

static void ft_subprocess(char c, w_lst *fmt)
{
    if(ft_isdigit(c))
    {
        if (fmt->dot || fmt->zero)
    }
}

int ft_printf(const char *restrict format, ...)
{
    int res;
    w_lst *fmt;
    va_list args;

    res = 0;
    fmt = malloc(sizeof(w_lst));
    if (!fmt)
        return (-1);
    state_setup(fmt);

    va_start(fmt->ap, format);
    while (*str)
    
    va_end(fmt->ap);
    free(fmt);
    return (ret);
}