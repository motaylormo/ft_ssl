/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:25:58 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/09 15:26:16 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashing.h"

#define DIGEST_SIZE 256
#define BLOCK_SIZE 512
#define ROUNDS 64
#define WORD_COUNT 64

static uint32_t	g_sha256_h_init[8] = {
	0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
	0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

static uint32_t	g_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

#define SIG0(x)	(ROTR(x, 2) ^ ROTR(x,13) ^ ROTR(x,22))
#define SIG1(x)	(ROTR(x, 6) ^ ROTR(x,11) ^ ROTR(x,25))
#define S0(x)	(ROTR(x, 7) ^ ROTR(x,18) ^ ((x) >>  3))
#define S1(x)	(ROTR(x,17) ^ ROTR(x,19) ^ ((x) >> 10))

#define EXPN(w,i) S1(w[i - 2]) + w[i - 7] + S0(w[i - 15]) + w[i - 16]

static uint32_t	*sha256_words(uint32_t *w)
{
	endianflip_field_32bit(w, BLOCK_SIZE);
	for (int i = (BLOCK_SIZE / 32); i < WORD_COUNT; i++)
	{
		w[i] = EXPN(w, i);
	}
	return (w);
}

static void		sha256_compression(uint32_t *state, uint32_t *w)
{
	uint32_t	*v;
	uint32_t	tmp1;
	uint32_t	tmp2;

	v = ft_memdup(state, DIGEST_SIZE / 8);
	for (int round = 0; round < ROUNDS; round++)
	{
		tmp1 = v[h] + SIG1(v[e]) + CH(v[e], v[f], v[g])
				+ g_k[round] + w[round];
		tmp2 = SIG0(v[a]) + MAJ(v[a], v[b], v[c]);
		v[h] = v[g];
		v[g] = v[f];
		v[f] = v[e];
		v[e] = v[d] + tmp1;
		v[d] = v[c];
		v[c] = v[b];
		v[b] = v[a];
		v[a] = tmp1 + tmp2;
	}
	for (int i = 0; i < DIGEST_SIZE / 32; i++)
		state[i] += v[i];
	free(v);
}

void		*ft_sha256(t_env env)
{
	uint32_t	*state;
	uint32_t	*words;
	int			endflag;

	endflag = 0;
	state = ft_memdup((void*)g_sha256_h_init, DIGEST_SIZE / 8);
	words = ft_memalloc(sizeof(uint32_t) * WORD_COUNT);
	while (endflag < 2)
	{
		padded_block((uint8_t*)words, env, &endflag,
						(t_blockpad){BLOCK_SIZE, big_endian, 64});
		words = sha256_words(words);
		sha256_compression(state, words);
	}
	free(words);
	endianflip_field_32bit(state, DIGEST_SIZE);
	return (state);
}

/*
**	SHA-224
**	A variant of SHA-256, the only differences:
**		1. Different initialization values for the digest
**		2. Only 224-bits of the hash are used for the checksum.
**			The last 32-bit chunk of the digest is discarded at the end.
*/

static uint32_t	g_sha224_h_init[8] = {
	0xc1059ed8, 0x367cd507, 0x3070dd17, 0xf70e5939,
	0xffc00b31, 0x68581511, 0x64f98fa7, 0xbefa4fa4
};

void		*ft_sha224(t_env env)
{
	uint32_t	*state;
	uint32_t	*words;
	int			endflag;

	endflag = 0;
	state = ft_memdup((void*)g_sha224_h_init, DIGEST_SIZE / 8);
	words = ft_memalloc(sizeof(uint32_t) * WORD_COUNT);
	while (endflag < 2)
	{
		padded_block((uint8_t*)words, env, &endflag,
						(t_blockpad){BLOCK_SIZE, big_endian, 64});
		words = sha256_words(words);
		sha256_compression(state, words);
	}
	free(words);
	endianflip_field_32bit(state, DIGEST_SIZE);
	return (state);
}
