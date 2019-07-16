/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:16:35 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/07 12:22:04 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

/*
**	<fcntl.h>	for open
**	<unistd.h>	for close, read, & write
**	<stdlib.h>	for malloc, free, & exit
**	<errno.h>	for strerror()
*/
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct	s_env
{
	int			mode;
	int			flags;
	int			input_fd;
	char		*input_ptr;
	int			input_ptr_bytes;
	int			output_fd;
	char		*password;
	uint64_t	salt;
	uint64_t	key;
	uint64_t	iv;
}				t_env;

enum	e_flags{
	flag_pass = 1,
	flag_salt = 1 << 1,
	flag_key = 1 << 2,
	flag_iv = 1 << 3,
	flag_b64 =  1 << 4
};

enum	e_error_codes{
	error_command,
	error_flag,
	error_file,
	error_incomplete
};

# define USAGE "usage: ft_ssl command [command opts] [command av]"

/*
**	ssl shell
*/
void		handle_error(int errorcode, char *str);
t_env		fresh_env(void);
void		free_env(t_env env);

//	endian.c
uint32_t	endianflip_32bit(uint32_t val);
uint64_t	endianflip_64bit(uint64_t val);
void		endianflip_field_32bit(uint32_t *field, int size);
void		endianflip_field_64bit(uint64_t *field, int size);


/*
**	hashing/
*/
void	*ft_md5(t_env env);
void	*ft_sha1(t_env env);
void	*ft_sha256(t_env env);
void	*ft_sha224(t_env env);
void	*ft_sha512(t_env env);
void	*ft_sha384(t_env env);

/*
**	des/
*/
t_env		ft_pbkdf(t_env env);
uint64_t	ft_des_ecb(t_env *env, uint64_t block, uint64_t *subkey);
uint64_t	ft_des_cbc(t_env *env, uint64_t block, uint64_t *subkey);
void		ft_des(t_env env, uint64_t (*f)(t_env*, uint64_t, uint64_t*));

/*
**	base64/
*/
//void		ft_base64(t_env env);
void	base64_encode_3bytes(char *dst, uint8_t *src, int src_len);
void	base64_decode_3bytes(char *dst, uint8_t *src);

#endif
