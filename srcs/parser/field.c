/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   field.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/23 15:04:43 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/24 16:30:01 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_extract_precision_number(t_env *e, char *s, int start)
{
	int j;

	j = start;
	e->precision = 0;
	while (s[j] == '.' || ft_isdigit(s[j]))
	{
		if (ft_isdigit(s[j]))
			e->precision = e->precision * 10 + (s[j] - '0');
		j++;
	}
}

void		pf_extract_precision(t_env *e, int start, int end, char *string)
{
	int j;

	j = start - 1;
	while (++j < end && (string[j] != '.'))
		;
	while (j < end && string[j])
	{
		if (string[j] == '.')
			pf_extract_precision_number(e, string, j);
		j++;
	}
}

void		pf_extract_width(t_env *e, int start, int end, char *string)
{
	int j;

	j = start - 1;
	while (++j < end && (!ft_isdigit(string[j]) || string[j] == '0'))
		;
	while (j < end && string[j])
	{
		if (ft_isdigit(string[j]))
		{
			if (e->width == -1)
				e->width = 0;
			e->width = e->width * 10 + (string[j] - '0');
		}
		if (!ft_isdigit(string[j + 1]))
			break ;
		j++;
	}
}
