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
**	ROTL	bitwise rotation left
**	ROTR	bitwise rotation right
*/
# define ROTL(x,n)	(((x) << (n)) | ((x) >> ((sizeof(x) * 8) - (n))))
# define ROTR(x,n)	(((x) >> (n)) | ((x) << ((sizeof(x) * 8) - (n))))

/*
**	MAJ		majority function
**	CH		choose function
**	PAR		parity function
*/
# define MAJ(x,y,z)	(((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define CH(x,y,z)	(((x) & (y)) ^ (~(x) & (z)))
# define PAR(x,y,z)	((x) ^ (y) ^ (z))

typedef struct	s_blockpad
{
	int	block_size;
	int	endian;
	int	len_size;
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
void			padded_block(uint8_t *block, t_env env, int *endflag,
								t_blockpad bp);

#endif
