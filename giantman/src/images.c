/*
** EPITECH PROJECT, 2021
** .c for images
** File description:
** images
*/

#include "giant.h"
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

char *decomp_image(char *msg)
{
    int i = 0;
    int x = 0;
    int w = 0;
    int n = 0;
    int y = 0;
    char *str = my_malloc(10);
    char *s_num = my_malloc(4);
    char *temp = my_malloc(4);

    while (msg[i] != '\0') {
        temp = reset_str(temp);
        str = reset_str(str);
        s_num = reset_str(s_num);
        temp = count_line(msg, i, temp);
        y = my_strlen(temp);
        i = i + y + 1;
        x = 0;
        w = 0;
        n = 0;
        if (temp[0] == '(') {
            x = 1;
            while (temp[x] != ')') {
                str[x - 1] = temp[x];
                x++;
            }
            x++;
            while (temp[x] != '\0') {
                s_num[w] = temp[x];
                x++;
                w++;
            }
            n = my_getnbr(str);
            while (n > 0) {
                my_putstr(s_num);
                my_putstr("\n");
                n--;
            }
        } else {
            my_putstr(temp);
            my_putstr("\n");
        }
    }
    return (msg);
}