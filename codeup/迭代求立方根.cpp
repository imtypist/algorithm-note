#include <cstdio>

double iterate(double y, double x)
{
    return y * 2 / 3.0 + x / (3 * y * y);
}

int main()
{
    double x, y;
    int n;
    while(scanf("%lf%d", &x, &n) != EOF)
    {
        y = x;
        for(int i=0; i<n; i++)
        {
            y = iterate(y, x);
        }
        printf("%.6lf\n", y);
    }
    return 0;
}
