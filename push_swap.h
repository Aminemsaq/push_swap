/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:16:46 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/16 23:27:47 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int				*numbers_int;
	char			*long_number;
	char			**long_split;
	int				size;
}					t_data;

typedef struct s_node
{
	int				value;
	int				index;
	int				index_sorted;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
long				ft_atoi(const char *str, t_data *data);
char				**ft_split(const char *s, char c);
char				*ft_strtrim(char const *s1);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					joining(int ac, char **av, t_data *data);
void				ft_putstr_fd(char *s, int fd);
int					ft_check_set(char const c);
int					help_join(char *number);
int					check_for_tab(char const *s1);
int					ft_isvalid(char c);
int					ft_parsing(t_data *data);
int					convert_to_int(t_data *data);
int					check_dupl(int *numbers_int, int size);
int					check_sorted(int *numbers_int, int size);
void				init_push_swap(t_data data);
t_stack				*init_stack(void);
void				push(t_stack *stack, int value);
int					pop(t_stack *stack);
void				free_stack(t_stack *stack);
void				free_data(t_data *data);
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				sort_two(t_stack *stack);
void				sort_three(t_stack *a);
void				index_stack(t_stack *stack);
void				sort_four_five(t_stack *stack_a, t_stack *stack_b);
void				index_stack_sorted(t_stack *stack);
void				sort_radix(t_stack *stack_a, t_stack *stack_b);
#endif