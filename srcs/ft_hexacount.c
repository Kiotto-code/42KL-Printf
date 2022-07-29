/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexacount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:30:48 by yichan            #+#    #+#             */
/*   Updated: 2022/07/28 21:36:39 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hexacount(unsigned long long nbr, int base)
{
    if (!(nbr/base))
        return (1);
    return (1 + ft_hexacount(nbr/base,base));
}

