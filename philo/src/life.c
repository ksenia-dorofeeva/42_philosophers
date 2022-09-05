/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:59:46 by brickard          #+#    #+#             */
/*   Updated: 2022/09/05 09:25:16 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    philo_print(t_philo *philo, char *str)
{
    if (philo->flag_of_death)
        return ;
    pthread_mutex_lock(philo->print_mutex);
    printf("%lld %d %s\n", get_time() - philo->start_time, philo->id, str);
    pthread_mutex_unlock(philo->print_mutex);
}

int philo_eat(t_philo *philo)
{
    if (philo->flag_of_death)
        return (1);
    pthread_mutex_lock(philo->left_fork);
    philo_print(philo, "has taken a fork");
    pthread_mutex_lock(philo->right_fork);
    philo_print(philo, "has taken a fork");
    philo_print(philo, "is eating");
    philo->lunches_ate++;
    philo->last_lunch = get_time();
    ft_usleep(philo->time_to_eat);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    return (0);
}

void    philo_sleep(t_philo *philo)
{
    if (philo->flag_of_death)
        return ;
    philo_print(philo, "is sleeping");
    ft_usleep(philo->time_to_sleep);
}

void    philo_think(t_philo *philo)
{
     if (philo->flag_of_death)
        return ;
    philo_print(philo, "is thinking");
}

void    *lifetime(void *thread)
{
    t_philo *philo;
    
    philo = (t_philo *)thread;
    if (philo->id % 2 == 0)
    {
        philo_print(philo, "is thinking");
        usleep(50);
    }
    while (!philo->flag_of_death)
    {
        if (philo_eat(philo))
            return (NULL);
        philo_sleep(philo);
        philo_think(philo);
    }
    return (NULL);
}

void    *death_is_near(void *data)
{
    t_data  *tmp;
    t_philo *ph;
    int     i;
    
    tmp = data;
    ph = tmp->philo;
    while (1)
    {
        i = -1;
        while (++i < tmp->num_of_philo)
        {
            if (tmp->num_lunches)
                if (ph->lunches_ate == tmp->num_lunches)
                    return (NULL);
            if (get_time() - ph[i].last_lunch > ph[i].time_to_die)
            {
                ph->flag_of_death = 1;
                pthread_mutex_lock(&tmp->print_mutex);
                printf("%lld %d died\n", get_time() - ph->start_time, ph->id);
                return (NULL);
            }
        }
    }
    return (NULL);
}

int manage_threads(t_data *data)
{
    int         i;
    pthread_t   check;

    i = -1;
    while (++i < data->num_of_philo)
        pthread_create(&data->thread[i], NULL, &lifetime, &data->philo[i]);
    pthread_create(&check, NULL, &death_is_near, data);
    pthread_mutex_unlock(&data->print_mutex);
    pthread_join(check, NULL);
    i = -1;
    while (++i < data->num_of_philo)
        pthread_join(data->thread[i], NULL);
    return (0);
}
