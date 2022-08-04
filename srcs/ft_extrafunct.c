/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extrafunct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:37:23 by yichan            #+#    #+#             */
/*   Updated: 2022/08/04 17:18:49 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhexa(unsigned long long nbr)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nbr / 16)
		ft_printhexa(nbr / 16);
	ft_putchar_fd(hexa[nbr % 16], 1);
}

size_t	ft_countlen(unsigned long nbr, int base)
{
	if (!(nbr / base) || nbr == 0)
		return (1);
	return (1 + ft_countlen(nbr / base, base));
}

unsigned long	ft_absolute(long nbr)
{
	unsigned long	absolute;

	if (nbr < 0)
		return (nbr * -1);
	else
		absolute = nbr;
	return (absolute);
}
