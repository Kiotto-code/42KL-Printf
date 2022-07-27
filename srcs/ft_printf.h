/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:06:11 by yichan            #+#    #+#             */
/*   Updated: 2022/07/27 20:12:28 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_flag
{
	size_t		width;
	size_t		precision;
	size_t		hash;
	size_t		zero;
	size_t		minus;
	size_t		space;
	size_t		plus;
	size_t		dot;
	va_list		args;
	size_t		box;
	size_t		len;
}	t_flag;

int	ft_printf(const char *str, ...);
void ft_printfc(t_flag *fmt);
void ft_prints(t_flag *fmt);

#endif