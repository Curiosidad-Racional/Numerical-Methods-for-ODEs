#include <iostream>
#include "rk4.h"

#define SIZE 4
#define ITER 9000

using namespace std;

static const double alpha = 1.1, gamma = .87;

int main(int argc, char *argv[])
{
    double x[] = {0., -.1, 0., .1};
    double (*functions[])(double*) = {
        [](double *x) -> double { return x[2]*(x[3] - 1 + x[1]*x[1]) + gamma*x[1];   },
        [](double *x) -> double { return x[1]*(3*x[3] + 1 - x[1]*x[1]) + gamma*x[2]; },
        [](double *x) -> double { return -2*x[3]*(alpha + x[1]*x[2]);                }
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
