/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:02:24 by yichan            #+#    #+#             */
/*   Updated: 2022/08/02 22:50:56 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    flagadjust(t_flag *fmt, size_t fulllen,long nbr,unsigned long absolute)
{
	if (fmt->width  > (size_t)fulllen)
		fmt->box = fmt->width - fulllen - fmt->precision;
	if (fmt->precision < fmt->width)
		fmt->len += fmt->box + fmt->precision + fulllen;
	else
		fmt->len += fmt->precision + fulllen;
	if	((fmt->minus && fmt->zero) || fmt->precision >= fmt->box)
		fmt->zero = 0;
	if	(fmt->space && fmt->dot)
		fmt->box--;
	if (fmt->space && fmt->limit)
		fmt->limit --;
	if (fmt->zero && fmt->precision < fmt->width && fmt->precisexist)
		fmt->zero = 0;
	fmt->precisionstate = fmt->precision;
	// printf("B$: %zu",fmt->precisionstate);
	ft_checkdash(fmt, nbr, absolute);
}

void	ft_printfi(t_flag *fmt)
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
	if (nbrlen > fmt->precision)
		fmt->limit += fmt->precision;
	fulllen += nbrlen;
	if (fmt->precision >= nbrlen)
		fmt->precision -= nbrlen;
	else if (fmt->precision < nbrlen)
		fmt->precision = 0;
	flagadjust(fmt,  fulllen, nbr, absolute);
}