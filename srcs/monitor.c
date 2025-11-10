#include "philo.h"

/*  creato nella funzione create_threads con i philo
    in caso contrario, se volessi crearlo in routine
    gli passo i philo e non data (cosa importante perchè cambia
    la logica anche in philo_died)*/

void  *ft_monitoring(void *arg)
{
    t_data *data;
    int     death;
    //t_philo *philo;

    data = (t_data *)arg;
    death = 0;
    //philo = (t_philo *)arg;
    while (!death)
    {
        pthread_mutex_lock(&data->death_check);
        if (data->death_flag == 1)
        {
            pthread_mutex_unlock(&data->death_check);
            break ;
        }
        pthread_mutex_unlock(&data->death_check);
        /*if (philo_died(philo) == 1)
            break ;*/
        death = philo_died(data);
        usleep(1000);
    }
    return (NULL);
}

/*int    philo_died(t_philo *philo)
{
    long    current_time;
    int     eating;

    pthread_mutex_lock(&philo->meal_check);
    eating = philo->is_eating;
    current_time = get_time() - philo->last_meal;
    if (current_time > philo->data->time_die && eating == 0)
    {
        ft_print_action(philo, "died");
        pthread_mutex_lock(&philo->data->death_check);
        philo->data->death_flag = 1;
        pthread_mutex_unlock(&philo->data->death_check);
        pthread_mutex_unlock(&philo->meal_check);
        return (1);
    }
    pthread_mutex_unlock(&philo->meal_check);
    check_meals(philo->data);
    return (0);
}*/

int     philo_died(t_data *data)
{
    long    current_time;
    int     eating;
    int     i;

    i = 0;
    while (i < data->num_philo)
    {
        pthread_mutex_lock(&data->philo[i].meal_check);
        eating = data->philo[i].is_eating;
        current_time = get_time() - data->philo[i].last_meal;
        if (current_time > data->time_die && eating == 0)
        {
            ft_print_action(&data->philo[i], "died");
            pthread_mutex_lock(&data->death_check);
            data->death_flag = 1;
            pthread_mutex_unlock(&data->death_check);
            pthread_mutex_unlock(&data->philo[i].meal_check);
            return (1);
        }
        pthread_mutex_unlock(&data->philo[i].meal_check);
        i++;
    }
    check_meals(data);
    return (0);
}

int     check_meals(t_data *data)
{
    int     i;
    int     all_ate;

    all_ate = 1;
    i = 0;
    if (data->num_meals == -1)
        return (0);
    while (i < data->num_philo)
    {
        pthread_mutex_lock(&data->philo[i].meal_check);
        if (data->philo[i].meals_counter < data->num_meals)
            all_ate = 0;
        pthread_mutex_unlock(&data->philo[i].meal_check);
        i++;
    }
    if (all_ate == 1)
    {
        ft_print_action(NULL, "All philosophers have eaten the required number of meals.");
        pthread_mutex_lock(&data->death_check);
        data->death_flag = 1;
        pthread_mutex_unlock(&data->death_check);
        return (1);
    }
    return (0);
}
