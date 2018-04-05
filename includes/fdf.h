/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:16:02 by thchin            #+#    #+#             */
/*   Updated: 2017/02/28 07:41:49 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# define WIDTH 1600
# define HEIGHT 900

typedef struct	s_matrix
{
	float		m[16];
}				t_matrix;

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_vertex
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vertex;

typedef struct	s_draw
{
	int			xa;
	int			ya;
	int			xb;
	int			yb;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
	float		w;
}				t_draw;

typedef struct	s_pers
{
	float		fovy;
	float		aspect;
	float		znear;
	float		zfar;
}				t_pers;

typedef struct	s_frustum
{
	float		left;
	float		right;
	float		top;
	float		bottom;
	float		near;
	float		far;
}				t_frustum;

typedef struct	s_view
{
	int			top;
	int			bottom;
	int			left;
	int			right;
}				t_view;

typedef struct	s_lookat
{
	t_vector	eye;
	t_vector	center;
	t_vector	up;
}				t_lookat;

typedef struct	s_edge
{
	int			ymin;
	int			ymax;
	float		xmin;
	float		xi;
	float		zmin;
	float		zi;
	float		hmin;
	float		hi;
	int			hline;
}				t_edge;

typedef struct	s_env
{
	t_list		*list;
	t_list		*edge_table;
	t_list		*active_edge;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	float		translatex;
	float		translatey;
	float		translatez;
	float		rotatex;
	float		rotatey;
	float		rotatez;
	int			x;
	int			y;
	t_vertex	**grid;
	float		z_min;
	float		z_max;
	float		**z_buffer;
	t_edge		*edge[4];
	float		sc_ymin;
	float		sc_ymax;
	void		*mlx;
	void		*win;
	t_draw		draw;
	t_lookat	lookat;
	t_view		view;
	t_pers		pers;
	t_frustum	frustum;
	t_matrix	*matrix;
	int			type;
	float		scalez;
	int			color;
}				t_env;

t_vector		min_vector(t_vector v1, t_vector v2);
t_vector		div_vector(t_vector v, float div);
t_vector		mult_vector(t_vector v, float multi);
t_vector		scal_vector(t_vector v1, t_vector v2);
float			norm_vector(t_vector v);

void			gl_translatef(t_env *env, float x, float y, float z);
void			gl_rotatexf(t_env *env, float angle);
void			gl_rotateyf(t_env *env, float angle);
void			gl_rotatezf(t_env *env, float angle);
void			gl_scalef(t_env *env, float x, float y, float z);

t_matrix		gl_loadidentity(void);
t_matrix		gl_loadempty(void);
void			copy_matrix(t_matrix *a, t_matrix b);
void			mult_matrix(t_env *env, t_matrix a);
t_vertex		matrix_mul_vec(t_matrix *m, t_vertex v);

void			set_glulookat(t_env *env, t_lookat *lookat);
void			glulookat(t_env *env, t_lookat *lookat);
void			set_gluperspective(t_pers *pers);
void			gluperspective(t_env *env, t_pers *pers);
void			set_glfrustum(t_frustum *frustum);
void			glfrustum(t_env *env, t_frustum *frustum);
t_draw			set_draw(t_vertex v1, t_vertex v2);
void			draw(t_vertex v1, t_vertex v2, t_env *env);
void			set_viewport(t_view *view);
int				in_gridviewport(int x, int y, t_env *env);
int				in_viewport(int x, int y, t_env *env);

void			img_put_pixel(t_env *env, int x, int y, int color);
void			fill_img(t_env *env, int color);
void			draw_img(t_env *env);
int				print_img(t_env *env);

int				create_grid(t_env *env);
void			update_grid(t_env *env);
void			matrix_grid(t_env *env);
void			ortho_grid(t_env *env);

t_env			*init_env(void);
void			clear_env(t_env *env);
int				get_map(t_env *env, int fd);

int				key_hook(int keycode, t_env *env);

void			print_matrix(t_matrix *m);
void			print_vertex(t_vertex vertex);
void			print_list(t_env *env);
void			print_grid(t_env *env);
void			print_edge(t_edge *e);
void			print_edge_table(t_list *list);

void			scanline(int x, int y, t_env *env);
void			init_z_buffer(t_env *env);
void			init_edge(int i, t_vertex v1, t_vertex v2, t_env *env);
void			sort_edge(t_edge *edge[4]);
void			swap_edge(t_edge *e1, t_edge *e2);
void			remove_edge(t_list *active, int y);
void			add_edge(t_list *table, t_list *active, int y);
t_list			*sort_active(t_list *list);
void			init_edge_table(t_edge *edge[4], t_list *list);

int				set_color(t_env *env, int flag);

#endif
