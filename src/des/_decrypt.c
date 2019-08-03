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

static int	read_block(t_env *env, void* block, int bytes)
{
	if (env->flags & flag_b64)
		return (read_from_base64(env->input_fd, block, bytes));
	else
		return (read(env->input_fd, block, bytes));
}

static int	read_salted_prefix(t_env *env, void *block)
{
	read_block(env, block, BLOCK_BYTES);
	if (ft_memcmp(block, "Salted__", BLOCK_BYTES) == 0)
	{
		read_block(env, &(env->salt), BLOCK_BYTES);
		env->flags |= flag_salt;
		return (1);
	}
	return (0);
}

void	ft_des_decode(t_env *env, uint64_t (*f)(t_env*, uint64_t, uint64_t*))
{
	uint64_t	subkey[ROUNDS];
	uint64_t	pre_block;
	uint64_t	post_block;

	read_salted_prefix(env, &pre_block);
	ft_pbkdf(env);

	key_schedule(env->key, subkey, env->mode);
	while (read_block(env, &pre_block, BLOCK_BYTES))
	{
		post_block = (*f)(env, pre_block, subkey);
		write(env->output_fd, &post_block, BLOCK_BYTES);
	}
}