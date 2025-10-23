#include "philo.h"

int 	check_struct(t_data *data)
{
	int 	i;
	if (!data->forks)
		return(1);
	if (!data->philo)
		return(1);
	i = 0;
	while (i < data->num_philo)
	{
		if (!data->philo[i++].data)
			return(ft_error_msg("malloc failed for philosopher data pointer\n"));
	}
	return(0);
}

/* riporto quale argomento non va bene */
char    *get_arg(int index)
{
    if (index == 1)
        return("number_of_philosophers");
    else if (index == 2)
        return("time_to_die");
    else if (index == 3)
        return("time_to_eat");
    else if (index == 4)
        return("time_to_sleep");
    else if (index == 5)
        return("number_of_times_each_philosopher_must_eat");
    return("≽^• ˕ • ྀི≼\n");


}

/* ritorno 1, se l'input non va bene, ritorno 0 se si puo procedere*/
int	check_input(int ac, char **av)
{
	int		i;
	int		value;

	i = 1;
	while (i < ac)
	{
		if (ft_isdigit(av[i]) == 0)
			return (ft_error_msg(get_arg(i)));
		value = ft_atol(av[i]);
		if (value <= 0)
			return (ft_error_msg(get_arg(i)));
		i++;
	}
	return (0);
}

/* ritorno 1, se l'input non va bene, ritorno 0 se si puo procedere*/
int		check_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
        return (ft_error_msg("invalid number of arguments\n"));
    if (check_input(ac, av) == 1)
        return (ft_msg_err("invalid input\n"));
	else
		return (0);
}
