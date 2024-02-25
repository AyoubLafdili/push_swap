/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:28:43 by alafdili          #+#    #+#             */
/*   Updated: 2024/02/25 23:50:56 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void which_sort(t_stack **stack_a, t_stack **stack_b)
{
    int size;

    if (!stack_a)
        return ;
    if (_is_sorted(*stack_a) == 1)
    {
        ft_lstclear(stack_a);
        return ;
    }
    size = list_size(*stack_a);
    if (size == 2)
        ft_sa(stack_a);
    else if (size == 3)
        srt_three(stack_a); 
    else
        srt_rest(stack_a, stack_b);
}

void check_arg(char *arg)
{
    int i;
    i = 0;
    if (arg[0] == '\0')
        _free(&arg, '0');
    else
    {
        while (arg[i] == 32 && arg[i])
            i++;
        if (arg[i] == '\0')
            _free(&arg, '0');
    }
}
int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;
    char *new_args;
   
    
    stack_a = NULL;
    stack_b = NULL;
    new_args = NULL;
    argc = 1;
    while (argv[argc])
    {
        check_arg(argv[argc]);
        new_args = ft_strjoin(new_args, argv[argc]);
        new_args = ft_strjoin(new_args, "  ");
        argc++;
    }
    parsing(new_args);
    max_min(new_args, &stack_a);    
    check_duplicat(&stack_a);
    which_sort(&stack_a, &stack_b);
    ft_lstclear(&stack_a);
    
    return (0);
}

