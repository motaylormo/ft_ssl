/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:20:20 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/30 15:20:21 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	endianflip_32bit(uint32_t val)
{
	return (
		(val & 0x000000FF) << 24 | (val & 0x0000FF00) << 8 |
		(val & 0x00FF0000) >> 8 | (val & 0xFF000000) >> 24
		);
}

uint64_t	endianflip_64bit(uint64_t val)
{
	return (
		(val & 0x00000000000000FF) << 56 | (val & 0x000000000000FF00) << 40 |
		(val & 0x0000000000FF0000) << 24 | (val & 0x00000000FF000000) << 8 |
		(val & 0x000000FF00000000) >> 8 | (val & 0x0000FF0000000000) >> 24 |
		(val & 0x00FF000000000000) >> 40 | (val & 0xFF00000000000000) >> 56
		);
}

void		endianflip_field_32bit(uint32_t *field, int size)
{
	for (int i = 0; i < size / 32; i++)
		field[i] = endianflip_32bit(field[i]);
}

void		endianflip_field_64bit(uint64_t *field, int size)
{
	for (int i = 0; i < size / 64; i++)
		field[i] = endianflip_64bit(field[i]);
}
