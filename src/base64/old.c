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

#include "../ss/ft_ssl.h"

#define PADDING 64

static const char	g_base64[64] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
	'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
	'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

static void	encode_3bytes(char *src, char *dst)
{
	int	src_len;

	src_len = ft_strlen(src);
	dst[0] = ((src_len > 0) ? (src[0] & 0xFC) >> 2 : 0);
	dst[1] = ((src_len > 0) ? (src[0] & 0x03) << 4 : 0)
			| ((src_len > 1) ? (src[1] & 0xF0) >> 4 : 0);
	dst[2] = ((src_len > 1) ? (src[1] & 0x0F) << 2 : 0)
			| ((src_len > 2) ? (src[2] & 0xC0) >> 6 : 0);
	dst[3] = ((src_len > 2) ? (src[2] & 0x3F) : 0);
	dst[0] = g_base64[(int)dst[0]];
	dst[1] = g_base64[(int)dst[1]];
	dst[2] = (src_len > 1) ? g_base64[(int)dst[2]] : '=';
	dst[3] = (src_len > 2) ? g_base64[(int)dst[3]] : '=';
}

char		*ft_base64_encode(char *plaintext)
{
	char	*encoded;
	int		src_len;
	int		i;

	src_len = ft_strlen(plaintext);
	encoded = ft_strnew(((src_len / 3) * 4)
					+ ((src_len % 3 != 0) ? 4 : 0));
	i = 0;
	while (i * 3 < src_len)
	{
		encode_3bytes(plaintext + (i * 3), encoded + (i * 4));
		i++;
	}
	return (encoded);
}

static char	table_to_index(char symbol)
{
	int		i;

	if (symbol == '=')
		return (PADDING);
	i = 0;
	while (i < 64)
	{
		if (symbol == g_base64[i])
			return (i);
		i++;
	}
	return (symbol);
}

static void	decode_3bytes(char *src, char *dst)
{
	src[0] = table_to_index(src[0]);
	src[1] = table_to_index(src[1]);
	src[2] = table_to_index(src[2]);
	src[3] = table_to_index(src[3]);
	dst[0] = (src[0] << 2) | ((src[1] & 0x30) >> 4);
	if (src[2] != PADDING)
		dst[1] = ((src[1] & 0x0F) << 4) | ((src[2] & 0x3C) >> 2);
	if (src[3] != PADDING && (src[2] != PADDING))
		dst[2] = ((src[2] & 0x03) << 6) | (src[3] & 0x3F);
}

char		*ft_base64_decode(char *encoded)
{
	char	*plaintext;
	int		src_len;
	int		i;

	src_len = ft_strlen(encoded);
	plaintext = ft_strnew((src_len / 4) * 3
					- ((encoded[src_len - 1] == '=') ? 1 : 0)
					- ((encoded[src_len - 2] == '=') ? 1 : 0));
	i = 0;
	while (i * 4 < src_len)
	{
		decode_3bytes(encoded + (i * 4), plaintext + (i * 3));
		i++;
	}
	return (plaintext);
}
