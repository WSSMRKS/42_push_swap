/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:49:01 by maweiss           #+#    #+#             */
/*   Updated: 2024/02/28 15:01:22 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_free_int(void *data)
{
	int	*nbr;

	nbr = data;
	free(nbr);
	data = NULL;
}

// [ ] Work on list functions.

void	ft_lstfree(t_list **lst)
{
	void *del;
	t_list *tmp_l;

	del = &ft_lstfree;
	tmp_l = lst;
	while (tmp_l->next != NULL)
	{

		ft_lstdelone(lst, del);

}

int	ft_sorted(t_list *lst_a)
{
	int		value;
	int		sorted;
	t_list	*tmp_l;

	tmp_l = lst_a;
	value = INT_MIN;
	sorted = 1;
	while (tmp_l->next != NULL && sorted == 1)
	{
		if (value <= tmp_l->content)
		{
			sorted = 1;
			value = tmp_l->content;
			tmp_l = tmp_l->next;
		}
		else
			sorted = 0;
	}
	return (sorted);
}

void	ft_fill_lst(int *stack_a, int size)
{
	t_list	*lst_a;
	int		i;

	i = 0;
	lst_a = ft_lstnew(stack_a[i++]);
	while (stack_a[i])
		ft_lstadd_back(&lst_a, ft_lstnew(stack_a[i++]));
	if (ft_sorted(lst_a))
	{

		exit(3);
	}
}

void	ft_switch(int *stack_a, int size, char purpose)
{
	if (purpose == 's')
		ft_solve(stack_a, size);
	else if (purpose == 'c')
		ft_check(stack_a, size);
}

static void	ft_free(char **tofree)
{
	int	i;

	if (!tofree)
		return ;
	i = 0;
	while (tofree[i])
	{
		free((void *)tofree[i]);
		i++;
	}
	free((void *)tofree);
	return ;
}

int	ft_validate_args(char *str, int *valid)
{
	int		i;
	long	nbr;

	nbr = 0;
	i = 0;
	*valid = 1;
	if (!str)
		return (NULL);
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			break ;
	}
	nbr = ft_atol(str);
	if (str[i] == '\0' && i <= 11 && nbr >= -2147483648
		&& nbr <= 2147483647)
		return ((int) nbr);
	else
		*valid = 0;
	return (0);
}

char	*ft_parse_several(int argc, char **argv)
{
	int			i;
	int			*stack_a;
	int			valid;

	stack_a = (int *) malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i <= (argc - 1))
	{
		stack_a[i++] = ft_atol(ft_validate_args(argv[i + 1], &valid)); // [ ] check if syntax is right (++)
		if (valid != 1)
		{
			free(stack_a);
			return (NULL);
		}
	}
	return (stack_a);
}

char	*ft_parse_one(char *input, int *size)
{
	char	**split;
	int		*stack_a;
	int		i;
	int		valid;

	i = ft_countwords(input, ' ');
	stack_a = (int *) malloc(sizeof(int) * i);
	split = ft_split(*input, ' ');
	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		stack_a[i] = ft_atol(ft_validate_args(split[i], &valid));
		if (valid != 1)
		{
			ft_free(split);
			free(stack_a);
			return (NULL);
		}
		free(split[i++]);
	}
	free(split);
	*size = i; // [ ] validate right size from i
	return (stack_a);
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		size;
	char	purpose;
	int		success;

	purpose = 's'; // [ ] s = solve; c = check;
	if (argc < 2)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	else if (argc == 2)
		stack_a = ft_parse_one(argv[1], &size);
	else
	{
		stack_a = ft_parse_several(argc, **argv);
		size = argc - 1;
	}
	if (!stack_a)
	{
		write(2, "ERROR\n", 6);
		exit(2);
	}
	ft_switch(stack_a, size, purpose);
	return (1);
}
