#include "philo.h"

void    init_philo(t_data *data)
{
    int     i;

    i = 0;
    data->philo = ft_malloc(sizeof(t_philo) * data->num_philo)
    while (i < data->num_philo)
    {
        data->philo[i].id = i + 1;
        data->philo[i].is_eating = 0;
        data->philo[i].last_meal = table->start_time;
        data->philo[i].fork_left = 
        data->philo[i].data = data;
        i++; 
    }
}

void    init_forks(t_data *data)
{
    int     i;

    i = 0;
    data->forks = ft_malloc(sizeof(pthread_mutex_t) * data->num_philo);
    while (i < data->num_philo)
        pthread_mutex_init(&data->forks[i], NULL);
}

void    init_data(t_data *data, int ac, char **av)
{
    data->num_philo = ft_atol(av[1]);
    data->time_die = ft_atol(av[2]);
    data->time_eat = ft_atol(av[3]);
    data->time_sleep = ft_atol(av[4]);
    if (ac == 6)
        data->num_meals = ft_atol(av[5]);
    else
        data->num_meals = -1;
    data->start_time = get_time();
    data->is_die = 0;
    pthread_mutex_init(&data->print, NULL);
    init_forks(data);
    init_philo(data);
}
