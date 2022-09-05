/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:34:45 by brickard          #+#    #+#             */
/*   Updated: 2022/09/02 11:32:17 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int argc, char **argv)
{
    t_data  *data;
    
    if (check_args(argc, argv))
        return (1);
    data = init_data(argc, argv);
    if (!data)
        return (ft_free(data));
    if (malloc_stuff(data))
        return (ft_free(data));
    if (init_philo(data))
        return (ft_free(data));
    manage_threads(data);
    ft_destroy_mutex(data);
    ft_free(data);
    return (0);
}
