#include "printf.h"
#include "libft/libft.h"

static void state_setup(w_lst *fmt)
{
    fmt->state = 0;
    fmt->width = 0;
    fmt->precision = 0;
    fmt->length = 0;
    fmt->type = 0;
    fmt->flag = 0;
    fmt->str = NULL;
    fmt->num = 0;
    fmt->c = 0;
}

int ft_printf(const char *restrict format, ...)
{
    int ret;
    w_lst *fmt;
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