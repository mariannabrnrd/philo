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
    while (philo->data->death_flag == 0)
    {
        ft_eat(philo);
        if (philo->data->death_flag == 1)
            break ;
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
        {
            ft_error_msg("thread don't create\n");
            return(0);
        }
        i++;
    }
    i = 0;
    while (i < data->num_philo)
    {
        if (pthread_join(data->philo[i].thread, NULL) != 0)
        {
            ft_error_msg("in joining thread");
            return(0);
        }
        i++;
    }
    return(0);
}
