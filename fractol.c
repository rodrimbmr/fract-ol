/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:40:09 by rmonfort          #+#    #+#             */
/*   Updated: 2025/04/01 13:44:50 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 2 && ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		fractal.julia_x = atodbl(argv[2]);
		fractal.julia_y = atodbl(argv[3]);
		ft_fractal_init(&fractal);
		//ft_fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
