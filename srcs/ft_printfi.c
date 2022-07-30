/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:02:24 by yichan            #+#    #+#             */
/*   Updated: 2022/07/30 21:46:51 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_printfi(t_flag *fmt)
{
    int nbrlen;
    int fulllen;
    long nbr;
    unsigned long absolute;

    fulllen = 0;
    nbr = va_arg(fmt->args, int);
    if (nbr < 0)
    {
        absolute = -nbr;
        fulllen++;
    }
    else
        absolute = nbr;
    nbrlen = ft_countlen((unsigned long)absolute, 10);
    fulllen += nbrlen;
    if (fmt->precision > (size_t)nbrlen)
        fmt->precision = fmt->precision - nbrlen;
    if (fmt->width  > (size_t)fulllen)
        fmt->box = fmt->width - fulllen;
    fmt->len += fmt->box + fmt->precision + fulllen;
    ft_checkdash(fmt, nbr);
}
