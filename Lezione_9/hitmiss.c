#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int nell_ellisse(double x, double y, double a, double b)
{
  return (a * x * x + b * y * y < 1);
}

double genera_coordinata()
{
  return drand48() * 4.0 - 2.0;
}

int main()
{
  srand48(time(NULL));

  unsigned int N_p;
  printf("Inserisci il numero di punti da stimare: ");
  scanf("%u", &N_p);

  unsigned int conta = 0;
  for(unsigned int i = 0; i < N_p; i++)
  {
    double x, y;
    x = genera_coordinata();
    y = genera_coordinata();

    if(nell_ellisse(x, y, 0.25, 1.0) &&
       nell_ellisse(x, y, 1.0, 0.25))
      {
	conta++;
      }
  }

  double area = 16.0 * (double)conta / (double)N_p;
  printf("%d, %lf\n", conta, area);
  
  printf("Valore integrazione \t%.2lf\nValore analitico \t%.2lf",
	 area, 4 * asin(0.8));
  
  return 0;
}
