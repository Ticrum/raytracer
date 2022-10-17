
#include "ray.h"

t_bunny_response key(t_bunny_event_state state,
		     t_bunny_keysym      sym,
		     void		 *d)
{
  t_data *data;

  data = (t_data *)d;
  //printf("pl addr %p\n", data->object->sphere[0]);
  std_clear_pixelarray(data->pix, BLACK);
  if (state == GO_UP)
    return (GO_ON);
  if (sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (sym == BKS_Z)
    data->cam->z = data->cam->z + 5;
  if (sym == BKS_S)
    data->cam->z = data->cam->z - 5;
  if (sym == BKS_Q)
    data->cam->x = data->cam->x + 5;
  if (sym == BKS_D)
    data->cam->x = data->cam->x - 5;
  if (sym == BKS_A)
    data->cam->y = data->cam->y + 5;
  if (sym == BKS_E)
    data->cam->y = data->cam->y - 5;
  if (sym == BKS_T)
    data->object->light[0]->pos.z = data->object->light[0]->pos.z + 5;
  if (sym == BKS_G)
    data->object->light[0]->pos.z = data->object->light[0]->pos.z - 5;
  if (sym == BKS_F)
    data->object->light[0]->pos.x = data->object->light[0]->pos.x + 5;
  if (sym == BKS_H)
    data->object->light[0]->pos.x = data->object->light[0]->pos.x - 5;
  if (sym == BKS_R)
    data->object->light[0]->pos.y = data->object->light[0]->pos.y + 5;
  if (sym == BKS_Y)
    data->object->light[0]->pos.y = data->object->light[0]->pos.y - 5;
  printf("x %f y %f z %f\n", data->cam->x, data->cam->y, data->cam->z);
  send_rtray(data->pix, data->vect, data->cam, data->object);
  bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
  bunny_display(data->win);
  return (GO_ON);
}

int main(void)
{
  t_data data;
  t_cam cam;
  t_object object;
  int size;

  size = 1000;
  data.win = bunny_start(size, size, false, "Bunny");
  data.pix = bunny_new_pixelarray(size, size);
  cam.x = 130;
  cam.y = 170;
  cam.z = -600;
  cam.dist = 300;
  data.cam = &cam;
  data.vect = init_vector(data.pix->clipable.buffer.width * data.pix->clipable.buffer.height, data.cam, data.pix);
  create_obj(&object);
  data.object = &object;
  printf("obj addr %p\n", data.object);
  std_clear_pixelarray(data.pix, BLACK);
  send_rtray(data.pix, data.vect, data.cam, data.object);
  bunny_blit(&data.win->buffer, &data.pix->clipable, NULL);
  bunny_display(data.win);
  bunny_set_key_response(key);
  bunny_loop(data.win, 30, (void *)&data);
  bunny_stop(data.win);
  free_vect(data.vect, data.pix->clipable.buffer.width * data.pix->clipable.buffer.height);
  return (0);
}
