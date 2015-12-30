# Numerical Methods for ODEs

Methods used to find numerical approximations to the solutions
of ordinary differential equations (ODEs) implemented in C/C++.

- Integrates systems in any dimension.
- Calculations with float, double, long double...
- Any number of points.

## Runge Kutta 4th order

`rk4` folder. Template class `rk4` inside `rk4.h` file.

How to use `rk4` class: read `rk4/main.cpp`

> *Advice*: Runge Kutta Methods are solvers for non-stiff ODEs.

### Example: Lorenz Attractor

Extract files and open project's folder. Then:

```bash
$ cd rk4
$ make
g++ -o bin/rk4 src/main.cpp -std=c++11
$ bin/rk4 > test/lorenz.dat
$ gnuplot 

	G N U P L O T
	Version 4.6 patchlevel 4    last modified 2013-10-02 
	Build System: Linux x86_64

	Copyright (C) 1986-1993, 1998, 2004, 2007-2013
	Thomas Williams, Colin Kelley and many others

	gnuplot home:     http://www.gnuplot.info
	faq, bugs, etc:   type "help FAQ"
	immediate help:   type "help"  (plot window: hit 'h')

Terminal type set to 'wxt'
gnuplot> splot "test/lorenz.dat" using 2:3:4 with lines
```

![gnuplot window](rk4/test/lorenz.png?raw=true)
