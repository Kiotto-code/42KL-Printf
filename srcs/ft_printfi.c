/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:02:24 by yichan            #+#    #+#             */
/*   Updated: 2022/07/31 23:32:11 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_printfi(t_flag *fmt)
{
    size_t nbrlen;
    size_t fulllen;
    long nbr;
    unsigned long absolute;

    fulllen = 0;
    nbr = (long)va_arg(fmt->args, int);
    if (nbr == 0 && fmt->dot && !fmt->width)
        return ;
    if (nbr < 0)
        fulllen++;
    absolute = ft_absolute(nbr);
    nbrlen = ft_countlen((unsigned long)absolute, 10);
    fulllen += nbrlen;
    if (fmt->precision >= (size_t)nbrlen)
        fmt->precision -= nbrlen;
    else
        fmt->precision = 0;
    if (fmt->width  > (size_t)fulllen)
        fmt->box = fmt->width - fulllen;
    fmt->len += fmt->box + fmt->precision + fulllen;
    if (fmt->space && fmt->dot)
        fmt->box--;
    ft_checkdash(fmt, nbr, absolute);
}