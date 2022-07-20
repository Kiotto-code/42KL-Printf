/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:06:11 by yichan            #+#    #+#             */
/*   Updated: 2022/07/20 21:01:43 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_flag
{
	size_t	width;
	int		precision;
	int		hash;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		dot;
	va_list	args;
}	t_flag;

int	ft_printf(const char *format, ...);
int ft_printfc(t_flag *fmt);

#endif