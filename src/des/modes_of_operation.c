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

static int	des_block(int fd, void *ptr)
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

/*
**	The padding at the very end of the final block takes the form of
**		the number refering to how many "empty" bytes there are.
**		(0x1 to 0x7)
*/
static int	remove_padding(t_env env, void *ptr)
{
	uint8_t	*block;
	int		len;

	block = ptr;
	len = BLOCK_SIZE / 8;
	if (env.mode == 1 && (block[7] < (BLOCK_SIZE / 8)))
		len -= block[7];
	return (len);
}

/*
**	Electronic Codebook (ECB)
*/
uint64_t	ft_des_ecb(t_env *env, uint64_t block, uint64_t *subkey)
{
	uint64_t	crypted_block;

	(void)env;
	crypted_block = des_inner(block, subkey);
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

	if (env->mode == 0)
		block ^= env->iv;
	crypted_block = des_inner(block, subkey);
	if (env->mode == 1)
		crypted_block ^= env->iv;
	env->iv = (env->mode == 1) ? block : crypted_block;
	return (crypted_block);
}

void	ft_des(t_env env, uint64_t (*f)(t_env*, uint64_t, uint64_t*))
{
	uint64_t	subkey[ROUNDS];
	uint64_t	block;
	uint64_t	crypted_block;
	uint64_t	on_deck;
	int			endflag;

	key_schedule(env.key, subkey, env.mode);
	endflag = 0;
	while (des_block(env.input_fd, &block))
	{
		block = endianflip_64bit(block);
		crypted_block = (*f)(&env, block, subkey);
		crypted_block = endianflip_64bit(crypted_block);

		if (endflag == 1)
			write(env.output_fd, &on_deck, BLOCK_SIZE / 8);
		else
			endflag = 1;
		on_deck = crypted_block;
	}
	write(env.output_fd, &on_deck, remove_padding(env, &on_deck));
}
