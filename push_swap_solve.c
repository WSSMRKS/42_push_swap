/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wssmrks <wssmrks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/18 19:38:00 by wssmrks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve(int **stack_a, int *size)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = ft_fill_lst(stack_a, size);
	lst_b = NULL;
	if (*size == 2)
		ft_sa(&lst_a, 0);
	else if (*size <= 3)
		ft_solve_3_l(&lst_a);
	// else if (*size <= 5)
	// 	ft_solve_5(&lst_a, &lst_b, size, ft_chunks(*size));
	// else if (*size <= 10)
	// 	ft_solve_10(&lst_a, &lst_b, size, ft_chunks(*size));
	else
		ft_solve_big(&lst_a, &lst_b, size, ft_chunks(*size));
	ft_lstfree(&lst_a);
	ft_lstfree(&lst_b);
	ft_free((void *)stack_a, 0);
}

void	ft_solve_3_l(t_list **lst_a)
{
	if ((*lst_a)->cont->value < (*lst_a)->next->cont->value
		&& (*lst_a)->next->cont->value > (*lst_a)->next->next->cont->value)
	{
		if ((*lst_a)->cont->value < (*lst_a)->next->next->cont->value)
		{
			ft_sa(lst_a, 0);
			ft_ra(lst_a, 0);
		}
		else
			ft_rra(lst_a, 0);
	}
	else if ((*lst_a)->cont->value > (*lst_a)->next ->cont->value
		&& (*lst_a)->next->cont->value < (*lst_a)->next->next->cont->value)
	{
		if ((*lst_a)->cont->value < (*lst_a)->next->next->cont->value)
			ft_sa(lst_a, 0);
		else
			ft_ra(lst_a, 0);
	}
	else
	{
		ft_sa(lst_a, 0);
		ft_rra(lst_a, 0);
	}
}

void	ft_solve_3_r(t_list **lst_b)
{
	if ((*lst_b)->cont->value > (*lst_b)->next->cont->value
		&& (*lst_b)->next->cont->value < (*lst_b)->next->next->cont->value)
	{
		if ((*lst_b)->cont->value < (*lst_b)->next->next->cont->value)
		{
			ft_sb(lst_b, 0);
			ft_rb(lst_b, 0);
		}
		else
			ft_rrb(lst_b, 0);
	}
	else if ((*lst_b)->cont->value < (*lst_b)->next ->cont->value
		&& (*lst_b)->next->cont->value > (*lst_b)->next->next->cont->value)
	{
		if ((*lst_b)->cont->value > (*lst_b)->next->next->cont->value)
			ft_sb(lst_b, 0);
		else
			ft_rb(lst_b, 0);
	}
	else
	{
		ft_sa(lst_b, 0);
		ft_rra(lst_b, 0);
	}
}

void	ft_solve_5(t_list **lst_a, t_list **lst_b, int *size, int chunks)
{
	int		chunk;
	int		size_a;
	int		size_b;
	int		dist;
	
	chunk = chunks - 1;
	size_a = *size;
	size_b = 0;
	ft_calc_index(lst_a, *size);
	while (size_a > 3)
	{
		dist = ft_find_chunk(lst_a, chunk, size_a);
		if (dist == -1000000)
			chunk--;
		while (dist != 0 && dist != -1000000)
		{
			if (dist < 0)
			{
				ft_rra(lst_a, 0);
				dist++;
			}
			else
			{
				ft_ra(lst_a, 0);
				dist--;
			}
		}
		if (dist == 0)
		{
			if (size_b == 3)
				ft_solve_3_r(lst_b);
			{
				ft_pb(lst_a, lst_b, 0);
				size_b++;
			}
			size_a--;
		}
	}
	ft_solve_3_l(lst_a);
	write(2, "Solving algorithm not in place yet!\n", 36);
	lst_a = NULL;
	lst_b = NULL;
	*size = 0;
	return ;
}

void	ft_solve_10(t_list **lst_a, t_list **lst_b, int *size, int chunks)
{
	int		chunk;
	int		size_a;
	int		size_b;
	int		dist;

	chunk = chunks - 1;
	size_a = *size;
	size_b = 0;
	ft_calc_index(lst_a, *size);
	while (size_a > 3)
	{
		dist = ft_find_chunk(lst_a, chunk, size_a);
		if (dist == -1000000)
			chunk--;
		while (dist != 0 && dist != -1000000)
		{
			if (dist < 0)
			{
				ft_rra(lst_a, 0);
				dist++;
			}
			else
			{
				ft_ra(lst_a, 0);
				dist--;
			}
		}
		if (dist == 0)
		{
			if (size_b == 3)
				ft_solve_3_r(lst_b);
			{
				ft_pb(lst_a, lst_b, 0);
				size_b++;
			}
			size_a--;
		}
	}
	ft_solve_3_l(lst_a);
	write(2, "Solving algorithm not in place yet!\n", 36);
	lst_a = NULL;
	lst_b = NULL;
	*size = 0;
	return ;
}

void	ft_solve_big(t_list **lst_a, t_list **lst_b, int *size, int chunks)
{
	int		chunk;
	int		size_a;
	int		size_b;
	int		dist;

	chunk = chunks - 1;
	size_a = *size;
	size_b = 0;
	ft_calc_index(lst_a, *size);
	while (size_a > 3)
	{
		dist = ft_find_chunk(lst_a, chunk, size_a);
		if (dist == -1000000)
			chunk--;
		while (dist != 0 && dist != -1000000)
		{
			if (dist < 0)
			{
				ft_rra(lst_a, 0);
				dist++;
			}
			else
			{
				ft_ra(lst_a, 0);
				dist--;
			}
		}
		if (dist == 0)
		{
			if (size_b == 3)
				ft_solve_3_r(lst_b);
			{
				ft_pb(lst_a, lst_b, 0);
				size_b++;
			}
			size_a--;
		}
	}
	ft_solve_3_l(lst_a);
	ft_push_val(lst_a, lst_b, size_b);
	write(2, "Solving algorithm not in place yet!\n", 36);
	lst_a = NULL;
	lst_b = NULL;
	*size = 0;
	return ;
}

void	ft_push_val(t_list **lst_1, t_list **lst_2, int size_2)
{
	int		dist;

	while (size_2 > 0)
	{
		dist = ft_find_index(lst_1, (*lst_2)->cont->index, ft_lstsize(*lst_1));
		while (dist != 0 && dist != -1000000)
		{
			if (dist < 0)
			{
				ft_rrb(lst_2, 0);
				dist++;
			}
			else
			{
				ft_rb(lst_2, 0);
				dist--;
			}
		}
		if (dist == 0)
		{
			ft_pa(lst_1, lst_2, 0);
			size_2--;
		}
	}
}
