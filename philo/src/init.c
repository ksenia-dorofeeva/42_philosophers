/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:13:13 by brickard          #+#    #+#             */
/*   Updated: 2022/09/05 08:34:30 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int malloc_stuff(t_data *data)
{
    data->philo = malloc(sizeof(t_philo) * data->num_of_philo);
    if (!data->philo)
        return (1);
    data->fork = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
    if (!data->fork)
        return (1);
    data->thread = malloc(sizeof(pthread_t) * data->num_of_philo);
    if (!data->thread)
        return (1);
    return (0);
}

int init_philo(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->num_of_philo)
        if (pthread_mutex_init(&data->fork[i], NULL))
            return (1);
    i = -1;
    while (++i < data->num_of_philo)
    {
        data->philo[i].id = i + 1;
        data->philo[i].time_to_die = data->time_to_die;
        data->philo[i].time_to_eat = data->time_to_eat;
        data->philo[i].time_to_sleep = data->time_to_sleep;
        data->philo[i].lunches_ate = 0;
        data->philo[i].left_fork = &(data->fork[i]);
        data->philo[i].print_mutex = &data->print_mutex;
        data->philo[i].flag_of_death = 0;
        pthread_mutex_init(&data->philo[i].eating_mutex, NULL);
        pthread_mutex_init(&data->philo[i].death_mutex, NULL);
        if (i < data->num_of_philo - 1)
            data->philo[i].right_fork = &(data->fork[i + 1]);
        else
            data->philo[i].right_fork = 0;
        data->philo[i].last_lunch = 0;
    }
    return (0);
}

t_data  *init_data(int ac, char **av)
{
    t_data  *data;
    
    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        return (NULL);
    pthread_mutex_init(&data->print_mutex, NULL);
    data->num_of_philo = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    data->num_lunches = 0;
    if (ac == 6)
        data->num_lunches = ft_atoi(av[5]);
    data->start_time = 0;
    data->thread = NULL;
    data->fork = NULL;
    data->philo = NULL;
    return (data);
}