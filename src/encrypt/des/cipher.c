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

static const int		g_initial_permutation[64] = {
	58, 50, 42, 34, 26, 18, 10, 2,
	60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,
	64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17,  9, 1,
	59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,
	63, 55, 47, 39, 31, 23, 15, 7
};

static const int		g_final_permutation[64] = {
	40, 8, 48, 16, 56, 24, 64, 32,
	39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30,
	37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28,
	35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26,
	33, 1, 41,  9, 49, 17, 57, 25
};

static const int		g_expansion_permutation[48] = {
	32,  1,  2,  3,  4,  5,  4,  5,
	 6,  7,  8,  9,  8,  9, 10, 11,
	12, 13, 12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21, 20, 21,
	22, 23, 24, 25, 24, 25, 26, 27,
	28, 29, 28, 29, 30, 31, 32,  1
};

static const int		g_substitution_boxes[8][4][16] = {
	{
		{0xe,0x4,0xd,0x1,0x2,0xf,0xb,0x8,0x3,0xa,0x6,0xc,0x5,0x9,0x0,0x7},
		{0x0,0xf,0x7,0x4,0xe,0x2,0xd,0x1,0xa,0x6,0xc,0xb,0x9,0x5,0x3,0x8},
		{0x4,0x1,0xe,0x8,0xd,0x6,0x2,0xb,0xf,0xc,0x9,0x7,0x3,0xa,0x5,0x0},
		{0xf,0xc,0x8,0x2,0x4,0x9,0x1,0x7,0x5,0xb,0x3,0xe,0xa,0x0,0x6,0xd},
	},
	{
		{0xf,0x1,0x8,0xe,0x6,0xb,0x3,0x4,0x9,0x7,0x2,0xd,0xc,0x0,0x5,0xa},
		{0x3,0xd,0x4,0x7,0xf,0x2,0x8,0xe,0xc,0x0,0x1,0xa,0x6,0x9,0xb,0x5},
		{0x0,0xe,0x7,0xb,0xa,0x4,0xd,0x1,0x5,0x8,0xc,0x6,0x9,0x3,0x2,0xf},
		{0xd,0x8,0xa,0x1,0x3,0xf,0x4,0x2,0xb,0x6,0x7,0xc,0x0,0x5,0xe,0x9},
	},
	{
		{0xa,0x0,0x9,0xe,0x6,0x3,0xf,0x5,0x1,0xd,0xc,0x7,0xb,0x4,0x2,0x8},
		{0xd,0x7,0x0,0x9,0x3,0x4,0x6,0xa,0x2,0x8,0x5,0xe,0xc,0xb,0xf,0x1},
		{0xd,0x6,0x4,0x9,0x8,0xf,0x3,0x0,0xb,0x1,0x2,0xc,0x5,0xa,0xe,0x7},
		{0x1,0xa,0xd,0x0,0x6,0x9,0x8,0x7,0x4,0xf,0xe,0x3,0xb,0x5,0x2,0xc},
	},
	{
		{0x7,0xd,0xe,0x3,0x0,0x6,0x9,0xa,0x1,0x2,0x8,0x5,0xb,0xc,0x4,0xf},
		{0xd,0x8,0xb,0x5,0x6,0xf,0x0,0x3,0x4,0x7,0x2,0xc,0x1,0xa,0xe,0x9},
		{0xa,0x6,0x9,0x0,0xc,0xb,0x7,0xd,0xf,0x1,0x3,0xe,0x5,0x2,0x8,0x4},
		{0x3,0xf,0x0,0x6,0xa,0x1,0xd,0x8,0x9,0x4,0x5,0xb,0xc,0x7,0x2,0xe},
	},
	{
		{0x2,0xc,0x4,0x1,0x7,0xa,0xb,0x6,0x8,0x5,0x3,0xf,0xd,0x0,0xe,0x9},
		{0xe,0xb,0x2,0xc,0x4,0x7,0xd,0x1,0x5,0x0,0xf,0xa,0x3,0x9,0x8,0x6},
		{0x4,0x2,0x1,0xb,0xa,0xd,0x7,0x8,0xf,0x9,0xc,0x5,0x6,0x3,0x0,0xe},
		{0xb,0x8,0xc,0x7,0x1,0xe,0x2,0xd,0x6,0xf,0x0,0x9,0xa,0x4,0x5,0x3},
	},
	{
		{0xc,0x1,0xa,0xf,0x9,0x2,0x6,0x8,0x0,0xd,0x3,0x4,0xe,0x7,0x5,0xb},
		{0xa,0xf,0x4,0x2,0x7,0xc,0x9,0x5,0x6,0x1,0xd,0xe,0x0,0xb,0x3,0x8},
		{0x9,0xe,0xf,0x5,0x2,0x8,0xc,0x3,0x7,0x0,0x4,0xa,0x1,0xd,0xb,0x6},
		{0x4,0x3,0x2,0xc,0x9,0x5,0xf,0xa,0xb,0xe,0x1,0x7,0x6,0x0,0x8,0xd},
	},
	{
		{0x4,0xb,0x2,0xe,0xf,0x0,0x8,0xd,0x3,0xc,0x9,0x7,0x5,0xa,0x6,0x1},
		{0xd,0x0,0xb,0x7,0x4,0x9,0x1,0xa,0xe,0x3,0x5,0xc,0x2,0xf,0x8,0x6},
		{0x1,0x4,0xb,0xd,0xc,0x3,0x7,0xe,0xa,0xf,0x6,0x8,0x0,0x5,0x9,0x2},
		{0x6,0xb,0xd,0x8,0x1,0x4,0xa,0x7,0x9,0x5,0x0,0xf,0xe,0x2,0x3,0xc},
	},
	{
		{0xd,0x2,0x8,0x4,0x6,0xf,0xb,0x1,0xa,0x9,0x3,0xe,0x5,0x0,0xc,0x7},
		{0x1,0xf,0xd,0x8,0xa,0x3,0x7,0x4,0xc,0x5,0x6,0xb,0x0,0xe,0x9,0x2},
		{0x7,0xb,0x4,0x1,0x9,0xc,0xe,0x2,0x0,0x6,0xa,0xd,0xf,0x3,0x5,0x8},
		{0x2,0x1,0xe,0x7,0x4,0xa,0x8,0xd,0xf,0xc,0x9,0x0,0x3,0x5,0x6,0xb},
	},
};

