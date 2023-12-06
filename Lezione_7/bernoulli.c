#include <stdio.h>
#include <math.h>

typedef unsigned long long int u64;

u64 factorial(u64 num) 
{
    return num == 0 ? 1 : num * factorial(num - 1); 
}

u64 binomial(u64 n, u64 k)
{
    return factorial(n) / (factorial(k) * factorial(n-k));
}

double bernoulli_distribution(u64 n, u64 k, double p)
{
    return binomial(n, k) * pow(p, k) * pow(1.0 - p, n - k);
}

int main(int argc, char** argv)
{
    FILE* file = fopen("bernoulli.dat", "w+");
    if(!file) return 1;

    u64 n = 20;
    double p = 1.0 / 6.0;
    for(u64 k = 0; k <= n; k++)
    {
        fprintf(file, "%lld %lf\n", k, bernoulli_distribution(n, k, p));
    }

    fclose(file);
    return 0;
}