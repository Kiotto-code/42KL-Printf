/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:50:14 by yichan            #+#    #+#             */
/*   Updated: 2022/07/29 22:44:15 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_printfd(t_flag *fmt)
{
    long long nbrlen;
    long long fulllen;
    long long nbr;
    long long absolute;
    
    fulllen = 0;
    nbr = va_arg(fmt->args, long long);
    absolute = (nbr<0 && fulllen+1)? -nbr : nbr;
    nbrlen = ft_countlen(absolute, 10);
    fulllen += nbrlen;
    if (fmt->precision > fulllen)
        fmt->hole = fmt->precision - fulllen;
    if (fmt->)
    
}