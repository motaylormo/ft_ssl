/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:23:54 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/07 17:26:47 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_shell.h"

int			main(int argc, char **argv)
{
	if (argc < 2)
		ft_printf(USAGE "\n");
	else
	{
		argc--;
		argv++;
		if (run_hash(argc, argv))
			return (0);
		else if (run_des(argc, argv))
			return (0);
		else if (run_base64(argc, argv))
			return (0);
		else
			handle_error(error_command, argv[0]);
	}
	return (0);
}
