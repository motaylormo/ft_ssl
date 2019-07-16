/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_shell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:12:00 by mtaylor           #+#    #+#             */
/*   Updated: 2019/07/10 12:12:03 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_SHELL_H
# define SSL_SHELL_H

# include "ft_ssl.h"

int		run_hash(int ac, char **av);
int		run_des(int ac, char **av);
int		run_base64(int ac, char **av);

t_env	parse_flags(int ac, char **av, void (*f[])(t_env*, int, char*));
void	parse_file_flags(t_env *env, int flag, char *arg);
void	parse_mode_flags(t_env *env, int flag, char *arg);
void	parse_des_flags(t_env *env, int flag, char *arg);
void	parse_hash_flags(t_env *env, int flag, char *arg);

void	print_hex(int fd, void *ptr, int bytes);
void	print_base64(int fd, void *ptr, int bytes);


#endif