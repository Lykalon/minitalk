/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:40:20 by lykalon           #+#    #+#             */
/*   Updated: 2022/03/07 14:40:22 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	mt_putchar(char c)
{
	write(1, &c, 1);
}

void	mt_putstr(char *str, int flag)
{
	while (*str)
	{
		write(1, str, 1);
		++str;
	}
	if (flag)
		mt_putchar('\n');
}

void	print_str(char **str, int *index)
{
	mt_putstr(*str, 1);
	free(*str);
	*str = NULL;
	*index = 0;
}
