/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 12:48:22 by mtaylor           #+#    #+#             */
/*   Updated: 2019/07/21 12:48:23 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# include "ft_ssl.h"

# define BYTES_PER_LINE 48
# define BUFSIZE 100
# define SMALLER(a, b)	((a < b) ? a : b)

const char	g_b64[64];

void	base64_encode_3bytes(uint8_t dst[4], uint8_t src[3], int bytes);
void	base64_decode_3bytes(uint8_t dst[3], uint8_t src[4]);

#endif
