/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:21:10 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/27 13:14:19 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Converts a number of specified base in the initial portion of a string
**		to an long.
*/

long	ft_atolbase(char *str, unsigned int base)
{
	long	num;
	long	sign;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9' && *str <= (char)(base + '0')) ||
			(*str >= 'a' && *str <= 'z' && *str <= (char)(base - 11 + 'a')) ||
			(*str >= 'A' && *str <= 'Z' && *str <= (char)(base - 11 + 'A')))
	{
		if (*str >= '0' && *str <= '9')
			num = (num * base) + (*str - '0');
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
			num = (num * base) + (ft_tolower(*str) - 'a' + 10);
		str++;
	}
	return (sign * num);
}
