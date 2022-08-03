/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:25:20 by yichan            #+#    #+#             */
/*   Updated: 2022/08/03 14:37:50 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count(unsigned long n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i ++;
	}
	return (i);
}

char	*ft_uitoa(unsigned long nb, t_flag *fmt)
{
	char		*res;
	size_t		i;
	
	i = count(nb);
	// printf("res: %zu", nb);
	// if (fmt->precisexist && fmt->dot && nb == 0 && fmt->precisionstate)
	// 	return (ft_strdup("0"));
	// printf("precisexist: %zu", fmt->precisexist);
	// printf("precisonstate: %zu", fmt->precisionstate);
	// printf("precision: %zu", fmt->precision);
	// printf("box: %zu", fmt->box);
	// if (!fmt->precision && fmt->dot && nb == 0)
	// 	return (ft_strdup("0"));
	// if (fmt->)
	if (!fmt->precisionstate && fmt->dot && nb == 0 )
		return (ft_strdup(" "));
	// if (fmt->precisionstate == 1 && nb == 0)
	// 	return (ft_strdup(""));
	if (nb == 0)
		return (ft_strdup("0"));
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = '\0';
	while (i--)
	{
		res[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	// printf("res: %s", res);
	return (res);
}