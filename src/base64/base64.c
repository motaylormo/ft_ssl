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

#include "base64.h"

#define PADDING 64
#define MASK_6 0x3F
#define MASK_8 0xFF

const char	g_b64[64] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
	'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
	'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

static int	table_to_index(char c)
{
	if (c == '=')
		return (PADDING);
	for (int i = 0; i < 64; ++i)
	{
		if (c == g_b64[i])
			return (i);
	}
	return (-1);
}

/*
**	|  input byte1  |  input byte2  |  input byte3  |
**	|---------------|---------------|---------------|
**	 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1
**	|-----------|-----------|-----------|-----------|
**	| b64 char1 | b64 char2 | b64 char3 | b64 char4 |
*/

void	base64_encode_3bytes(uint8_t dst[4], uint8_t src[3], int bytes)
{
	uint32_t	input;

	input = 0;
	for (int i = 0; i < 3; ++i)
	{
		input <<= 8;
		if (i < bytes)
			input += src[i];
	}
	for (int i = 3; i >= 0; --i)
	{
		if (bytes >= i)
			dst[i] = g_b64[input & MASK_6];
		else
			dst[i] = '=';
		input >>= 6;
	}
}

void	base64_decode_3bytes(uint8_t dst[3], uint8_t src[4])
{
	int			bytes;
	uint32_t	input;

	input = 0;
	bytes = 3;
	for (int i = 0; i < 4; ++i)
	{
		input <<= 6;
		if (table_to_index(src[i]) == PADDING)
			bytes--;
		else
			input += table_to_index(src[i]) & MASK_6;
	}
	for (int i = 2; i >= 0; --i)
	{
		dst[i] = input & MASK_8;
		input >>= 8;
	}
	while (bytes < 3)
		dst[bytes++] = '\0';
}
