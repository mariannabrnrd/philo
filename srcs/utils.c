#include "philo.h"

// capire quale ft_uspleep usare

/*long  ft_usleep(long time_in_ms)
{
	long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
	{
		if (time_in_ms > 10)
			usleep((time_in_ms / 10) * 1000);
		else
			usleep(100); // per tempi piccoli, serve più precisione
	}
	return (0);
}*/

long    ft_usleep(long time_in_ms)
{
    long    start_time;
    long    remaining;

    start_time = get_time();
    while ((get_time() - start_time) < time_in_ms)
    {
        remaining = time_in_ms - (get_time() - start_time);
        if (remaining > 1000)  // Se manca più di 1 secondo
            usleep(remaining * 1000 / 2);  // Dormi metà del tempo rimanente
        else if (remaining > 10)
            usleep(remaining * 100);  // Per tempi medi
        else
            usleep(100);  // Per precisione finale
    }
    return (0);
}

void 	free_data(t_data *data)
{
	int 	i;

	i = 0;
	if (data->forks)
	{
		while (i < data->num_philo)
			pthread_mutex_destroy(&data->forks[i++]);
		free(data->forks);
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death_check);
	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->philo[i].meal_check);
		i++;
	}
	if (data->philo)
		free(data->philo);
}

/* funzione che prende il tempo */
long 	get_time(void)
{
	struct timeval 	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday error\n", 20);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
