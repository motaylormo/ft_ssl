/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbkdf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:38:43 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/08 12:38:45 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

/*
**	Concatenate password + salt, then MD5 hash it
*/

static void	*hash_salted_pass(char *password, uint64_t salt)
{
	int		pass_len;
	char	*salted_pass;
	t_env	md5_env;
	void	*md5_hash;

	pass_len = ft_strlen(password);
	salted_pass = ft_memalloc(pass_len + (64 / 8) + 1);
	ft_memcpy(salted_pass, password, pass_len);
	salt = endianflip_64bit(salt);
	ft_memcpy(salted_pass + pass_len, &salt, (64 / 8));
	ft_bzero(&md5_env, sizeof(md5_env));
	md5_env.input_ptr = salted_pass;
	md5_env.input_ptr_bytes = pass_len + (64 / 8);
	md5_hash = ft_md5(md5_env);
	free(salted_pass);
	endianflip_field_32bit(md5_hash, 128);
	return (md5_hash);
}

/*
**	Password-Based Key Derivation Function
*/

void			ft_pbkdf(t_env *env)
{
	uint32_t	*hash;

	if (!(env->flags & flag_pass))
	{
		env->password = getpass((env->mode == 0) ?
			"enter des encryption password: " :
			"enter des decryption password: ");
		env->flags |= flag_pass;
	}
	handle_salt(env);
	if (env->password)
	{
		hash = hash_salted_pass(env->password, env->salt);
		if (!(env->flags & flag_key))
		{
			env->key = rejoin_halves(hash[0], hash[1], 32);
			env->flags |= flag_key;
		}
		if (!(env->flags & flag_iv))
		{
			env->iv = rejoin_halves(hash[2], hash[3], 32);
			env->flags |= flag_iv;
		}
		free(hash);
	}
}
