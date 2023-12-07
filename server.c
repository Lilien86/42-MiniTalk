/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:00:31 by lauger            #+#    #+#             */
/*   Updated: 2023/12/07 12:53:33 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

volatile int signal_received = 0;

void serveur_pid()
{
    int i;
    unsigned int pid;
    unsigned char *str_pid;

    pid = getpid();
    i = 0;
    str_pid = (unsigned char *)ft_itoa((int)pid);

    while (str_pid[i])
    {
        write(1, &str_pid[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

void sigusr1_handler()
{
    signal_received = 1;
}

int main(void)
{
    serveur_pid();
    signal(SIGUSR1, sigusr1_handler);

    while (1)
    {
        if (signal_received)
        {
            write(1, "05", 2);
            signal_received = 0;
        }
    }

    return 0;
}

