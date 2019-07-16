/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bitfield.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:18:07 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/09 16:18:10 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_shell.h"

void	print_hex(int fd, void *ptr, int bytes)
{
	uint8_t	*field;

	field = ptr;
	for (int i = 0; i < bytes; i++)
	{
		ft_dprintf(fd, "%.2x", field[i]);
	}
}

void	print_base64(int fd, void *ptr, int bytes)
{
	uint8_t	*field = ptr;
	uint8_t	plain3[3];
	char	encyp4[4];

	for (int i = 0; i < bytes; i += 3)
	{
		ft_bzero(plain3, 3);
		ft_memcpy(plain3, field + i, (bytes < 3) ? bytes : 3);
		base64_encode_3bytes(encyp4, plain3, bytes - i);
		write(fd, encyp4, 4);
	}
}
