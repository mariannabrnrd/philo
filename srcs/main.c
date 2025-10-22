
#include "philo.h"

/* ./philo  n_philo  time_to_die  time_to_eat  time_to_sleep  n_pasti */
int main(int ac, char **av)
{
    t_data      data;

    if (check_args(ac, av) == 1)
        return(1);
    init_data(&data, ac, av);
    print_data(&data);
    print_philos(&data);
    return(0);
}


/*creare i thread*/

/*...e poi bella domanda*/