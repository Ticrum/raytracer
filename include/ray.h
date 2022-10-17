
typedef struct s_zpos
{
  double		x;
  double		y;
  double		z;
}t_zpos;

#include <lapin.h>

typedef struct s_cam
{
  double		x;
  double		y;
  double		z;
  int			dist;
}t_cam;

typedef struct s_vect
{
  double		x;
  double		y;
  double		z;
}t_vect;

typedef struct s_sphere
{
  t_zpos		pos;
  double       		radius;
  unsigned int		color;
}t_sphere;

typedef struct s_light
{
  t_zpos		pos;
  unsigned int		color;
}t_light;

typedef struct s_cylindre
{
  t_zpos		pos;
  double       		radius;
  unsigned int		color;
  char			axe;
}t_cylindre;

typedef struct s_plan
{
  double		pos;
  char			axe;
  unsigned int		color;
}t_plan;

typedef struct s_object
{
  t_sphere		**sphere;
  int			nbr_sphere;
  t_plan		**plan;
  int			nbr_plan;
  t_cylindre		**cylindre;
  int			nbr_cylindre;
  t_light		**light;
  int			nbr_light;
}t_object;

typedef struct s_hit_point
{
  t_bunny_color		color;
  double		dist;
  char			type;
  int			nbr;
}t_hit_point;

typedef struct s_data
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  t_cam			*cam;
  t_vect		**vect;
  t_object		*object;
}t_data;

#ifndef		RAY_H
#define		RAY_H

#include <stdio.h>

t_vect		*pix_vector(t_bunny_pixelarray	*pix,
			    int			x,
			    int			y,
			    t_cam		*cam,
			    t_vect		*vect);

t_vect		**init_vector(int		nbr_vect,
			      t_cam		*cam,
			      t_bunny_pixelarray *pix);

void		free_vect(t_vect		**vect,
			  int			len);

void		send_rtray(t_bunny_pixelarray	*pix,
			   t_vect	       	**vect,
			   t_cam		*cam,
			   t_object		*obj);

void		std_set_pixel(t_bunny_pixelarray	*px,
			      t_bunny_position		pos,
			      unsigned int		color);

double		std_get_ratio(double			max,
			      double			min,
			      double			curr);

void		std_clear_pixelarray(t_bunny_pixelarray	*pix,
				     unsigned int      	color);

t_sphere       	*init_sphere(double			x,
			     double			y,
			     double			z,
			     double			radius,
			     unsigned int		color);

t_plan		*init_plan(double	       		pos,
			   char	       			axe,
			   unsigned int	       		color);

t_light		*init_light(double			x,
			    double			y,
			    double			z,
			    unsigned int		color);

t_cylindre    	*init_cylindre(double			x,
			       double			y,
			       double			z,
			       double			radius,
			       unsigned int		color,
			       char			axe);

t_object	*create_obj(t_object			*obj);

void		draw_sphere(t_vect		       	*vect,
			    t_cam			*cam,
			    t_object			*obj,
			    t_hit_point			*hit);

t_hit_point    	*draw_plan(t_vect			*vect,
			   t_cam       			*cam,
			   t_object			*obj,
			   t_hit_point			*hit);

t_hit_point	*draw_plan_alt(t_vect			*vect,
			       t_cam			*cam,
			       t_object			*obj,
			       t_hit_point             	*hit);

void		draw_cylindre(t_vect      	       	*vect,
			      t_cam       		*cam,
			      t_object			*obj,
			      t_hit_point		*hit);

t_zpos		contact_pos(t_vect			*vect,
			    double			dist,
			    t_cam			*cam);

double		send_light(t_zpos			pos,
			   t_object			*obj,
			   t_vect			*vect);

double		get_angle(t_vect			*light,
			  t_object			*obj,
			  char				type,
			  int				compt,
			  t_zpos			pos);

double		std_get_value(double			ratio,
			      int			min,
			      int			max);

double		std_abs(double				a);

#endif //	RAY_H
