/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_05_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:49:48 by dpozinen          #+#    #+#             */
/*   Updated: 2018/08/09 14:49:48 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_funcs.h"

bool	sub(t_session *game, t_carry *carry, t_champ *head)
{
	int 	args[2][3 + 1];
	int		lpc;

	(void)head;
	lpc = PC;
	ft_bzero((int**)args, 8 * sizeof(int));
	args[0][3] = -1;
	set_arg_values((int**)args, &lpc, game, false);
	if (!IS_REG(VAL1) || !IS_REG(VAL2) || !IS_REG(VAL3))
	{
		update_position(game, carry, lpc + 1);
		return (false);
	}
	REGS[VAL3 - 1] = REGS[VAL1 - 1] - REGS[VAL2 - 1];
	CARRY = (REGS[VAL3 - 1] == 0 ? true : false);
	update_position(game, carry, lpc + 1);
	return (true);
}
