/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:06:09 by brickard          #+#    #+#             */
/*   Updated: 2022/09/05 09:32:14 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>

typedef struct timeval	t_timeval;

typedef struct s_philo
{
    int             id;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             lunches_ate;
    pthread_mutex_t             *left_fork;
    pthread_mutex_t             *right_fork;
    long long       start_time;
    long long       last_lunch;
    int			    flag_of_death;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	eating_mutex;
	pthread_mutex_t	death_mutex;
    
}   t_philo;

typedef struct s_data
{
    int             num_of_philo;
    int             time_to_eat;
    int             time_to_sleep;
    int             time_to_die;
    int             num_lunches;
    long long            start_time;
    pthread_t		*thread;
    pthread_mutex_t	print_mutex;
    pthread_mutex_t	*fork;
	t_philo			*philo;
    
}   t_data;

int	ft_atoi(const char *str);
void    *lifetime(void *thread);
int manage_threads(t_data *data);
void	ft_usleep(long long time);
long long	get_time(void);
int	ft_free(t_data *data);
int check_args(int ac, char **av);
t_data  *init_data(int ac, char **av);
int init_philo(t_data *data);
int malloc_stuff(t_data *data);
void	ft_destroy_mutex(t_data *data);

#endif