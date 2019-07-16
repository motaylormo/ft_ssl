/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:13:16 by mtaylor           #+#    #+#             */
/*   Updated: 2019/07/05 15:13:17 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_STRUCTS_H
# define TABLE_STRUCTS_H

typedef struct	s_hash_cmd
{
	char		*str;
	void*		(*func)(t_env);
	int			chuck;
	int			bits;
}				t_hash_cmd;

typedef struct	s_des_cmd
{
	char		*str;
	uint64_t	(*func)(t_env*, uint64_t, uint64_t*);
}				t_des_cmd;

typedef struct	s_func_flags
{
	void		(*func)(t_env*, int, char*);
	char		*flags;
}				t_func_flags;
#endif