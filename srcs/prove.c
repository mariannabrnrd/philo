#include "philo.h"

void print_data(t_data *data)
{
    printf("\n" CYAN "══════════════════════════════════════════════════════\n" RESET);
    printf(CYAN "                 🧠 DATA STRUCT INFO 🧠\n" RESET);
    printf(CYAN "══════════════════════════════════════════════════════\n" RESET);

    printf(GREEN "Number of philosophers : " RESET "%d\n", data->num_philo);
    printf(GREEN "Time to die            : " RESET "%ld ms\n", data->time_die);
    printf(GREEN "Time to eat            : " RESET "%ld ms\n", data->time_eat);
    printf(GREEN "Time to sleep          : " RESET "%ld ms\n", data->time_sleep);

    if (data->num_meals != -1)
        printf(GREEN "Number of meals        : " RESET "%ld\n", data->num_meals);
    else
        printf(GREEN "Number of meals        : " RESET "∞ (no limit)\n");

    printf(GREEN "Start time             : " RESET "%ld ms\n", data->start_time);
    printf(GREEN "Death flag             : " RESET "%d\n", data->death_flag);

    printf(CYAN "══════════════════════════════════════════════════════\n\n" RESET);
}

// ───────────────────────────────────────────────────────────────
// STAMPA STRUTTURE PHILO
// ───────────────────────────────────────────────────────────────
void print_philos(t_data *data)
{
    int i = 0;

    printf(MAGENTA "══════════════════════════════════════════════════════\n" RESET);
    printf(MAGENTA "                 🍽️  PHILOS STRUCT INFO 🍽️\n" RESET);
    printf(MAGENTA "══════════════════════════════════════════════════════\n" RESET);

    while (i < data->num_philo)
    {
        t_philo *p = &data->philo[i];

        printf(YELLOW "Philosopher %d\n" RESET, p->id);
        printf("  %-22s %d\n", "Is eating:", p->is_eating);
        printf("  %-22s %d\n", "Meals counter:", p->meals_counter);
        printf("  %-22s %d\n", "Last meal time:", p->last_meal);
        printf("  %-22s %d\n", "Left fork index:", p->fork_left);
        printf("  %-22s %d\n", "Right fork index:", p->fork_right);
        printf("  %-22s %p\n", "Pointer to data:", (void *)p->data);

        printf(BLUE "------------------------------------------------------\n" RESET);
        i++;
    }

    printf(MAGENTA "══════════════════════════════════════════════════════\n\n" RESET);
}
