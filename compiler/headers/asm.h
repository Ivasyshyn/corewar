/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:29:16 by ollevche          #+#    #+#             */
/*   Updated: 2018/08/02 13:29:17 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libftprintf.h"
# include "op.h"
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>

typedef unsigned char	t_uchar;

typedef struct			s_item
{
	int				type;
	char			*line;
	t_uchar			*bytecode;
	struct s_item	*next;
}						t_item;

/*
**	compile.c
*/

bool					compile(char *filename);

/*
**	struct_funcs.c
*/

t_item					*new_item(char *line);
t_item					*add_item(t_item **head, char *line);
void					free_items(t_item **head);

#endif
