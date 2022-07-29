/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:40:09 by yichan            #+#    #+#             */
/*   Updated: 2022/07/28 22:08:32 by yichan           ###   ########.fr       */
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