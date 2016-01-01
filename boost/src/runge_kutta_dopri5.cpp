#include <string>
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>

#include <boost/array.hpp>

#include <boost/numeric/odeint.hpp>

#define FRAMES 1000
#define START 15.
#define STOP 25.

using namespace std;
using namespace boost::numeric::odeint;

typedef boost::array< double , 3 > state_type;

static double a = 10., b = START, c=8./3.;

void rhs( const state_type &x , state_type &dxdt , const double t )
{
    dxdt[0] = a*(x[1] - x[0]);
    dxdt[1] = x[0]*(b - x[2]) - x[1];
    dxdt[2] = x[0]*x[1] - c*x[2];
}


ofstream out;

void write_out( const state_type &x , const double t )
{
    out << t << ' ' << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
}


int main()
{
    state_type x = {{ 2.0, 2.0, 2.0 }};

    double t = 0.0;
    double dt = 0.01;
    double t_end = 100.0;


    typedef runge_kutta_dopri5< state_type > dopri5_type;
    typedef controlled_runge_kutta< dopri5_type > controlled_dopri5_type;
    typedef dense_output_runge_kutta< controlled_dopri5_type > dense_output_dopri5_type;

    dense_output_dopri5_type dopri5 = make_dense_output( 1E-9 , 1E-9 , dopri5_type() );

    for (unsigned int i = 1; i <= FRAMES; i++) {
        x[0] = x[1] = x[2] = 2.0;

        out.open( "test/test" + to_string(i) + ".dat" );
        out.precision(16);
        integrate_adaptive( dopri5 , rhs , x , t , t_end , dt , write_out );
        out.close();
        b += (STOP - START)/(FRAMES - 1);
    }
}
