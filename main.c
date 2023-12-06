
#include "minitalk.h"

int ft_putnbr_unsigned_len(unsigned int n) {
    unsigned int num = n;
    unsigned int div = 1;
    int digit_count = 0;

    while (num / div >= 10) {
        div *= 10;
    }

    while (div > 0) {
        char digit = '0' + num / div;
        write(1, &digit, 1);
        num %= div;
        div /= 10;
        digit_count++;
    }
    write(1, "\n", 1);
    return (digit_count);
}


int     main(void)
{
   unsigned int pid = getpid();
   int       size_pid;
   char      *str_pid;

    size_pid = ft_putnbr_unsigned_len(pid);
    ft_putnbr_unsigned_len(size_pid);
    str_pid = malloc (sizeof(char) * (size_pid + 1));
    str_pid = ft_itoa(pid);
    write(1, &str_pid, (size_pid + 1));

    return (0);

}
