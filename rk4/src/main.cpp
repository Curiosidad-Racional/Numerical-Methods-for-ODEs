#include <iostream>
#include "rk4.h"

#define SIZE 2
#define ITER 1000

using namespace std;

double fun(double* x) {
    return x[1];
}

int main(int argc, char *argv[])
{
    double x[] = {0., 1.};
    double (*functions[])(double*) = { fun };
    rk4<double> ode(0.001, functions, x, SIZE);

    ode.iterate(ITER);

    for (unsigned int i = 0; i <= ITER; i++) {
        for (unsigned int j = 0; j < SIZE; j++)
            cout << ode.x[i][j] << " ";
        cout << endl;
    }
    return 0;
}
