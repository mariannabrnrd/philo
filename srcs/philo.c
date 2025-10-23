#include "philo.h"

void    *ft_routine(void *philosopher)
{
    t_philo *philo;

    philo = (t_philo *)philosopher;
    while (philo->data->is_die == 0)
    {

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
