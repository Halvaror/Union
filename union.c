/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-b <alopez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:34:14 by alopez-b          #+#    #+#             */
/*   Updated: 2022/02/14 20:54:31 by alopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>

void checkstrings(const char *str1, const char *str2)
{
	int i;
    int j;
    int h;
    int check;

    i = 0;
    h = 0;
    while (str1[i] != '\0')
    {
        check = 0;
        j = 0;
        while (j < i)
        {
            if (str1[j] == str1[i])
            {
                check = 1;
				i++;
                break;
            }   
            j++;
        }
        h = 0;
        while (str2[h] && check != 1)
        {
            if (str1[i] == str2[h])
            {
                i++;
				break;
            }
			if (str1[i] != str2[h])
				write(1, &str1[i], 1);
            h++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1, "\n",1);
        return (0);
    }
    checkstrings(argv[1], argv[2]);
    write(1, "\n",1);
    return (0);
}