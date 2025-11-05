#include "philo.h"

void    ft_eat(t_philo *philo)
{
    t_data *data;

    data = philo->data;
    pthread_mutex_lock(&data->forks[philo->left_fork]);
    ft_print_action(philo, "has taken a fork");
    pthread_mutex_lock(&data->forks[philo->right_fork]);
    ft_print_action(philo, "has taken a fork");
    pthread_mutex_lock(&data->meal_check);
    philo->last_meal = get_time();
    pthread_mutex_unlock(&data->meal_check);
    ft_print_action(philo, "is eating");
    ft_usleep(data->time_to_eat);
    philo->meals_eaten++;
    pthread_mutex_unlock(&data->forks[philo->left_fork]);
    pthread_mutex_unlock(&data->forks[philo->right_fork]);
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
        if (philo->data->death_flag)
            break ;
        ft_sleep(philo);
        if (philo->data->death_flag)
            break ;
        ft_think(philo);
    }
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
        if (phtread_join(data->philo[i].thread, NULL) != 0)
        {
            ft_error_msg("in joining thread");
            return(0);
        }
        i++;
    }
    return(0);
}
