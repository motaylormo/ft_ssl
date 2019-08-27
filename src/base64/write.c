/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:11:41 by mtaylor           #+#    #+#             */
/*   Updated: 2019/08/16 10:11:42 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base64.h"

static void	print_b64(int fd, void *ptr, int bytes)
{
	uint8_t	*field = ptr;
	uint8_t	plain3[3];
	uint8_t	encyp4[4];

	for (int i = 0; i < bytes; i += 3)
	{
		ft_bzero(plain3, 3);
		ft_memcpy(plain3, field + i, (bytes < 3) ? bytes : 3);
		base64_encode_3bytes(encyp4, plain3, bytes - i);
		write(fd, encyp4, 4);
	}
	ft_dprintf(fd, "\n");
}

int		write_to_base64(int fd, void *block, int block_bytes)
{
	static uint8_t	buf[BUFSIZE];
	static int	buf_bytes = 0;
	int				inc;

	if (block_bytes == 0)
	{
		print_b64(fd, buf, buf_bytes);
		buf_bytes = 0;
		return (0);
	}
	while (block_bytes > 0)
	{
		inc = SMALLER(block_bytes, BYTES_PER_LINE);
		ft_memcpy(buf + buf_bytes, block, inc);
		buf_bytes += inc;
		block += inc;
		block_bytes -= inc;
		if (buf_bytes >= BYTES_PER_LINE)
		{
			print_b64(fd, buf, BYTES_PER_LINE);
			buf_bytes -= BYTES_PER_LINE;
			ft_memmove(buf, buf + BYTES_PER_LINE, buf_bytes);
		}
	}
	return (1);
}