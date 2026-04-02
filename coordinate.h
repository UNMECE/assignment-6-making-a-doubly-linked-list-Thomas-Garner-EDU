#ifndef COORDINATE_H
#define COORDINATE_H

struct _coordinate
{
  float x;
  float y;
  int coord_id;
  struct _coordinate *next;
  struct _coordinate *previous;
};
typedef struct _coordinate Coordinate;

#endif
