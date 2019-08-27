/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:11:38 by mtaylor           #+#    #+#             */
/*   Updated: 2019/08/16 10:11:39 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base64.h"

static int	is_b64_char(char c)
{
	if (c == '=')
		return (1);
	for (int i = 0; i < 64; ++i)
	{
		if (c == g_b64[i])
			return (1);
	}
	return (0);
}

static int	read_block(int fd, uint8_t *encoded4)
{
	int		ret;
	char	c;

	ft_bzero(encoded4, 4);
	ret = 0;
	while (ret < 4)
	{
		if (!read(fd, &c, 1))
			return (0);
		if (is_b64_char(c))
			encoded4[ret++] = c;
	}
	return (1);
}

int		read_from_base64(int fd, void *block, int block_size)
{
	static uint8_t	buf[BUFSIZE];
	static int	buf_bytes = 0;
	uint8_t			encoded4[4];
	int				inc;

	while ((buf_bytes + 3 <= BUFSIZE)
		&& (buf_bytes < block_size)
		&& read_block(fd, encoded4))
	{
		base64_decode_3bytes(buf + buf_bytes, encoded4);
		buf_bytes += 3;
	}
	inc = SMALLER(block_size, buf_bytes);
	ft_memcpy(block, buf, inc);
	buf_bytes -= inc;
	ft_memmove(buf, buf + inc, buf_bytes);
	return (inc);
}