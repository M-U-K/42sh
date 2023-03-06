/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_getnbr.c
*/

long take_nbr(char const *str, int ctr, int sign)
{
    long nbr = 0;

    for (; ('0' <= str[ctr] && str[ctr] <= '9') &&
    str[ctr] != '\0'; ctr++) {
        nbr = (nbr * 10) + (str[ctr] - 48);
        if ((nbr > 2147483648 && sign == -1)\
|| (nbr > 2147483647 && sign == 1))
            return (0);
    }
    return (nbr);
}

int get_number(char const *str)
{
    long nbr = 0;
    int ctr = 0;
    int sign = 1;

    for (; str[ctr] != '\0'; ctr++) {
        if (('0' > str[ctr] || str[ctr] > '9')\
&& str[ctr] != '-' && str[ctr] != '+')
            return (0);
        else if (str[ctr] == '-')
            sign *= -1;
        else {
            nbr = take_nbr(str, ctr, sign);
            break;
        }
    }
    ctr = (int)nbr * sign;
    if (ctr == (nbr * sign) && nbr != 0)
        return (ctr);
    return (0);
}