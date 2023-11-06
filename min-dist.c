#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
  double x;
  double y;
} Point;

double CalDist(Point p1, Point p2)
{
  // printf("%.2lf %.2lf\n", p1.x, p1.y);
  // printf("%.2lf %.2lf\n", p2.x, p2.y);

  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  return sqrt(dx * dx + dy * dy);
}

void FindMinDist(Point *points, int size)
{
  double min = CalDist(points[0], points[1]);
  // printf("%.4lf", min);

  for (int i = 0; i < size - 1; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      double d = CalDist(points[i], points[j]);
      // printf("%.4lf", d);
      if (d < min)
      {
        min = d;
      }
    }
  }

  printf("%.4lf", min);
}

int main()
{
  int size = -1;
  scanf("%d", &size);

  Point *points = malloc(sizeof(Point) * size);

  for (int i = 0; i < size; i++)
  {
    double x, y;
    scanf("%lf %lf", &x, &y);

    points[i].x = x;
    points[i].y = y;
  }

  FindMinDist(points, size);

  return 0;
}