#include <stdio.h>
#include <math.h>

double sinc(double x)
{
  return sin(x) / x;
}

int main(int argc, char** argv)
{
  double a = -15.0, b = 15.0;
  int num_points = 0;  
  
  do
  {   
      fprintf(stderr, "Enter the number of points: ");
      scanf("%d", &num_points);
      printf("\n");
  }
  while(!(num_points >= 100));
  double dx = (b - a) / (num_points - 1);
  
  fprintf(stderr, "sinc(x) = sin(x) / x\n\n");
  for(int i = 0; i < num_points; i++)
  {
    double x = a + i * dx;
    if(x == 0.0)
      {
	fprintf(stderr, "sinc(0) -> 1\n");
	fprintf(stdout, "%lf %lf\n", 0.0, 1.0);
      }
    else
      {
	fprintf(stderr, "sinc(x) = %lf\n", sinc(x));
	fprintf(stdout, "%lf %lf\n", x, sinc(x));
      }
  }
  
  return 0;
}
