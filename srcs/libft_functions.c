#include "philo.h"

/* funzione per il malloc, se non va a buon fine, stampa errore */
void 	*ft_malloc(size_t size)
{
	void 	*res;

	res = malloc(size);
	if (!res)
	{
		ft_err_malloc("error malloc");
		return (NULL);
	}
	return (res);
}

/*  controlla la stringa se contiene caratteri diversi da numeri
	e trova un carattere ritorna 0, cosi nella funzione dopo entra
	nell'if ed esce con errore.
	se arriva alla fine riporta 1, e significa che l'input e giusto */
int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/* funzione di atoi.. sempre perche non possiam usare libft... /ᐠ ╥ ˕ ╥マ*/
long	    ft_atol(char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if (num > INT_MAX)
			return (-1);
		str++;
	}
	return (num * sign);
}

/* non possiamo usare libft... ≽^╥ ˕ ╥^≼ */
int     ft_strlen(char *msg)
{
    int     i;

    i = 0;
    while (msg[i])
        i++;
    return(i);
}
