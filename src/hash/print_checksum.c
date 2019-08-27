/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_checksum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:18:07 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/09 16:18:10 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_shell.h"

static void	print_hex(int fd, uint8_t *hash, int bytes)
{
	for (int i = 0; i < bytes; i++)
		ft_dprintf(fd, "%.2x", hash[i]);
	ft_dprintf(fd, "\n");
}

void	print_checksum(int flags, int fd, uint8_t *hash, int bytes)
{
	if (flags & flag_b64)
	{
		write_to_base64(fd, hash, bytes);
		write_to_base64(fd, hash, 0);
	}
	else
		print_hex(fd, hash, bytes);
}