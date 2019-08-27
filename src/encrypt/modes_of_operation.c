/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:13:07 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/31 19:13:09 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

/*
**	Electronic Codebook (ECB)
*/
uint64_t	ft_des_ecb(t_env *env, uint64_t block, uint64_t *subkey)
{
	(void)env;
	return (cipher(block, subkey));
}

/*
**	Cipher Block Chaining (CBC)
**		Encryption: XOR with iv ~before~ encryption
**		Decryption: XOR with iv ~after~ decryption
*/
uint64_t	ft_des_cbc(t_env *env, uint64_t pre_block, uint64_t *subkey)
{
	uint64_t	post_block;

	if (env->mode == 0)
		pre_block ^= env->iv;
	post_block = cipher(pre_block, subkey);
	if (env->mode == 1)
		post_block ^= env->iv;
	env->iv = (env->mode == 1) ? pre_block : post_block;
	return (post_block);
}
