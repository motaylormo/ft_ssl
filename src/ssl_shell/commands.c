/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:21:13 by mtaylor           #+#    #+#             */
/*   Updated: 2019/07/10 12:21:15 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_shell.h"
#include "table_structs.h"

static void (*g_hash_flag_sets[])(t_env*, int, char*) =
{
	parse_file_flags,
	parse_hash_flags,
	(NULL)
};

static const t_hash_cmd	g_hashs[] = {
	{   "md5",    ft_md5, 32, 128},
	{  "sha1",   ft_sha1, 32, 160},
	{"sha256", ft_sha256, 32, 256},
	{"sha224", ft_sha224, 32, 224},
	{"sha512", ft_sha512, 64, 512},
	{"sha384", ft_sha384, 64, 384},
	{(NULL), (NULL), 0, 0}
};

int		run_hash(int ac, char **av)
{
	t_env	env;
	void	*hash;
	
	for (int i = 0; g_hashs[i].str; ++i)
	{
		if (ft_strequ(av[0], g_hashs[i].str))
		{
			env = parse_flags(ac, av, g_hash_flag_sets);
			hash = g_hashs[i].func(env);
			if (env.flags & flag_b64)
				print_base64(env.output_fd, hash, g_hashs[i].bits / 8);
			else
				print_hex(env.output_fd, hash, g_hashs[i].bits / 8);
			ft_memdel(&hash);
			free_env(env);
			return (1);
		}
	}
	return (0);
}

static void (*g_des_flag_sets[])(t_env*, int, char*) =
{
	parse_file_flags,
	parse_mode_flags,
	parse_des_flags,
	(NULL)
};

static const t_des_cmd	g_des[] = {
	{    "des", ft_des_cbc},
	{"des-cbc", ft_des_cbc},
	{"des-ecb", ft_des_ecb},
	{(NULL), (NULL)}
};

int		run_des(int ac, char **av)
{
	t_env	env;

	for (int i = 0; g_des[i].str; ++i)
	{
		if (ft_strequ(av[0], g_des[i].str))
		{
			env = parse_flags(ac, av, g_des_flag_sets);
			if (env.mode == 0)
				ft_des_encode(&env, g_des[i].func);
			else
				ft_des_decode(&env, g_des[i].func);
			free_env(env);
			return (1);
		}
	}
	return (0);
}

static void (*g_base64_flag_sets[])(t_env*, int, char*) =
{
	parse_file_flags,
	parse_mode_flags,
	parse_hash_flags,
	(NULL)
};

#define BUFSIZE 15

int		run_base64(int ac, char **av)
{
	t_env	env;
	uint8_t	buf[BUFSIZE];

	if (ft_strequ(av[0], "base64"))
	{
		env = parse_flags(ac, av, g_base64_flag_sets);
		if (env.mode == 0)
			while (write_to_base64(env.output_fd, buf, read(env.input_fd, buf, BUFSIZE)));
		if (env.mode == 1)
			while (write(env.output_fd, buf, read_from_base64(env.input_fd, buf, BUFSIZE)));
		free_env(env);
		return (1);
	}
	return (0);
}
