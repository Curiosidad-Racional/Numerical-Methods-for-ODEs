# Numerical Methods for ODEs

Methods used to find numerical approximations to the solutions
of ordinary differential equations (ODEs) implemented in C/C++.

- Integrates systems in any dimension.
- Calculations with float, double, long double...
- Any number of points.

## Runge Kutta 4th order

`rk4` folder. Template class `rk4` inside `rk4.h` file.

How to use `rk4` class: read `rk4/lorenz.cpp` or `rk4/rabinovich.cpp`.

> *Advice*: Runge Kutta Methods are solvers for non-stiff ODEs.

### Example: Lorenz Attractor

```bash
$ cd rk4
$ make lorenz
g++ -o bin/lorenz src/lorenz.cpp -std=c++11
$ bin/lorenz > test/lorenz.dat
$ gnuplot 
...
gnuplot> splot "test/lorenz.dat" using 2:3:4 with lines
```

![gnuplot window](rk4/test/lorenz.png?raw=true)


### Example: Rabinovich–Fabrikant Attractor

```bash
$ cd rk4
$ make rabinovich
g++ -o bin/rabinovich src/rabinovich.cpp -std=c++11
$ bin/rabinovich > test/rabinovich.dat
$ gnuplot 
...
gnuplot> splot "test/rabinovich.dat" using 2:3:4 with lines
```

![gnuplot window](rk4/test/rabinovich.png?raw=true)
