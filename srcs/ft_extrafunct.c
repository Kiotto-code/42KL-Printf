/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extrafunct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:37:23 by yichan            #+#    #+#             */
/*   Updated: 2022/07/31 21:43:30 by yichan           ###   ########.fr       */
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

int     ft_countlen(unsigned long nbr, int base)
{
    if (!(nbr/base))
        return (1);
    return (1 + ft_countlen(nbr/base,base));
}

unsigned long   ft_absolute(long nbr)
{
    unsigned long absolute;
    if (nbr < 0)
        return (nbr * -1);
    else
        absolute = nbr;
    return absolute;
}

void    printdbox(t_flag *fmt, long nbr)
{
    // if (!fmt->space )
    while (!fmt->zero && fmt->box--)
        ft_putchar_fd(' ', 1);
    if (!(fmt->zero || fmt->dot))
        {
            if (nbr <0)
                write (1, "-", 1);
            else if (nbr>0 && fmt->plus)
                write (1, "+", 1);
            else if (fmt->space)
                write (1, " ", 1);
        }
    while (fmt->zero && fmt->box-- && !fmt->dot && !fmt->minus)
        ft_putchar_fd('0', 1);
    while (fmt->dot && fmt->precision--)
        ft_putchar_fd('0', 1);
}


void    ft_checksign(t_flag *fmt, long nbr)
{
    
    if ((fmt->zero || fmt->dot))
    {
        if (fmt -> space && !fmt-> plus && nbr>0)
            write(1, " ", 1);
        else if (nbr < 0)
            write(1, "-", 1);
        else if (!fmt ->space && fmt->plus && nbr>0)
            write(1, "+" ,1);
    }
}
void    ft_checkdash(t_flag *fmt, long nbr, unsigned long absolute)
{
   if (fmt -> minus)
    {
        ft_checksign(fmt, nbr);
        ft_putnbr_fd((absolute), 1);
        printdbox(fmt, nbr);
    }
    else if (!(fmt -> minus))
    {
        printdbox(fmt, nbr);
        ft_checksign(fmt, nbr);
        ft_putnbr_fd((absolute), 1);
    }
}