/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getfractols.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 00:07:34 by pholster       #+#    #+#                */
/*   Updated: 2019/05/03 00:07:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_ftl	*freeret(t_ftl **ftl, char ***ftls, void ***fncs, char *message)
{
	ft_memdel((void **)fncs);
	ft_strarrdel(ftls);
	if (*ftl == NULL)
		ft_puterror(message);
	return (*ftl);
}

static char		**prepare(char ***ftls, void ***fncs)
{
	int		size;

	size = 2;
	*ftls = ft_strarrnew(size);
	if (*ftls == NULL)
		return (NULL);
	if (ft_strarrcpy_var(*ftls, size, "Julia", "Mandelbrot") == NULL)
		return (NULL);
	ft_strarrtolower(*ftls);
	*fncs = (void **)ft_memalloc(sizeof(void *) * size);
	if (*fncs == NULL)
		return (NULL);
	(*fncs)[0] = NULL; //TODO ADD Julia FUNCTION HERE
	(*fncs)[1] = NULL; //TODO ADD Mandelbrot FUNCTION HERE
	//TODO ADD THHIRD SET
	return (*ftls);
}

t_ftl			*ft_getfractols(int ac, char **av, t_ftl **ftl)
{
	int		i;
	int		dex;
	char	*str;
	char	**ftls;
	void	**fncs;

	i = 0;
	str = NULL;
	ftls = NULL;
	fncs = NULL;
	if (prepare(&ftls, &fncs) == NULL)
		return (freeret(ftl, &ftls, &fncs, "Ft_getfractols: Malloc error\n"));
	while (i < ac)
	{
		if (ft_strequ(str, av[i]) == FALSE)
		{
			dex = ft_strindex((const char **)ftls, av[i]);
			if (dex != -1 && ft_addfractol(ftl, av[i], fncs[dex]) == NULL)
				return (freeret(ftl, &ftls, &fncs, ""));
		}
		str = av[i];
		i++;
	}
	return (freeret(ftl, &ftls, &fncs, MESSAGE_USAGE));
}
