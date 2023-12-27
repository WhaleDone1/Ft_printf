#include "libprintf.h"

static int ft_hexa_len(unsigned int n)
{
    int len;

    len = 0;
    while (n != 0)
    {
        len++;
        n = n / 16;
    }
    return (len);
}

static void ft_putprint_hex(unsigned int n, const char format)
{
    char tmp;

    if (n >= 16)
    {
        ft_putprint_hex(n / 16, format);
        ft_putprint_hex(n % 16, format);
    }
    else
    {
        if (n <= 9)
        {
            tmp = (n + '0');
            write(1, &tmp, 1);
        }
        else
        {
            if (format == 'x')
            {
                tmp = (n - 10 + 'a');
                write(1, &tmp, 1);
            }
            if (format == 'X')
            {
                tmp = (n - 10 + 'A');
                write(1, &tmp, 1);
            }
        }
    }
}

int ft_putnbrhexa_printf(unsigned int n, const char format)
{
    if (n == 0)
        return (write(1, "0", 1));
    else
        ft_putprint_hex(n, format);
    return (ft_hexa_len(n));
}