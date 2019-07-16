/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:51:05 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/08 14:40:13 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Outputs one string, then '\n', to standard output.
*/

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
