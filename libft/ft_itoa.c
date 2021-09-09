/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 14:16:00 by dkramer       #+#    #+#                 */
/*   Updated: 2020/11/25 09:59:52 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strrev(char *s1, int n, int d)
{
	int		end;
	char	temp;
	int		start;
	int		tempend;

	start = 0;
	if (n < 0)
		start = 1;
	end = d - 1 + start;
	tempend = end;
	while (end >= start)
	{
		temp = s1[start];
		s1[start] = s1[end];
		s1[end] = temp;
		start++;
		end--;
	}
	s1[tempend + 1] = '\0';
	return (s1);
}

static int		ft_nrofdigits(int n)
{
	int d;

	d = 0;
	while (n != 0)
	{
		n = n / 10;
		d++;
	}
	return (d);
}

static int		ft_getc(int n)
{
	int		c;

	c = 0;
	if (n < 0)
		c = 1;
	return (c);
}

static char		*ft_makestring(char *backwards, int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		backwards[i] = '-';
		n = n * -1;
		i++;
	}
	while (n != 0)
	{
		backwards[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	return (backwards);
}

char			*ft_itoa(int n)
{
	char	*backwards;
	int		tempn;
	int		d;

	tempn = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	d = ft_nrofdigits(n);
	backwards = malloc(d + ft_getc(n) + 1);
	if (backwards == NULL)
		return (NULL);
	backwards = ft_makestring(backwards, n);
	return (ft_strrev(backwards, tempn, d));
}
