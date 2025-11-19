#include "philo.h"

int     one_philo(t_data *data)
{
    t_philo  *philo;

    philo = &data->philo[0];
    if (data->num_philo == 1)
    {
        ft_usleep(data->time_die);
        pthread_mutex_unlock(&data->forks[philo->fork_left]);
        ft_print_action(philo, "died");
        pthread_mutex_lock(&data->death_check);
        data->death_flag = 1;
        pthread_mutex_unlock(&data->death_check);
        return (0);
    }
    return (1);
}

void    *ft_routine(void *philosopher)
{
    t_philo *philo;

    philo = (t_philo *)philosopher;
    if (philo->id % 2 == 0)
        usleep(100);
    while (1)
    {
        pthread_mutex_lock(&philo->data->death_check);
        if (philo->data->death_flag == 1)
        {
            pthread_mutex_unlock(&philo->data->death_check);
            break ;
        }
        pthread_mutex_unlock(&philo->data->death_check);
        ft_eat(philo);
        pthread_mutex_lock(&philo->data->death_check);
        if (philo->data->death_flag == 1)
        {
            pthread_mutex_unlock(&philo->data->death_check);
            break ;
        }
        pthread_mutex_unlock(&philo->data->death_check);
        ft_sleep(philo);
        ft_think(philo);
    }
    return (NULL);
}

int     create_threads(t_data *data)
{
    int     i;

    i = 0;
    while (i < data->num_philo)
    {
        if (pthread_create(&data->philo[i].thread, NULL, ft_routine, &data->philo[i]) != 0)
        return (ft_error_msg("thread don't create\n"));
        i++;
    }
    if (create_monitor(data) != 0)
        return (ft_error_msg("monitor thread don't create\n"));
    i = 0;
    while (i < data->num_philo)
    {
        if (pthread_join(data->philo[i].thread, NULL) != 0)
            return(ft_error_msg("thread don't join\n"));
        i++;
    }
    return(0);
}
