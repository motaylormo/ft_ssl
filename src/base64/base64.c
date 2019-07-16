/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:25:40 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/31 14:25:41 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

#define PADDING 64

static const char	g_b64[64] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
	'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
	'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

/*
**	|  input byte1  |  input byte2  |  input byte3  |
**	|---------------|---------------|---------------|
**	 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1
**	|-----------|-----------|-----------|-----------|
**	| b64 chr 1 | b64 chr 2 | b64 chr 3 | b64 chr 4 |
*/

static char	table_to_index(char symbol)
{
	if (symbol == '=')
		return (PADDING);
	for (int i = 0; i < 64; ++i)
	{
		if (symbol == g_b64[i])
			return (i);
	}
	return (symbol);
}

void	base64_encode_3bytes(char *dst, uint8_t *src, int bytes)
{
	uint32_t	input;

	ft_bzero(dst, 4);
	input = 0;
	for (int i = 0; i < 3; ++i)
	{
		input <<= 8;
		input += src[i];
	}
	for (int i = 3; i >= 0; --i)
	{
		if (bytes >= i)
			dst[i] = g_b64[input & 0x3F];
		else
			dst[i] = '=';
		input >>= 6;
	}
}

void	base64_decode_3bytes(char *dst, uint8_t *src)
{
	uint32_t	input;

	ft_bzero(dst, 3);
	input = 0;
	for (int i = 0; i < 4; ++i)
	{
		input <<= 6;
		input |= table_to_index(src[i]);
	}
	for (int i = 3; i >= 0; --i)
	{
		if ((input & 0xFF) == PADDING)
			dst[i] = '\0';
		else
			dst[i] = input & 0xFF;
		input >>= 8;
	}
}