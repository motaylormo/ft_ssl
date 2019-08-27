/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   en_de_crypt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:05:37 by mtaylor           #+#    #+#             */
/*   Updated: 2019/08/16 12:05:38 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

/*
**	The padding at the very end of the final block takes the form of
**		the number refering to how many "empty" bytes there are.
**		(0x1 to 0x7)
*/
static int	remove_padding(void *ptr)
{
	uint8_t	*block;
	int		len;

	block = ptr;
	len = BLOCK_BYTES;
	if (block[7] < BLOCK_BYTES)
		len -= block[7];
	return (len);
}

/*
**	Decrypt:
**		read normal (plain or b64)
**		write plain - padding
*/

void	ft_des_decrypt(t_env *env, uint64_t (*f)(t_env*, uint64_t, uint64_t*))
{
	uint64_t	subkey[ROUNDS];
	uint64_t	pre_block;
	uint64_t	post_block;

	key_schedule(env->key, subkey, 1);
	read_block(env, &pre_block, BLOCK_BYTES);
	while (1)
	{
		pre_block = endianflip_64bit(pre_block);
		post_block = (*f)(env, pre_block, subkey);
		post_block = endianflip_64bit(post_block);
		if (read_block(env, &pre_block, BLOCK_BYTES) == BLOCK_BYTES)
			write(env->output_fd, &post_block, BLOCK_BYTES);
		else
			break;
	}
	write(env->output_fd, &post_block, remove_padding(&post_block));
}

/*
**	Encrpyt
**		read plain + padding
**		write normal (plain or b64)
**		write 0 to flush out b64
*/

static int	get_padded_block(int fd, void *ptr, int bytes)
{
	uint8_t	*block;
	int		bytes_read;
	uint8_t	padding;

	block = ptr;
	bzero(block, bytes);
	if (!(bytes_read = read(fd, block, bytes)))
		return (0);
	if (bytes_read < bytes)
	{
		padding = bytes - bytes_read;
		while (bytes_read < bytes)
			block[bytes_read++] = padding;
	}
	return (1);
}

void	ft_des_encrypt(t_env *env, uint64_t (*f)(t_env*, uint64_t, uint64_t*))
{
	uint64_t	subkey[ROUNDS];
	uint64_t	pre_block;
	uint64_t	post_block;

	key_schedule(env->key, subkey, 0);
	while (get_padded_block(env->input_fd, &pre_block, BLOCK_BYTES))
	{
		pre_block = endianflip_64bit(pre_block);
		post_block = (*f)(env, pre_block, subkey);
		post_block = endianflip_64bit(post_block);
		write_block(env, &post_block, BLOCK_BYTES);
	}
	if (env->flags & flag_b64)
		write_block(env, &post_block, 0);
}
