/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:06:11 by yichan            #+#    #+#             */
/*   Updated: 2022/07/30 16:08:45 by yichan           ###   ########.fr       */
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
	size_t		hole;
}	t_flag;

int		ft_printf(const char *str, ...);
void	ft_printfc(t_flag *fmt);
void	ft_printfs(t_flag *fmt);
void    ft_printfp(t_flag *fmt);
void    ft_printfd(t_flag *fmt);
void	ft_printhexa(unsigned long long nbr);
int 	ft_countlen(unsigned long long nbr, int base);
void    printdbox(t_flag *fmt);


#endif