/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extrafunct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:37:23 by yichan            #+#    #+#             */
/*   Updated: 2022/07/29 23:26:24 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_printhexa(unsigned long long nbr)
{
    char *hexa;

    hexa = "0123456789abcdef";
    if (nbr/16)
        ft_printhexa(nbr/16);
    ft_putchar_fd(hexa[nbr%16], 1);
}

int ft_countlen(unsigned long long nbr, int base)
{
    if (!(nbr/base))
        return (1);
    return (1 + ft_countlen(nbr/base,base));
}

