/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:38:54 by htorp             #+#    #+#             */
/*   Updated: 2019/06/11 15:35:18 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <math.h>
# include <fcntl.h>
# include <zconf.h>
# define R 0xFF0000
# define G 0xFF00
# define B 0xFF
# define COLOR_STEP_R(a,b,c,d) ((((a & R)>>16) - ((b & R)>>16)) / (c + 1 - d))
# define COLOR_STEP_G(a,b,c,d) (((a & G)>>8) - ((b & G)>>8)) / (c + 1 - d)
# define COLOR_STEP_B(a,b,c,d) ((a & B) - (b & B)) / (c + 1 - d)
# define ONE_R(a,b,c,d) ((a & R) + ((int)(((int)b + 1 - (int)(c)) * d) << 16))
# define ONE_G(a,b,c,d) ((a & G) + ((int)(((int)b + 1 - (int)(c)) * d) << 8))
# define ONE_B(a,b,c,d) ((a & B) + (int)(((int)b + 1 - (int)(c)) * d))

typedef struct		s_line
{
	double			xd0;
	double			yd0;
	double			zd0;
	double			xd1;
	double			yd1;
	double			zd1;
	int				color0;
	int				color1;
	struct s_line	*next;
}					t_line;

typedef struct		s_reader
{
	int				a;
	int				b;
	int				ret;
	char			*line;
	char			**split;
	int				**tab;
	int				**col;
}					t_reader;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct		s_angles
{
	float			ang_x;
	float			ang_y;
	float			ang_z;
}					t_angles;

typedef struct		s_fileview
{
	int				**data;
	int				x_size;
	int				y_size;
	int				**color;
	int				step;
	int				i;
	int				j;
	float			height;
	t_point			*p0;
	t_point			*p1;
}					t_fileview;

typedef struct		s_winsets
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_fileview		*fileview;
}					t_winsets;

typedef struct		s_map_borders
{
	int				bor_min_x;
	int				bor_min_y;
	int				bor_max_x;
	int				bor_max_y;
}					t_map_borders;

typedef struct		s_image
{
	void			*ptr_image;
	void			*mlx_ptr;
	void			*win_ptr;
	char			*data_image;
	t_line			*base_lines;
	t_line			*out_lines;
	int				x_zero;
	int				y_zero;
	t_angles		*angles;
	int				color;
	t_point			*center;
	double			mult;
	double			x_size;
	double			y_size;
	double			x_shift;
	double			y_shift;
	double			height;
	int				angle_flag;
	char			rot_x;
	char			rot_y;
	char			rot_z;
	int				flag;
	int				x_pos;
	int				y_pos;
	int				lines_step;
	int				bor_x_min;
	int				bor_x_max;
	int				bor_y_min;
	int				bor_y_max;
	int				top_color;
	int				base_color;
	int				col_map_x;
	int				col_map_y;
	int				cur_max_height;
	int				col_mode;
	int				glob_mode;
	int				help_mode;
	int				col_bot_flag;
	int				col_top_flag;
	int				ground_col;
	int				main_color;
	t_winsets		*winsets;
	int				res_interface;
	int				plus_to_minus;
	int				minus_to_plus;
	t_map_borders	*map_borders;
}					t_image;

typedef struct		s_draw
{
	int				i;
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	double			x;
	double			y;
	double			tmp;
	double			dx;
	double			dy;
	double			gradient;
	double			xend;
	double			yend;
	double			intery;
	double			in;
	int				sign;
	double			c_s_r;
	double			c_s_g;
	double			c_s_b;
	int				o_c;
	int				o_c_r;
	int				o_c_g;
	int				o_c_b;
	int				set_color;
	double			color_step_r;
	double			color_step_g;
	double			color_step_b;
	int				one_color;
	int				one_color_r;
	int				one_color_g;
	int				one_color_b;
}					t_draw;

typedef struct		s_borders
{
	int				x_lt;
	int				x_rb;
	int				y_rt;
	int				y_lb;
}					t_borders;

typedef struct		s_centres
{
	int				old_cen_x;
	int				old_cen_y;
	int				cur_cen_x;
	int				cur_cen_y;
}					t_centres;

void				draw_line(t_image *i, t_draw *draw, int color0, int color1);
int					rgb(int color0, int color1, double max_height, double c_h);
void				ft_put_pixel(t_draw *draw, t_image *image);
void				change_pixel(t_draw *draw, t_image *image);
char				*color(char *s);
int					ft_y(int fd);
int					get_color(char *str);
int					*get_line_color(char **color, int max_x);
int					calc_izom_x(int x, int y, int z, int x_zero);
int					calc_izom_y(int x, int y, int z, int y_zero);
void				assigm_x(t_line *l, t_line *o_l, float angle, t_point *cen);
void				assigm_y(t_line *l, t_line *o_l, float angle, t_point *cen);
void				assigm_z(t_line *l, t_line *o_l, float angle, t_point *cen);
t_line				*cr_line_st(t_point *p0, t_point *p1);
t_line				*calc_lines(t_fileview *f_view, double d_step, double d_h);
void				zoom(t_line *line, double d);
int					ft_y(int fd);
void				v(char	*tmp, int *i);
t_fileview			*reader(int fd, int y, t_fileview *fileview);
void				set_base_color(t_line *ls, t_fileview *f_view, t_image *im);
void				set_user_color(t_line *ls, t_fileview *f_view, t_image *im);
int					*get_line_color(char **color, int max_x);
int					get_color(char *str);
void				swap_double(double *a, double *b);
void				swap_int(int *color0, int *color1);
int					ipart(double x);
int					ft_round(double x);
double				fpart(double x);
void				clear_col_map(t_image *image);
void				color_map(int stat_color, t_image *image, int x, int y);
void				sh_top_color(t_image *image);
void				sh_base_color(t_image *image);
void				clear_col_boxes(t_image *image);
void				line_grad(t_image *image, int color);
void				clear_line_grad(t_image *image);
int					key_press(int keycode, void *param);
void				set_all(t_image *image, int clear_fl);
int					ft_close(void *param);
int					mouse_press(int button, int x, int y, void *param);
int					mouse_release(int button, int x, int y, void *param);
int					mouse_move(int x, int y, void *param);
void				first_sets(t_image *image);
double				max_height(t_fileview *fileview);
void				set_glob_pos(t_image *im, t_fileview *f_vw, t_winsets *win);
void				set_interfaces(t_image *image);
void				figure_res(t_image *image, t_map_borders *m_borders);
void				set_borders(t_image *image);
void				choose_col_base(t_image *image, int keycode);
void				color_mode_set(t_image *image);
void				glob_mode_set(t_image *image);
void				help_mode_set(t_image *image);
void				key_sets(t_image *im, int keycode, int st, t_angles *angl);
void				incr_height(t_image *image);
void				decr_height(t_image *image);
void				second_sets(t_image *i, t_winsets *w, double st, double ht);
void				glob_interface(t_image *image);
void				set_line(t_line *ls, int x_zero, int y_zero, t_image *im);
void				line_copy(t_line *src, t_line *dest);
void				help_interface(t_image *image);
void				color_interface(t_image *image);
void				user_instr(int flag, char *s);

#endif
