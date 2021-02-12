/*
** EPITECH PROJECT, 2021
** .c for images
** File description:
** images
*/

#include "ant.h"
#include "libmy.h"

char *count_line(char *msg, int i, char *temp)
{
    int w = 0;

    while (msg[i + w] != '\n' && msg[i + w] != '\0') {
        temp[w] = msg[i + w];
        w++;
    }
    return (temp);
}

char *reset_str(char *str)
{
    int x = 0;

    while (str[x] != '\0') {
        str[x] = '\0';
        x++;
    }
    return (str);
}

char *comp_image(char *msg)
{
    int i = 0;
    int w = 0;
    int x = 0;
    int max = 0;
    char *str = my_malloc(4);
    char *temp = my_malloc(4);

    while (msg[i] != '\0') {
        temp = reset_str(temp);
        temp = count_line(msg, i, temp);
        w = my_strlen(temp);
        i = i + w + 1;
        x = 0;

        if (w > 3 || my_str_isnum(temp) == 0) {
            if (str[0] != '\0') {
                if (max != 0) {
                    my_putchar('(');
                    my_put_nbr(max + 1);
                    my_putchar(')');
                }
                my_putstr(str);
                my_putstr("\n");
                str = reset_str(str);
            }
            my_putstr(temp);
            my_putstr("\n");
        } else if (my_strcmp(temp, str) == 0) {
            max++;
        } else {
            if (str[0] != '\0') {
                if (max != 0) {
                    my_putchar('(');
                    my_put_nbr(max + 1);
                    my_putchar(')');
                }
                my_putstr(str);
                my_putstr("\n");
            }
            max = 0;
            str = reset_str(str);
            while (temp[x] != '\0') {
                str[x] = temp[x];
                x++;
            }
        }
    }
    if (str[0] != '\0') {
        if (max != 0) {
            my_putchar('(');
            my_put_nbr(max + 1);
            my_putchar(')');
        }
        my_putstr(str);
        my_putstr("\n");
    }
    return (msg);
}