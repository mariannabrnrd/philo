#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct  s_philo
{
    int         id;         /*-------> numero del philo */
    t_data      *data;
}               t_philo;

typedef struct  s_data
{
    int         n_philo;    /*-------> numero dei filosofi */
    int         t_die;      /*-------> time to die */
    int         t_eat;      /*-------> time to eat */
    int         t_sleep;    /*-------> time to sleep */
    int         n_eat;      /*-------> numero dei pasti */
}               t_data;

#endif