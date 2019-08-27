/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:16:05 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/09 12:16:06 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DES_H
# define DES_H

/*
**	<pwd.h>	for getpass
*/
# include "ft_ssl.h"
# include <pwd.h>

# define BLOCK_SIZE 64
# define ROUNDS 16
# define BLOCK_BYTES (BLOCK_SIZE / 8)

/*
**	core funcs
*/
void		key_schedule(uint64_t key, uint64_t subkey[], int mode);
uint64_t	cipher(uint64_t block, uint64_t *subkey);
void		handle_salt(t_env *env);

/*
**	util funcs
*/
uint64_t	reorder_bits(uint64_t src, const int order[], int n);
uint64_t	left_justify64(uint64_t val, int bits);
void		split_into_halves(uint64_t whole, int whole_bits,
							uint32_t *left, uint32_t *right);
uint64_t	rejoin_halves(uint64_t left, uint64_t right, int half_bits);

int			read_block(t_env *env, void *block, int bytes);
void		write_block(t_env *env, void *block, int bytes);

#endif
