#include "philo.h"

void    print_data(t_data *data)
{
    printf("\n");
	printf(CYAN "=== DATA STRUCT ===\n" RESET);
	printf("Number of philosophers : %d\n", data->n_philo);
	printf("Time to die            : %d\n", data->t_die);
	printf("Time to eat            : %d\n", data->t_eat);
	printf("Time to sleep          : %d\n", data->t_sleep);
	printf("Number of meals        : %d\n", data->n_eat);
	printf(CYAN "====================\n\n" RESET);
}

void	print_philos(t_data *data)
{
	int	i;

	printf(MAGENTA "=== PHILOS STRUCTS ===\n" RESET);
	i = 0;
	while (i < data->n_philo)
	{
		printf(YELLOW "Philo %d:\n" RESET, data->philo[i].id);
		printf("  Pointer to data: %p\n", (void *)data->philo[i].data);
		printf("  -> n_philo in data: %d\n", data->philo[i].data->n_philo);
		printf("-----------------------\n");
		i++;
	}
	printf(MAGENTA "=======================\n\n" RESET);
}
