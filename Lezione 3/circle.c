#include <stdio.h>
#include <math.h>

#define RADIUS 6.2
#define OMEGA (2 * M_PI / 60.0)

int main(int argc, char** argv)
{
  double time, x, y, vx, vy;
  FILE* f = fopen("trajectory.dat", "w+");
  
  //printf("Enter the time value. ");
  //scanf("%lf", &time);

  for(int i = 0; i <= 60; i++)
  {
    time = (double)i;
    x = RADIUS * cos(OMEGA * time);
    y = RADIUS * sin(OMEGA * time);
    vx = -OMEGA * RADIUS * sin(OMEGA * time);
    vy = OMEGA * RADIUS * cos(OMEGA * time);

    fprintf(f, "%lf %lf %lf %lf %lf\n", time, x, y, vx, vy);
  }
  
  //printf("[x(t), y(t)] = [%lf, %lf]\n", x, y);

  fclose(f);
  
  return 0;
}
