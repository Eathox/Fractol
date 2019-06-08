/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_normalize.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:42:00 by pholster       #+#    #+#                */
/*   Updated: 2019/02/10 11:42:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

double	ft_normalize(long long value, long long *range, long long *outputrange)
{
	long long	rangemin;
	long long	rangemax;
	long long	outputrangemin;
	long long	outputrangemax;
	double		output;

	rangemin = range[0];
	rangemax = range[1];
	outputrangemin = outputrange[0];
	outputrangemax = outputrange[1];
	output = (double)(outputrangemax - outputrangemin) / (rangemax - rangemin);
	output *= outputrangemin + (value - rangemin);
	return (output);
}
