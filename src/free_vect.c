
#include "ray.h"

void free_vect(t_vect	**vect,
	       int	len)
{
  int compt;

  compt = 0;
  while (compt != len)
    {
      free(vect[compt]);
      compt = compt + 1;
    }
  free(vect);
}

