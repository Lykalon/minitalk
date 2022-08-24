/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:39:54 by lykalon           #+#    #+#             */
/*   Updated: 2022/03/07 14:39:56 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\v') || (c == '\f')
		|| (c == '\r'))
		return (1);
	else
		return (0);
}

static void	ft_isnegative(const char *str, int *i, int *sign)
{
	if (str[*i] == '-')
	{
		*sign = -1;
		*i = *i + 1;
	}
	else if (str[*i] == '+')
		*i = *i + 1;
	while (str[*i] == '0')
		*i = *i + 1;
}

int	mt_atoi(const char *str)
{
	long long	result;
	int			i;
	int			sgn;
	int			ch;

	i = 0;
	sgn = 1;
	result = 0;
	ch = 0;
	while (ft_isspace(str[i]))
		i++;
	ft_isnegative(str, &i, &sgn);
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		result = result * 10 + str[i] - 48;
		i++;
		ch++;
	}
	result *= sgn;
	if (((ch > 18) && (sgn == 1) && (result < 0)) || ((ch > 19) && (sgn == 1)))
		result = -1;
	else if (((ch > 18) && (sgn == -1) && (result > 0)) || ((ch > 19)
			&& (sgn == -1)))
		result = 0;
	return ((int)result);
}
