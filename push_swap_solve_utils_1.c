/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_utils_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/27 17:54:00 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calc_index(t_list **lst_a, int size)
{
	int			min;
	long int	min_o;
	int			index;
	t_list		*tmp_a;

	index = 0;
	min_o = (long)-INT_MAX -2;
	while (index < size)
	{
		min = INT_MAX;
		tmp_a = *lst_a;
		while (tmp_a)
		{
			if (tmp_a->cont->value <= min && (long) tmp_a->cont->value > min_o)
				min = tmp_a->cont->value;
			tmp_a = tmp_a->next;
		}
		tmp_a = *lst_a;
		while (tmp_a)
		{
			if (tmp_a->cont->value == min)
				break ;
			tmp_a = tmp_a->next;
		}
		tmp_a->cont->index = index++;
		ft_assign_chunk(&tmp_a, size, ft_chunks(size));
		min_o = (long) min;
	}
}

void	ft_assign_chunk(t_list **lst_a, int size, int chunks)
{
	static float	chunk_size;
	int				i;

	i = 1;
	chunk_size = ((float)(size - 1) / chunks);
	if (chunk_size > (*lst_a)->cont->index)
		(*lst_a)->cont->chunk = 0;
	else if (chunk_size < (*lst_a)->cont->index)
	{
		while ((float)chunk_size * i < (*lst_a)->cont->index)
			i++;
		(*lst_a)->cont->chunk = i - 1;
	}
}

int	ft_chunks(int size)
{
	int	chunks;

	chunks = 1;
	if (size <= 15)
		return (chunks);
	else if (size > 15 && size <= 50)
		chunks = 3;
	else if (size > 50 && size < 80)
		chunks = 5;
	else if (size > 80 && size <= 200)
		chunks = 7;
	else if (size > 200 && size <= 450)
		chunks = 10;
	else if (size > 450 && size <= 950)
		chunks = 12;
	else if (size > 950 && size <= 2500)
		chunks = 17;
	else
	{
		while (size / chunks > 50)
			chunks++;
	}
	return (chunks);
}

void	ft_push_a(t_list **lst_1, t_list **lst_2, int size_2)
{
	int		dist;
	t_list	*tmp;

	while (size_2 > 0)
	{
		tmp = *lst_2;
		dist = ft_find_index(lst_1, tmp->cont->index);
		while (dist != 0 && dist != -1000000)
		{
			if (dist < 0)
			{
				ft_rra(lst_1, 0);
				dist++;
			}
			else
			{
				ft_ra(lst_1, 0);
				dist--;
			}
		}
		ft_pa(lst_1, lst_2, 0);
		size_2--;
	}
}
