/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:04:07 by yichan            #+#    #+#             */
/*   Updated: 2022/07/26 16:59:53 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_printfc(t_flag *fmt)
{
	char	c;
    
    c = va_arg(fmt->args, int);
	if (fmt->width > fmt->precision)
        fmt->box = (fmt->width) -1;
    fmt->len += fmt->box +1;
    if (fmt->minus)
    {
        ft_putchar_fd(c, 1);
        while (fmt->box--)
            ft_putchar_fd(' ',1);
    }
    else
    {
        while (fmt->box--)
            ft_putchar_fd(' ',1);
        ft_putchar_fd(c,1);
    }
}