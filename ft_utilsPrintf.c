#include "libprintf.h"

int ft_putchar_printf(char c)
{
    write(1, &c, 1);
    return 1;
}

int ft_putstr_printf(char *s)
{
    int i;

    i = 0;
    if (s == NULL)
    {
        write(1, "(null)", 6);
        return 6;
    }
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    return (i);
}

int ft_putnbr_printf(int n)
{
    int i;
    char *s;

    i = 0;
    if (n == 0)
    {
        return (write(1, "0", 1));
    }
    s = ft_itoa(n); // faire le itoa
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    free(s);
    return (i);
}

int ft_putnbru_printf(unsigned int n)
{
    unsigned int i;
    char *s;

    i = 0;
    if (n == 0)
    {
        return (write(1, "0", 1));
    }
    s = ft_uitoa(n); // faire le itoa
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    free(s);
    return (i);
}