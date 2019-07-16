/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_schedule.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:44:58 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/03 18:44:59 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

#define ROTL_28(x, n) (((x) << (n)) | ((x) >> (28 - (n))))

static const int	g_permuted_choice1[56] = {
	57, 49, 41, 33, 25, 17,  9,
	 1, 58, 50, 42, 34, 26, 18,
	10,  2, 59, 51, 43, 35, 27,
	19, 11,  3, 60, 52, 44, 36,
	63, 55, 47, 39, 31, 23, 15,
	 7, 62, 54, 46, 38, 30, 22,
	14,  6, 61, 53, 45, 37, 29,
	21, 13,  5, 28, 20, 12,  4
};

static const int	g_rotations[16] = {
	1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

static const int	g_permuted_choice2[48] = {
	14, 17, 11, 24,  1,  5,
	 3, 28, 15,  6, 21, 10,
	23, 19, 12,  4, 26,  8,
	16,  7, 27, 20, 13,  2,
	41, 52, 31, 37, 47, 55,
	30, 40, 51, 45, 33, 48,
	44, 49, 39, 56, 34, 53,
	46, 42, 50, 36, 29, 32
};

/*
**	Inverts the order of the keys, for decryption.
*/
static void	decrypt_mode(uint64_t subkey[])
{
	uint64_t	tmp;
	int			a = 0;
	int			z = ROUNDS - 1;

	while ((a + 1) <= (ROUNDS / 2))
	{
		tmp = subkey[a];
		subkey[a] = subkey[z];
		subkey[z] = tmp;
		a++;
		z--;
	}
}

/*
**	Derive 16 subkeys (each 48-bits) from the key (64-bits).
**		permuted choice 1	64-bits	to 56-bits
**		           halves	28-bits
**		permuted choice 2	56-bits to 48-bits
*/
void	key_schedule(uint64_t key, uint64_t subkey[], int mode)
{
	uint32_t	left;
	uint32_t	right;

	key = reorder_bits(key, g_permuted_choice1, 56);
	split_into_halves(key, 56, &left, &right);
	for (int i = 0; i < ROUNDS; i++)
	{
		left = ROTL_28(left, g_rotations[i]);
		right = ROTL_28(right, g_rotations[i]);
		subkey[i] = rejoin_halves(left, right, 28);
		subkey[i] = reorder_bits(subkey[i], g_permuted_choice2, 48);
	}
	if (mode == 1)
		decrypt_mode(subkey);
}