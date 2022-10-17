
#include "ray.h"

void send_rtray(t_bunny_pixelarray	*pix,
		t_vect			**vect,
		t_cam			*cam,
		t_object		*obj)
{
  int compt;
  int temp;
  t_zpos pos;
  t_bunny_position posi;
  t_bunny_color color;
  t_hit_point hit;
  double ratio;
  t_vect light;
  double angle;

  compt = 0;
  while (compt != pix->clipable.buffer.width * pix->clipable.buffer.height)
    {
      hit.dist = -1;
      hit.color.full = BLACK;
      hit.type = 'n';
      draw_plan(vect[compt], cam, obj, &hit);
      draw_sphere(vect[compt], cam, obj, &hit);
      draw_cylindre(vect[compt], cam, obj, &hit);
      if (hit.dist >= 0)
	{
	  pos = contact_pos(vect[compt], hit.dist, cam);
	  ratio = send_light(pos, obj, &light);
	  color.full = obj->light[0]->color;
	  if (ratio == -1)
	    hit.color.full = BLACK;
	  else if (hit.type == 's' || hit.type == 'c' || hit.type == 'p' )
	    {
	      angle = acos(get_angle(&light, obj, hit.type, hit.nbr, pos));
	      ratio = std_get_ratio(M_PI / 2, 0, angle);
	      if (ratio > 1)
		ratio = 1;
	      if (ratio < 0)
		ratio = 0;
	      temp = (hit.color.argb[RED_CMP] - (255 - color.argb[RED_CMP])) * (1 - ratio);
	      if (temp < 0)
		temp = 0;
	      hit.color.argb[RED_CMP] = temp;
	      temp = (hit.color.argb[GREEN_CMP] - (255 - color.argb[GREEN_CMP])) * (1 - ratio);
	      if (temp < 0)
		temp = 0;
	      hit.color.argb[GREEN_CMP] = temp;//(hit.color.argb[GREEN_CMP] - (255 - color.argb[GREEN_CMP])) * (1 - ratio);
	      temp = (hit.color.argb[BLUE_CMP] - (255 - color.argb[BLUE_CMP])) * (1 - ratio);
	      if (temp < 0)
		temp = 0;
	      hit.color.argb[BLUE_CMP] = temp;//(hit.color.argb[BLUE_CMP] - (255 - color.argb[BLUE_CMP])) * (1 - ratio);
	    }
	  posi.x = compt % pix->clipable.buffer.width;
	  posi.y = compt / pix->clipable.buffer.width;
	  std_set_pixel(pix, posi, hit.color.full);
	}
      compt = compt + 1;
    }
}

