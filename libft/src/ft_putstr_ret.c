/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hastid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:34:13 by hastid            #+#    #+#             */
/*   Updated: 2019/04/08 17:38:52 by hastid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_ret(const char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			write(1, &str[i++], 1);
	return (i);
}