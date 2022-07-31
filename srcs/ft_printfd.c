/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:50:14 by yichan            #+#    #+#             */
/*   Updated: 2022/07/31 18:58:32 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void    ft_printfd(t_flag *fmt)
{
    int nbrlen;
    int fulllen;
    long nbr;
    unsigned long absolute;

    fulllen = 0;
    nbr = va_arg(fmt->args, int);
    if (nbr < 0)
        fulllen++;
    absolute = ft_absolute(nbr);
    nbrlen = ft_countlen((unsigned long)absolute, 10);
    fulllen += nbrlen;
    if (fmt->precision >= (size_t)nbrlen)
        fmt->precision = fmt->precision - nbrlen;
    if (fmt->width  > (size_t)fulllen)
        fmt->box = fmt->width - fulllen;
    fmt->len += fmt->box + fmt->precision + fulllen;
    if (fmt->space)
        fmt->box--;
    // if (fmt->space && nbr>0)
    //     fmt->len++;
    // if (fmt -> space && !fmt -> plus && !(nbr<0))
    //     write (1, " ", 1);
    ft_checkdash(fmt, nbr, absolute);
}