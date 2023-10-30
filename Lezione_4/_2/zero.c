#include <stdio.h>
#include <math.h>

double sinc(double x)
{
  return sin(x) / x;
}

int main(int argc, char** argv)
{
  double a = -15.0, b = 15.0;
 
  for(int num_points = 2; num_points <= 101; num_points++)
  {
      double dx = (b - a) / (num_points - 1);
      int num_zero = 0;

      fprintf(stderr, "Estimate based on the number of points: #%d\n", num_points);
      for(int i = 0; i < num_points - 1; i++)
      {
        double x_l = a + i * dx;
        double x_r = a + (i + 1) * dx;

        if(x_l == 0 && sinc(x_r) <= 0 || x_r == 0 && sinc(x_l) <= 0)
        {
          num_zero++;
          fprintf(stderr, "x = \t%lf \t+/- \t%lf\n", x_l == 0 ? x_r / 2.0 : x_l / 2.0, x_l == 0 ? x_r / 2.0 : x_l / 2.0);
        }
        else if(sinc(x_l) * sinc(x_r) <= 0)
        {
          num_zero++;
          fprintf(stderr, "x = \t%lf \t+/- \t%lf\n", (x_l + x_r) / 2.0, (x_l - x_r) / 2.0);
        }
      }
      fprintf(stdout, "%d %d\n", num_points, num_zero);
      fprintf(stderr, "Count: %d\n\n", num_zero);
  }
  
  return 0;
}
