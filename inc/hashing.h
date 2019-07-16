/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:12:29 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/09 12:12:30 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHING_H
# define HASHING_H

# include "ft_ssl.h"

/*
**	ROTL	rotate left (circular left shift)
**	ROTR	rotate right (circular right shift)
*/
# define ROTL(x, n)	(((x) << (n)) | ((x) >> ((sizeof(x) * 8) - (n))))
# define ROTR(x, n)	(((x) >> (n)) | ((x) << ((sizeof(x) * 8) - (n))))

/*
**	Majority function:
**			Maj(x, y, z) = (x ∧ y) ⊕ (x ∧ z) ⊕ (y ∧ z)
**		For each bit index, that result bit according to
**		what bit is the the majority amongst 𝑥 𝑦 𝑧 at this index.
**
**	Choose function:
**			Ch(x, y, z) = (x ∧ y) ⊕ (¬x ∧ z)
**		For each bit index, that result bit is according to
**		the bit from 𝑦 or 𝑧, depending on the bit from 𝑥.
**			{ x = 1,	y }
**			{ x = 0,	z }
**
**	Parity function:
**			Par(x, y, z) = x ⊕ y ⊕ z
**		For each bit index, that result bit is according to
**		the parity of 𝑥 𝑦 𝑧 at this index.
**		Parity is whether it contains an odd or even number of 1-bits.
**			1	odd
**			0	even
*/
# define MAJ(x,y,z)	(((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define CH(x,y,z)	(((x) & (y)) ^ (~(x) & (z)))
# define PAR(x,y,z)	((x) ^ (y) ^ (z))

typedef struct	s_blockpad
{
	int			block_size;
	int			endian;
	int			len_size;
}				t_blockpad;

enum	e_abc{
	a,
	b,
	c,
	d,
	e,
	f,
	g,
	h
};

enum	e_endian{
	lil_endian,
	big_endian
};

/*
**	block.c
*/
void	padded_block(uint8_t *block, t_env env, int *endflag, t_blockpad bp);

#endif
