/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:40:17 by mtaylor           #+#    #+#             */
/*   Updated: 2019/07/17 12:40:18 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

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

static void	write_block(t_env *env, void* block, int bytes)
{
	if (env->flags & flag_b64)
		write_to_base64(env->output_fd, block, bytes);
	else
		read(env->output_fd, block, bytes);
}

static void	write_salted_prefix(t_env *env, uint64_t salt)
{
	write_block(env, "Salted__", 8);
	write_block(env, &salt, 8);
}

void	ft_des_encode(t_env *env, uint64_t (*f)(t_env*, uint64_t, uint64_t*))
{
	uint64_t	subkey[ROUNDS];
	uint64_t	pre_block;
	uint64_t	post_block;

	ft_pbkdf(env);
	write_salted_prefix(env, endianflip_64bit(env->salt));

	key_schedule(env->key, subkey, env->mode);
	while (get_padded_block(env->input_fd, &pre_block, BLOCK_BYTES))
	{
		post_block = (*f)(env, pre_block, subkey);
		write_block(env, &post_block, BLOCK_BYTES);
	}
	write_block(env, &post_block, 0);
}
