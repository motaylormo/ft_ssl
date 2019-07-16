/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:07:36 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/09 12:07:38 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

#define FIRSTBIT 0x8000000000000000

/*
**	Takes a right-justified bit field of the specified size,
**		and places it in the left-justified position in a 64-bit field.
*/
uint64_t	left_justify64(uint64_t val, int bits)
{
	return (val << (64 - bits));
}

/*
**	Reorders the bits of a left-justified 64-bit field
**		in accordance with the table given.
**	Output is also a left-justified 64-bit field.
*/
uint64_t	reorder_bits(uint64_t src, const int order[], int n)
{
	uint64_t	dst;

	dst = 0;
	for (int i = 0; i < n; i++)
	{
		if ((src << (order[i] - 1)) & FIRSTBIT)
			dst |= FIRSTBIT >> i;
	}
	return (dst);
}

/*
**	Create a mask for the rightmost n bits.
*/
static uint64_t	mask_bits(int n)
{
	uint64_t	mask;

	mask = 0;
	for (int i = 0; i < n; i++)
	{
		mask = (mask << 1) + 1;
	}
	return (mask);
}

/*
**	Converts a left-justified 64-bit field
**		into 2 right-justified 32-bit halves.
*/
void	split_into_halves(uint64_t whole, int whole_bits,
							uint32_t *left, uint32_t *right)
{
	uint64_t	mask;
	int			half_bits;

	half_bits = whole_bits / 2;
	mask = mask_bits(half_bits);
	*left = (whole >> (64 - half_bits)) & mask;
	*right = (whole >> (64 - (half_bits * 2))) & mask;
}

/*
**	Converts 2 right-justified 32-bit halves
**		into 1 left-justified 64-bit field.
*/
uint64_t	rejoin_halves(uint64_t left, uint64_t right, int half_bits)
{
	uint64_t	mask;

	mask = mask_bits(half_bits);
	left = (left & mask) << (64 - half_bits);
	right = (right & mask) << (64 - (half_bits * 2));
	return (left + right);
}