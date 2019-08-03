/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:26:41 by mtaylor           #+#    #+#             */
/*   Updated: 2019/07/05 15:26:43 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_env	fresh_env(void)
{
	t_env	env;

	ft_bzero(&env, sizeof(env));
	env.input_fd = STDIN_FILENO;
	env.output_fd = STDOUT_FILENO;
	return (env);
}


static void	print_env(t_env env)
{
	ft_printf("\n");
	ft_printf("           mode = %d\n", env.mode);
	ft_printf("          flags = %.4b\n", env.flags);
	ft_printf("       input_fd = %d\n", env.input_fd);
	ft_printf("      input_ptr = %s\n", env.input_ptr);
	ft_printf("input_ptr_bytes = %d\n", env.input_ptr_bytes);
	ft_printf("      output_fd = %d\n", env.output_fd);
	ft_printf("       password = %s\n", env.password);
	ft_printf("           salt = %.16lx\n", env.salt);
	ft_printf("            key = %.16lx\n", env.key);
	ft_printf("             iv = %.16lx\n", env.iv);	
}

void	free_env(t_env env)
{
	print_env(env);
	if (env.input_ptr)
		free(env.input_ptr);
	if (env.password)
		free(env.password);
}