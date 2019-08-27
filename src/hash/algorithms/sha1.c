/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:25:58 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/09 15:26:16 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashing.h"

#define DIGEST_SIZE 160
#define BLOCK_SIZE 512
#define ROUNDS 80
#define WORD_COUNT 80

static uint32_t	g_h_init[5] = {
	0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476, 0xc3d2e1f0
};

static uint32_t	g_k[4] = {
	0x5a827999, 0x6ed9eba1, 0x8f1bbcdc, 0xca62c1d6
};

#define F(x,y,z)	CH(x,y,z)  + g_k[0]
#define G(x,y,z)	PAR(x,y,z) + g_k[1]
#define H(x,y,z)	MAJ(x,y,z) + g_k[2]
#define I(x,y,z)	PAR(x,y,z) + g_k[3]

#define EXPN(w,i) ROTL((w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16]), 1)

static uint32_t	*sha1_words(uint32_t *w)
{
	endianflip_field_32bit(w, BLOCK_SIZE);
	for (int i = (BLOCK_SIZE / 32); i < WORD_COUNT; i++)
	{
		w[i] = EXPN(w, i);
	}
	return (w);
}

static void		sha1_compression(uint32_t *state, uint32_t *w)
{
	uint32_t	*v;
	uint32_t	tmp;

	v = ft_memdup(state, DIGEST_SIZE / 8);
	for (int round = 0; round < ROUNDS; round++)
	{
		tmp = ROTL(v[a], 5) + v[e] + w[round];
		if (round < (20 * 1))
			tmp += F(v[b], v[c], v[d]);
		else if (round < (20 * 2))
			tmp += G(v[b], v[c], v[d]);
		else if (round < (20 * 3))
			tmp += H(v[b], v[c], v[d]);
		else if (round < (20 * 4))
			tmp += I(v[b], v[c], v[d]);
		v[e] = v[d];
		v[d] = v[c];
		v[c] = ROTL(v[b], 30);
		v[b] = v[a];
		v[a] = tmp;
	}
	for (int i = 0; i < DIGEST_SIZE / 32; i++)
		state[i] += v[i];
	free(v);
}

void		*ft_sha1(t_env env)
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
						(t_blockpad){BLOCK_SIZE, big_endian, 64});
		words = sha1_words(words);
		sha1_compression(state, words);
	}
	free(words);
	endianflip_field_32bit(state, DIGEST_SIZE);
	return (state);
}