static const int		g_pbox_permutation[32] = {
	16,  7, 20, 21, 29, 12, 28, 17,
	 1, 15, 23, 26,  5, 18, 31, 10,
	 2,  8, 24, 14, 32, 27,  3,  9,
	19, 13, 30,  6, 22, 11,  4, 25
};

/*
**	Input (48-bits) is split into chunks of 6-bits. In each sextet:
**		- the first and last bit are combined into a 2-bit number
**		- the middle 4 bits are another number
**	Look it up in the substitution boxes in the form:
**		sbox[nth of sextet][2-bit value][4-bit value]
**	Save the sbox value at that index as 4-bits.
**	Output 32-bits
*/

static uint64_t	sboxes(uint64_t input)
{
	uint32_t	output;
	uint8_t		sextet;
	uint8_t		outer2;
	uint8_t		inner4;

	output = 0;
	for (int i = 0; i < (48 / 6); i++)
	{
		sextet = (input >> (64 - ((i + 1) * 6))) & 0x3F;
		outer2 = ((sextet & 0x20) >> 4) + (sextet & 0x1);
		inner4 = (sextet >> 1) & 0xF;
		output = (output << 4) + g_substitution_boxes[i][outer2][inner4];
	}
	return (left_justify64(output, 32));
}

/*
**	   expansion	32-bits to 48-bits
**	XOR with key	both 48-bits
**	     s-boxes	48-bits to 32-bits
**	     p-boxes	still 32-bits
*/
static uint32_t	feistel(uint32_t half_block, uint64_t subkey)
{
	uint64_t x;

	x = left_justify64(half_block, 32);
	x = reorder_bits(x, g_expansion_permutation, 48);
	x = subkey ^ x;
	x = sboxes(x);
	x = reorder_bits(x, g_pbox_permutation, 32);
	return (x >> 32);
}

uint64_t	cipher(uint64_t block, uint64_t *subkey)
{
	uint32_t	left;
	uint32_t	right;
	uint32_t	tmp;

	block = reorder_bits(block, g_initial_permutation, 64);
	split_into_halves(block, 64, &left, &right);
	for (int i = 0; i < ROUNDS; i++)
	{
		tmp = left ^ feistel(right, subkey[i]);
		left = right;
		right = tmp;
	}
	block = rejoin_halves(right, left, 32);
	block = reorder_bits(block, g_final_permutation, 64);
	return (block);
}