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
	uint64_t	crypted_block;

	(void)env;
	block = endianflip_64bit(block);
	crypted_block = des_cipher(block, subkey);
	crypted_block = endianflip_64bit(crypted_block);
	return (crypted_block);
}

/*
**	Cipher Block Chaining (CBC)
**		Encryption: XOR with iv ~before~ encryption
**		Decryption: XOR with iv ~after~ decryption
*/
uint64_t	ft_des_cbc(t_env *env, uint64_t block, uint64_t *subkey)
{
	uint64_t	crypted_block;

	block = endianflip_64bit(block);
	if (env->mode == 0)
		block ^= env->iv;
	crypted_block = des_cipher(block, subkey);
	if (env->mode == 1)
		crypted_block ^= env->iv;
	env->iv = (env->mode == 1) ? block : crypted_block;
	crypted_block = endianflip_64bit(crypted_block);
	return (crypted_block);
}
