/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:26:28 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/09 15:26:35 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashing.h"

#define DIGEST_SIZE 128
#define BLOCK_SIZE 512
#define ROUNDS 64
#define WORD_COUNT 16

static const uint32_t	g_h_init[4] = {
	0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476
};

static const uint32_t	g_k[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

static const int		g_s[4][4] = {
	{7, 12, 17, 22},
	{5, 9, 14, 20},
	{4, 11, 16, 23},
	{6, 10, 15, 21},
};

#define F(x,y,z)	((x & y) | (~x & z)) + w[round]
#define G(x,y,z)	((x & z) | (y & ~z)) + w[(5 * round + 1) % 16]
#define H(x,y,z)	(x ^ y ^ z)          + w[(3 * round + 5) % 16]
#define I(x,y,z)	(y ^ (x | ~z))       + w[(7 * round) % 16]

static void	md5_compression(uint32_t *state, uint32_t *w)
{
	uint32_t	*v;
	uint32_t	tmp;

	v = ft_memdup(state, DIGEST_SIZE / 8);
	for (int round = 0; round < ROUNDS; round++)
	{
		tmp = v[a] + g_k[round];
		if (round < (16 * 1))
			tmp += F(v[b], v[c], v[d]);
		else if (round < (16 * 2))
			tmp += G(v[b], v[c], v[d]);
		else if (round < (16 * 3))
			tmp += H(v[b], v[c], v[d]);
		else if (round < (16 * 4))
			tmp += I(v[b], v[c], v[d]);
		tmp = v[b] + ROTL(tmp, g_s[round / 16][round % 4]);
		v[a] = v[d];
		v[d] = v[c];
		v[c] = v[b];
		v[b] = tmp;
	}
	for (int i = 0; i < DIGEST_SIZE / 32; i++)
		state[i] += v[i];
	free(v);
}

void	*ft_md5(t_env env)
{
	uint32_t	*state;
	uint32_t	*words;
	int			endflag;

	endflag = 0;
	state = ft_memdup((void*)g_h_init, DIGEST_SIZE / 8);
	words = ft_memalloc(sizeof(uint32_t) * WORD_COUNT);
	while (endflag < 2)
	{
		padded_block((uint8_t*)words, env, &endflag,
						(t_blockpad){BLOCK_SIZE, lil_endian, 64});
		md5_compression(state, words);
	}
	free(words);
	return (state);
}
