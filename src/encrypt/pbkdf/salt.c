/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:33:06 by mtaylor           #+#    #+#             */
/*   Updated: 2019/08/16 11:33:07 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

#define SIZE (64 / 8)

/*
**	Generates random salt, by reading 64-bits from /dev/random
*/

static uint64_t	random_salt(void)
{
	uint64_t	salt;
	int			fd;

	fd = open("/dev/random", O_RDONLY);
	read(fd, &salt, SIZE);
	close(fd);
	return (salt);
}

static uint64_t	read_salt_prefix(t_env *env)
{
	uint64_t	buf;

	if (read_block(env, &buf, SIZE) &&
		ft_memcmp(&buf, "Salted__", SIZE) == 0)
	{
		read_block(env, &buf, SIZE);
		return (endianflip_64bit(buf));
	}
	handle_error(error_command, "salt error");
	return (0);
}

static void	write_salt_prefix(t_env *env, uint64_t salt)
{
	write_block(env, "Salted__", SIZE);
	salt = endianflip_64bit(salt);
	write_block(env, &salt, SIZE);
}

void	handle_salt(t_env *env)
{
	if (!(env->flags & flag_salt))
	{
		if (env->mode == 0)
			env->salt = random_salt();
		else
			env->salt = read_salt_prefix(env);
		env->flags |= flag_salt;
	}
	if ((env->flags & flag_salt) && env->mode == 0)
		write_salt_prefix(env, env->salt);
}