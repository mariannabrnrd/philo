#include "philo.h"

void  *ft_monitoring(void *arg)
{
    t_data *data;

    data = (t_data *)arg;
    while (1)
    {
        pthread_mutex_lock(&data->death_check);
        if (data->death_flag == 1)
        {
            pthread_mutex_unlock(&data->death_check);
            break ;
        }
        pthread_mutex_unlock(&data->death_check);
        if (philo_died(data) == 1)
            break ;
        if (ate_all_meals(data) == 1)
            break ;
    }
}