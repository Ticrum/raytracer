/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** get_ratio - 2021
**
** *****************************************************************************
*/

#include "ray.h"

double std_get_ratio(double max,
		     double min,
		     double curr)
{
  return ((double)(curr - min) / (max - min));
}

