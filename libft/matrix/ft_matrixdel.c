/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:25:34 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/16 10:25:35 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Frees an array of strings, and puts the pointer to NULL.
*/

void	ft_matrixdel(char ***matrix)
{
	int	i;

	if (matrix && *matrix && **matrix)
	{
		i = 0;
		while ((*matrix)[i])
		{
			ft_strdel(&(*matrix)[i]);
			i++;
		}
		free(*matrix);
		*matrix = NULL;
	}
}
