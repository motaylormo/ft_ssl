/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:09:39 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/05 12:09:41 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_shell.h"
#include "table_structs.h"

/*
**	-i, input file [default: stdin]
**	-o, output file [default: stdout]
*/
void	parse_file_flags(t_env *env, int flag, char *arg)
{
	if (flag == 'i')
	{
		if ((env->input_fd = open(arg, O_RDONLY)) < 1)
			handle_error(error_file, arg);
	}
	if (flag == 'o')
	{
		if ((env->output_fd = open(arg, O_WRONLY)) < 1)
			handle_error(error_file, arg);
	}
}

/*
**	-d, decode mode [default: encrypt]
**	-e, encode mode [default: encrypt]
*/
void	parse_mode_flags(t_env *env, int flag, char *arg)
{
	(void)arg;
	if (flag == 'd')
		env->mode = 1;
	if (flag =='e')
		env->mode = 0;
}

static uint64_t	hex_arg(char *arg, int this_flag, int *flags)
{
	uint64_t	n;
	int			len;

	n = ft_atolbase(arg, 16);
	len = ft_strlen(arg);
	if (len < 16)
		n <<= (16 - len) * 4;
	*flags |= this_flag;
	return (n);
}

/*
**	-p, password in ascii
**	-s, salt in hex
**	-k, key in hex
**	-v, initialization vector in hex
*/
void	parse_des_flags(t_env *env, int flag, char *arg)
{
	if (flag == 's')
		env->salt = hex_arg(arg, flag_salt, &env->flags);
	if (flag == 'k')
		env->key = hex_arg(arg, flag_key, &env->flags);
	if (flag == 'v')
		env->iv = hex_arg(arg, flag_iv, &env->flags);
	if (flag == 'p')
	{
		env->password = ft_strdup(arg);
		env->flags |= flag_pass;
	}
}

/*
**	-s, input is the given string [default: stdin]
*/
void	parse_hash_flags(t_env *env, int flag, char *arg)
{
	if (flag == 's')
	{
		env->input_ptr = ft_strdup(arg);
		env->input_ptr_bytes = ft_strlen(arg);
	}
}

static const t_func_flags	g_flag_sets[] = {
	{parse_file_flags, "i:o:"},
	{parse_mode_flags, "de"},
	{parse_des_flags, "s:k:v:p:"},
	{parse_hash_flags, "s:"},
	{(NULL), (NULL)}
};


t_env	parse_flags(int ac, char **av, void (*f[])(t_env*, int, char*))
{
	char	flag_str[20];
	int		opt;
	t_env	env;

	ft_bzero(flag_str, sizeof(flag_str));
	flag_str[0] = 'a';
	for (int i = 0; (*f[i]) != NULL; ++i)
	{
		for (int j = 0; g_flag_sets[j].func != NULL; ++j)
		{
			if ((*f[i]) == g_flag_sets[j].func)
				ft_strcat(flag_str, g_flag_sets[j].flags);
		}
	}
	env = fresh_env();
	while ((opt = ft_getopt(ac, av, flag_str)) != -1)
	{
		if (opt == '?')
			handle_error(error_flag, av[optind]);
		if (optarg && optarg[0] == '-' && ft_strlen(optarg) == 2)
			handle_error(error_incomplete,
					"an argument for a flag that requires one");
		for (int i = 0; (*f[i]) != NULL; ++i)
			(*f[i])(&env, opt, optarg);
		if (opt == 'a')// -a, decode/encode the input/output in base64, depending on the encrypt mode
		{
			env.flags |= flag_b64;
		}
	}
	return (env);
}