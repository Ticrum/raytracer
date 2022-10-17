/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** set_pixel - 2021
**
** *****************************************************************************
*/

#include "ray.h"

void std_set_pixel(t_bunny_pixelarray	*px,
		   t_bunny_position	pos,
		   unsigned int		color)
{
  int *copy;
  int w;
  int h;
  int coord;
  double ratio;
  t_bunny_color colori[2];

  w = px->clipable.buffer.width;
  h = px->clipable.buffer.height;
  copy = px->pixels;
  coord = pos.x + pos.y * w;
  colori[0].full = copy[coord];
  colori[1].full = color;
  ratio = std_get_ratio(0, 255, colori[1].argb[ALPHA_CMP]);
  colori[0].argb[RED_CMP] = (1 - ratio) * colori[1].argb[RED_CMP] + (ratio) * colori[0].argb[RED_CMP];
  colori[0].argb[GREEN_CMP] = (1 - ratio) * colori[1].argb[GREEN_CMP] + (ratio) * colori[0].argb[GREEN_CMP];
  colori[0].argb[BLUE_CMP] = (1 - ratio) * colori[1].argb[BLUE_CMP] + (ratio) * colori[0].argb[BLUE_CMP];
  if (pos.y >= 0 && pos.y <= h && pos.x <= w && pos.x >= 0)
    copy[coord] = colori[0].full;
}

