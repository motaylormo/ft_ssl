/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:21:08 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/02 14:21:28 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashing.h"

static void	add_64bit_len(uint8_t *block, int byte_size, uint64_t len, int endian)
{
	int	bytes_from_end;
	int	shift;

	bytes_from_end = 8;
	shift = (endian == big_endian) ? 56 : 0;
	while (bytes_from_end > 0)
	{
		block[byte_size - bytes_from_end] = (len >> shift) & 0xFF;
		bytes_from_end--;
		if (endian == big_endian)
			shift -= 8;
		if (endian == lil_endian)
			shift += 8;
	}
}

/*
**	If there's a string, read from that.
**	Elsewise, read from the fd.
*/

static int	read_block(uint8_t *block, t_env env, int bits, int index)
{
	int	block_bytes;
	int	bytes_read;

	block_bytes = bits / 8;
	index /= 8;
	ft_bzero(block, block_bytes);
	if (env.input_ptr != NULL)
	{
		bytes_read = ((block_bytes) <= (env.input_ptr_bytes - index)) ?
						block_bytes : (env.input_ptr_bytes - index);
		block = ft_memcpy(block, env.input_ptr + index, bytes_read);
	}
	else
		bytes_read = read(env.input_fd, block, block_bytes);
	return (bytes_read);
}


/*
**	Block formatting goes:
**		1. All the bytes of message
**		2. The byte 10000000
**		3. Zeros to make up the length so it divides evenly into the block size
**		4. The number of bits in the message portion
**
**	Length at the end is given as:
**		MD5		64-bit little endian
**		SHA1	64-bit big endian
**		SHA256	64-bit big endian
**		SHA512	128-bit big endian (but since there's no 128-bit datatype
**									and it doesn't REALLY need to handle
**									stuff THAT big, this acts like
**									64-bits of 0-padding + 64-bits of length)
*/

void		padded_block(uint8_t *block, t_env env, int *endflag,
						t_blockpad bp)
{
	static uint64_t	len = 0;
	int				bytes_read;

	if (*endflag == 2)
		return ;
	bytes_read = read_block(block, env, bp.block_size, len);
	len += bytes_read * 8;
	if ((bytes_read * 8 < bp.block_size) && (*endflag < 1))
	{
		block[bytes_read++] = 1 << 7;
		*endflag = 1;
	}
	if (bp.block_size - (bytes_read * 8) >= bp.len_size)
	{
		add_64bit_len(block, bp.block_size / 8, len, bp.endian);
		*endflag = 2;
		len = 0;
	}
}
