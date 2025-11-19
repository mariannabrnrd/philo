#include "philo.h"

/* Controlla se un filosofo è morto */
int check_death(t_philo *philo)
{
    long current_time;
    long time_since_meal;

    pthread_mutex_lock(&philo->meal_check);
    current_time = get_time();
    time_since_meal = current_time - philo->last_meal;
    pthread_mutex_unlock(&philo->meal_check);
    
    /* Se non sta mangiando e il tempo dall'ultimo pasto supera time_to_die */
    //if (philo->is_eating == 0 && time_since_meal >= philo->data->time_die)
    if (time_since_meal > philo->data->time_die)
    {
        ft_print_action(philo, "died");
        pthread_mutex_lock(&philo->data->death_check);
        philo->data->death_flag = 1;
        pthread_mutex_unlock(&philo->data->death_check);
        return (1);
    }
    return (0);
}

int check_meals_completed(t_data *data)
{
    int i;
    int all_done;

    /* Se non c'è limite di pasti, ritorna 0 */
    if (data->num_meals == -1)
        return (0);
    
    all_done = 1;
    i = 0;
    while (i < data->num_philo)
    {
        pthread_mutex_lock(&data->philo[i].meal_check);
        if (data->philo[i].meals_counter < data->num_meals)
            all_done = 0;
        pthread_mutex_unlock(&data->philo[i].meal_check);
        i++;
    }
    
    if (all_done == 1)
    {
        pthread_mutex_lock(&data->death_check);
        data->death_flag = 1;
        pthread_mutex_unlock(&data->death_check);
        return (1);
    }
    return (0);
}

void *monitor_routine(void *arg)
{
    t_data *data;
    int i;

    data = (t_data *)arg;
    
    /* Piccolo ritardo iniziale per permettere ai filosofi di iniziare */
    usleep(10);
    while (1)
    {
        /* Controlla se qualche filosofo è morto */
        i = 0;
        while (i < data->num_philo)
        {
            if (check_death(&data->philo[i]) == 1)
                return (NULL);
            i++;
        }
        
        /* Controlla se tutti hanno completato i pasti */
        if (check_meals_completed(data) == 1)
            return (NULL);
        
        /* Piccolo sleep per non sovraccaricare la CPU */
        usleep(500);
    }
    return (NULL);
}

int     create_monitor(t_data *data)
{
    pthread_t   monitor;

    if (pthread_create(&monitor, NULL, monitor_routine, data) != 0)
        return (ft_error_msg("monitor thread don't create\n"));
    if (pthread_detach(monitor) != 0)
        return (ft_error_msg("monitor thread don't detach\n"));
    return (0);
}