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

void	free_env(t_env env)
{
	if (env.input_ptr)
		free(env.input_ptr);
	if (env.password)
		free(env.password);
}