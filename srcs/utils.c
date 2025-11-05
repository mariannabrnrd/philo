#include "philo.h"

size_t  ft_usleep(long time_in_ms)
{
	size_t	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
	{
		if (time_in_ms > 10)
			usleep((time_in_ms / 10) * 1000);
		else
			usleep(100); // per tempi piccoli, serve più precisione
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
