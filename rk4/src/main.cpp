#include <iostream>
#include "rk4.h"

#define SIZE 4
#define ITER 50000

using namespace std;

static const double a = 10., b = 28., c=8./3.;

int main(int argc, char *argv[])
{
    double x[] = {0., 2., 2., 2.};
    double (*functions[])(double*) = {
        [](double *x) -> double { return a*(x[2] - x[1]);         },
        [](double *x) -> double { return x[1]*(b - x[3]) - x[2];  },
        [](double *x) -> double { return x[1]*x[2] - c*x[3];      }
    };
    rk4<double> ode(0.001, functions, x, SIZE);

    ode.iterate(ITER);

    for (unsigned int i = 0; i <= ITER; i++) {
        for (unsigned int j = 0; j < SIZE; j++)
            cout << ode[i][j] << " ";
        cout << endl;
    }
    return 0;
}
