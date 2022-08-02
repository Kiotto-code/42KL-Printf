/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:06:11 by yichan            #+#    #+#             */
/*   Updated: 2022/08/02 19:24:02 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdio.h>

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
	size_t		precisionstate;
	size_t		precisexist;
	long		limit;
	char *		ascii;
}	t_flag;

int				ft_printf(const char *str, ...);
void			ft_printfc(t_flag *fmt);
void			ft_printfs(t_flag *fmt);
void			ft_printfp(t_flag *fmt);
void			ft_printfd(t_flag *fmt);
void			ft_printfi(t_flag *fmt);
void			ft_printfu(t_flag *fmt);
void			ft_printhexa(unsigned long long nbr);
size_t			ft_countlen(unsigned long nbr, int base);
void			printdbox(t_flag *fmt, long nbr);
void			ft_checkdash(t_flag *fmt, long nbr, unsigned long absolute);
void			ft_checksign(t_flag *fmt, long nbr);
unsigned long	ft_absolute(long nbr);
void			precise(t_flag *fmt);
char			*ft_uitoa(unsigned long nb, t_flag *fmt);
void 			flagadjust(t_flag *fmt, size_t fulllen,long nbr,unsigned long absolute);
void			ft_putascii(t_flag *fmt, char *ascii);


#endif