/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:56:53 by yichan            #+#    #+#             */
/*   Updated: 2022/07/20 22:29:45 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

/*intialize the variable for format modification*/
static void	state_setup(t_flag *fmt)
{
	fmt->width = 0;
	fmt->precision = 0;
	fmt->hash = 0;
	fmt->zero = 0;
	fmt->minus = 0;
	fmt->space = 0;
	fmt->plus = 0;
	fmt->dot = 0;
}

//modified the format when go through flags instead of conversion-type
static void	ft_subflag(char c, t_flag *fmt)
{
	if (ft_isdigit(c))
	{
		if (fmt->dot || fmt->zero)
			fmt->precision = fmt->precision * 10 + c - '0';
		else
		{
			if (!fmt->width && c == '0')
				fmt->zero = 1;
			else
				fmt->width = fmt->width * 10 + c - '0';
		}
	}
	else if (c == '#')
		fmt->hash += 1;
	else if (c == '-')
		fmt->minus += 1;
	else if (c == ' ')
		fmt->space += 1;
	else if (c == '+')
		fmt->plus += 1;
	else if (c == '.')
		fmt->dot += 1;
}

// go through all the character one by o
// ne to check its flag and conversion type
// call subflag('ft_subflag') function
//  if detect flags symbols
// apply the relevant function when go 
//through each conversion-type(using 'ft_strchr')
static char *main_reader(char *str, t_flag *fmt)
{
	while (*str && !ft_strchr("cspdiuxX%", *str))
	{
		ft_subflag(*str, fmt);
		str++;
	}
	if (*str == 'c')
		ft_printfc(fmt);
	// else if (*str == 's')
	// else if (*str == 'p')
	// else if (*str == 'd')
	// else if (*str == 'i')
	// else if (*str == 'u')
	// else if (*str == 'x')
	// else if (*str == 'X')
	// else if (*str == '%')
	return (str);
}

int	ft_printf(const char *str, ...)
{
	int		counter;
	t_flag	*fmt;
	
	counter = 0;
	fmt = malloc(sizeof(t_flag));
	if (!fmt)
		return (0);
	state_setup(fmt);
	va_start(fmt->args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str = main_reader((char *)str, fmt);
			state_setup(fmt);
		}
		else if(counter++)
			ft_putchar_fd(*str++,1);
	}
	va_end(fmt->args);
	free(fmt);
	return (counter);
}

int main(void)
{
    ft_printf("%c",'a');
    return (0);
}