#include "philo.h"

void    ft_print_action(t_philo *philo, char *action)
{
    t_data  *data;
    long    timestamp;

    data = philo->data;
    pthread_mutex_lock(&data->print);
    timestamp = get_time() - data->start_time;
    if (data->death_flag == 0)
        printf("%ld %d %s\n", timestamp, philo->id, action);
    pthread_mutex_unlock(&data->print);
}

void   ft_think(t_philo *philo)
{
    ft_print_action(philo, "is thinking");
}

void   ft_sleep(t_philo *philo)
{
    t_data  *data;

    data = philo->data;
    ft_print_action(philo, "is sleeping");
    ft_usleep(data->time_sleep);
}

void    ft_eat(t_philo *philo)
{
    t_data *data;

    data = philo->data;
    pthread_mutex_lock(&data->forks[philo->fork_left]);
    ft_print_action(philo, "has taken a fork");
    if (one_philo(data) == 0)
        return;
    pthread_mutex_lock(&data->forks[philo->fork_right]);
    ft_print_action(philo, "has taken a fork");
    pthread_mutex_lock(&philo->meal_check);
    philo->is_eating = 1;
    philo->last_meal = get_time();
    pthread_mutex_unlock(&philo->meal_check);
    ft_print_action(philo, "is eating");
    ft_usleep(data->time_eat);
    pthread_mutex_lock(&philo->meal_check);
    philo->is_eating = 0;
    philo->meals_counter++;
    pthread_mutex_unlock(&philo->meal_check);
    pthread_mutex_unlock(&data->forks[philo->fork_left]);
    pthread_mutex_unlock(&data->forks[philo->fork_right]);
}
