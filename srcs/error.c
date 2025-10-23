#include "philo.h"

/* errore in caso di malloc */
void    ft_err_malloc(char *msg)
{
    write(2, RED "philo: ", 14);
    write(2, msg, ft_strlen(msg));
    write(2, RESET, 4);
}

/* stampa l'errore con questa dicitura 
    ": (stringa che passo)" ovviamente in rosso /ᐠ > ˕ <マ ) */
int     ft_msg_err(char *msg)
{
    write(2, RED ": ", 9);
    write(2, msg, ft_strlen(msg));
    write(2, RESET, 4);
    return(1);
}

/* stampa gli errori (con tonalita di rosso /ᐠ > ˕ <マ ) */
int     ft_error_msg(char *msg)
{
    write(2, RED "Error: ", 14);
    write(2, msg, ft_strlen(msg));
    write(2, RESET, 4);
    return(1);
}
