/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:16:14 by brickard          #+#    #+#             */
/*   Updated: 2022/08/30 14:16:32 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int check_args(int ac, char **av)
{
    if (ac != 5 && ac != 6)
    {
        printf("Error: wrong number of arguments.\n");
        return (1);
    }
    if (ft_atoi(av[1]) < 0 || ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0 ||
        ft_atoi(av[4]) <= 0 || (ac == 6 && ft_atoi(av[5]) <= 0))
    {
        printf("Error: wrong arguments.\n");
        return (1);
    }
    return (0);
}