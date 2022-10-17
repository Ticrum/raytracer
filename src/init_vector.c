
#include "ray.h"

t_vect **init_vector(int		nbr_vect,
		     t_cam		*cam,
		     t_bunny_pixelarray *pix)
{
  t_vect **vect;
  int compt;

  if ((vect = malloc(sizeof(t_vect *) * nbr_vect)) == NULL)
    return (NULL);
  compt = 0;
  while (compt != nbr_vect)
    {
      if ((vect[compt] = malloc(sizeof(t_vect))) == NULL)
	return (NULL);
      pix_vector(pix, compt % pix->clipable.buffer.width, compt / pix->clipable.buffer.width, cam, vect[compt]);
      compt = compt + 1;
    }
  return (vect);
}
