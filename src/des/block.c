/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 19:36:03 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/10 19:36:05 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

static const char	g_base64[64] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
	'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
	'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

int	des_block(int fd, void *ptr)
{
	uint8_t	*block;
	int		bytes_read;
	uint8_t	padding;

	block = ptr;
	bzero(block, (64 / 8));
	bytes_read = read(fd, block, BLOCK_SIZE / 8);
	if (bytes_read == 0)
		return (0);
	if (bytes_read < BLOCK_SIZE / 8)
	{
		padding = (BLOCK_SIZE / 8) - bytes_read;
		while (bytes_read < BLOCK_SIZE / 8)
			block[bytes_read++] = padding;
	}
	return (1);
}

static void	write_base64(t_env env, uint64_t block, int bytes)
{
	int bits = bytes * 8;
	int sextet;

	while (bits)
	{
		sextet = block & 0xFC;
		block >>= 6;
		bits -= 6;
		write(env.output_fd, g_base64(sextet), 1)
	}
}

/*
**	The padding at the very end of the final block takes the form of
**		the number refering to how many "empty" bytes there are.
**		(0x1 to 0x7)
*/
int	write_block(t_env env, void *ptr)
{
	uint8_t			block[8] = NULL;
	static uint8_t	on_deck[8] = NULL;
	int				bytes;

	block = ft_memcpy(block, on_deck, BLOCK_SIZE / 8);
	on_deck = ft_memcpy(on_deck, ptr, BLOCK_SIZE / 8);
	if (block == NULL)
		return (1);
	bytes = BLOCK_SIZE / 8;
	if (on_deck == NULL && env.mode == 1
		&& (block[7] < (BLOCK_SIZE / 8)))
	{
			ft_printf("[%c] [%x]\n", block[7], block[7]);
			bytes -= block[7];
	}
	write(env.output_fd, &block, bytes);
	return ((on_deck == NULL) ? 0 : 1);
}