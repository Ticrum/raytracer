
#include "ray.h"

t_object *create_obj(t_object *obj)
{
  t_plan **plan;
  t_sphere **sphere;
  t_cylindre **cyl;
  t_light **light;

  plan = malloc(sizeof(t_plan *) * 2);
  sphere = malloc(sizeof(t_sphere *));
  light = malloc(sizeof(t_light *));
  cyl = malloc(sizeof(t_cylindre *) * 3);
  plan[0] = init_plan(0, 'y', WHITE);
  plan[1] = init_plan(0, 'z', BLUE);
  sphere[0] = init_sphere(0, 0, 0, 96, RED);
  cyl[0] = init_cylindre(0, 0, 0, 50, TEAL, 'x');
  cyl[1] = init_cylindre(0, 0, 0, 50, YELLOW, 'y');
  cyl[2] = init_cylindre(0, 0, 0, 50, GREEN, 'z');
  light[0] = init_light(300, 170, -400, WHITE);
  obj->sphere = sphere;
  obj->nbr_sphere = 1;
  obj->plan = plan;
  obj->nbr_plan = 1;
  obj->cylindre = cyl;
  obj->nbr_cylindre = 3;
  obj->light = light;
  obj->nbr_light = 1;
  return (obj);
}

