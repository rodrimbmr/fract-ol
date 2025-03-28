/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:43:46 by rmonfort          #+#    #+#             */
/*   Updated: 2025/03/27 18:30:40 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FRACTOL_H
# define	FRACTOL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "librarys/minilibx-linux/mlx.h"
# include "librarys/42_Libft/libft.h"

#define ERROR_MESSAGE "error, please enter the values <mandelbrot> or <julia> - <value1> & <value2> \n"

#define WIDTH	800
#define HEIGHT	800

// colors
#define COLOR_BLACK   0x000000
#define COLOR_WHITE   0xFFFFFF
#define COLOR_RED     0xFF0000
#define COLOR_GREEN   0x00FF00
#define COLOR_BLUE    0x0000FF
#define COLOR_YELLOW  0xFFFF00
#define COLOR_CYAN    0x00FFFF
#define COLOR_MAGENTA 0xFF00FF
#define COLOR_GRAY    0x808080
#define COLOR_ORANGE  0xFFA500
#define COLOR_PURPLE  0x800080
#define COLOR_BROWN   0xA52A2A
#define COLOR_PINK    0xFFC0CB

//complex number
typedef	struct s_complex
{
	//real
	double	x;
	//imagin
	double	y;
}			t_complex;


typedef	struct s_image
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef	struct  s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
}				t_fractal;

//init
void	ft_fractal_init(t_fractal *fractal);
void	data_init(t_fractal *fractal);

//render
static void	handle_pixel(int x, int y, t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
static void	my_pixel_put(int x, int y, t_img *img, int color);

//math
double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif
