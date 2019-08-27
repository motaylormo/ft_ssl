/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:39:52 by mtaylor           #+#    #+#             */
/*   Updated: 2019/08/16 11:39:54 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

/*
**	Read or write, depending on b64 mode
*/

int		read_block(t_env *env, void *block, int bytes)
{
	if (env->flags & flag_b64)
		return (read_from_base64(env->input_fd, block, bytes));
	else
		return (read(env->input_fd, block, bytes));
}

void	write_block(t_env *env, void *block, int bytes)
{
	if (env->flags & flag_b64)
		write_to_base64(env->output_fd, block, bytes);
	else
		write(env->output_fd, block, bytes);
}