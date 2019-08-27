/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:05:43 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/02 15:05:45 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashing.h"

#define DIGEST_SIZE 512
#define BLOCK_SIZE 1024
#define ROUNDS 80
#define WORD_COUNT 80

static uint64_t	g_sha512_h_init[8] = {
	0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b,
	0xa54ff53a5f1d36f1, 0x510e527fade682d1, 0x9b05688c2b3e6c1f,
	0x1f83d9abfb41bd6b, 0x5be0cd19137e2179
};

static uint64_t	g_k[80] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f,
	0xe9b5dba58189dbbc, 0x3956c25bf348b538, 0x59f111f1b605d019,
	0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242,
	0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
	0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 0x2de92c6f592b0275,
	0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
	0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f,
	0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc,
	0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
	0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6,
	0x92722c851482353b, 0xa2bfe8a14cf10364, 0xa81a664bbc423001,
	0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99,
	0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
	0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc,
	0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915,
	0xc67178f2e372532b, 0xca273eceea26619c, 0xd186b8c721c0c207,
	0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba,
	0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
	0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
	0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

#define SIG0(x)	(ROTR(x,28) ^ ROTR(x,34) ^ ROTR(x,39))
#define SIG1(x)	(ROTR(x,14) ^ ROTR(x,18) ^ ROTR(x,41))
#define S0(x)	(ROTR(x, 1) ^ ROTR(x, 8) ^ ((x) >> 7))
#define S1(x)	(ROTR(x,19) ^ ROTR(x,61) ^ ((x) >> 6))

#define EXPN(w,i) S1(w[i - 2]) + w[i - 7] + S0(w[i - 15]) + w[i - 16]

static uint64_t	*sha512_words(uint64_t *w)
{
	endianflip_field_64bit(w, BLOCK_SIZE);
	for (int i = (BLOCK_SIZE / 64); i < WORD_COUNT; i++)
	{
		w[i] = EXPN(w, i);
	}
	return (w);
}

static void		sha512_compression(uint64_t *state, uint64_t *w)
{
	uint64_t	*v;
	uint64_t	tmp1;
	uint64_t	tmp2;

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
	for (int i = 0; i < DIGEST_SIZE / 64; i++)
		state[i] += v[i];
	free(v);
}

void		*ft_sha512(t_env env)
{
	uint64_t	*state;
	uint64_t	*words;
	int			endflag;

	endflag = 0;
	state = ft_memdup((void*)g_sha512_h_init, DIGEST_SIZE / 8);
	words = ft_memalloc(sizeof(uint64_t) * WORD_COUNT);
	while (endflag < 2)
	{
		padded_block((uint8_t*)words, env, &endflag,
						(t_blockpad){BLOCK_SIZE, big_endian, 128});
		words = sha512_words(words);
		sha512_compression(state, words);
	}
	free(words);
	endianflip_field_64bit(state, BLOCK_SIZE);
	return (state);
}

/*
**	SHA-384
**	A variant of SHA-512, the only differences:
**		1. Different initialization values for the digest
**		2. Only 384-bits of the hash are used for the checksum.
**			The last 2, 64-bit chunks of the digest are discarded at the end.
*/

static uint64_t	g_sha384_h_init[8] = {
	0xcbbb9d5dc1059ed8, 0x629a292a367cd507, 0x9159015a3070dd17,
	0x152fecd8f70e5939, 0x67332667ffc00b31, 0x8eb44a8768581511,
	0xdb0c2e0d64f98fa7, 0x47b5481dbefa4fa4
};

void		*ft_sha384(t_env env)
{
	uint64_t	*state;
	uint64_t	*words;
	int			endflag;

	endflag = 0;
	state = ft_memdup((void*)g_sha384_h_init, DIGEST_SIZE / 8);
	words = ft_memalloc(sizeof(uint64_t) * WORD_COUNT);
	while (endflag < 2)
	{
		padded_block((uint8_t*)words, env, &endflag,
						(t_blockpad){BLOCK_SIZE, big_endian, 128});
		words = sha512_words(words);
		sha512_compression(state, words);
	}
	free(words);
	endianflip_field_64bit(state, BLOCK_SIZE);
	return (state);
}
