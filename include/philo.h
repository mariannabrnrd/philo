#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>


/* **************************************************************************** */
/*                                  COLORS                                      */
/* **************************************************************************** */

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define RESET   "\033[0m"

/* **************************************************************************** */
/*                                  STRUCT                                      */
/* **************************************************************************** */

typedef struct s_data   t_data;

typedef struct  s_philo
{
    int         id;                 //-------> numero del philo
    int         is_eating;          //-------> variabile che serve per vedere se ha mangiato
    int         last_meal;          //-------> ultimo pasto
    int         meals_counter;      //-------> numero dei pasti
    int         fork_left;          //-------> forchetta di sinistra
    int         fork_right;         //-------> forchetta di destra
    pthread_t   thread;             //-------> thread del philos
    t_data      *data;              //-------> puntatore alla struttura principale
}               t_philo;

typedef struct  s_data
{
    int         num_philo;          //-------> numero dei filosofi
    long        time_die;           //-------> time to die
    long        time_eat;           //-------> time to eat
    long        time_sleep;         //-------> time to sleep
    long        num_meals;          //-------> numero dei pasti
    long        start_time;         //-------> tempo con cui inizia l'esecuzione
    int         is_die;             //-------> se qualcuno e morto
    pthread_mutex_t     print;      //-------> mutex per printare
    pthread_mutex_t		*forks;     //-------> mutex delle forchette
    t_philo             *philo;     //-------> struttura dei philos
}               t_data;

/* ************************************************** */
/*                 CHEK_INPUT                         */
/* ************************************************** */

char    *get_arg(int index);
int     check_input(int ac, char **av);
int		check_args(int ac, char **av);

/* ************************************************** */
/*                  INIT                              */
/* ************************************************** */

void    init_data(t_data *data, int ac, char **av);
void    init_philo(t_data *data);


/* ************************************************** */
/*                  ERROR                            */
/* ************************************************** */

int     ft_msg_err(char *msg);
int     ft_error_msg(char *msg);

/* ************************************************** */
/*                  UTILS                             */
/* ************************************************** */

int	    ft_atol(char *str);
int     ft_strlen(char *msg);
int     ft_isdigit(char *str);

/* ************************************************** */
/*                  PROVE                             */
/* ************************************************** */

void    print_data(t_data *data);
void	print_philos(t_data *data);

#endif