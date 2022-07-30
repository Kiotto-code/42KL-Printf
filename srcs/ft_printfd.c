/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:50:14 by yichan            #+#    #+#             */
/*   Updated: 2022/07/30 18:55:11 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void    ft_printfd(t_flag *fmt)
{
    int nbrlen;
    int fulllen;
    int nbr;
    int absolute;
    
    fulllen = 0;
    nbr = va_arg(fmt->args, int);
    absolute = (nbr<0 && ++fulllen)? -nbr : nbr;
    if (nbr < 0)
    {
        absolute = -nbr;
        fulllen++;
    }
    else
    {
        absolute = nbr;
    }
    nbrlen = ft_countlen(absolute, 10);
    fulllen += nbrlen;
    if (fmt->precision > (size_t)nbrlen)
        fmt->precision = fmt->precision - nbrlen;
    if (fmt->width  > (size_t)fulllen)
        fmt->box = fmt->width - fulllen;
    fmt->len += fmt->box + fmt->precision + fulllen;
    
    if (fmt -> minus)
    {
        printdbox(fmt);
        ft_putnbr_fd((nbr), 1);
    }
    else if (!fmt -> minus)
    {
        printdbox(fmt);
        ft_putnbr_fd((nbr), 1);
    }
}