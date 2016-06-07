#include <functional>
#include <vector>
#include <cmath>
#include <stdexcept>

#include "RK.hpp"

using namespace ODE;

double RK23::rk_step (struct B b, std::function<double (double const &, double const &)> const & f, double const & y0, double const & t0, double const & h, double & error)
{
    double F1 = h * f(t0, y0);
    double F2 = h * f(t0 + b.c2 * h, y0 + b.a21 * F1);
    double F3 = h * f(t0 + b.c3 * h, y0 + b.a31 * F1 + b.a32 * F2);
    double F4 = h * f(t0 + b.c4 * h, y0 + b.a41 * F1 + b.a42 * F2 + b.a43 * F3);
    
    double y2 =   y0 + b.b21 * F1 + b.b23 * F3;
    double y3 =   y0 + b.b31 * F1 + b.b33 * F3 + b.b34 * F4;
    error = std::abs(y3 - y2);
    return y3;
}

double RK45::rk_step (struct B b, std::function<double (double const &, double const &)> const & f, double const & y0, double const & t0, double const & h, double & error)
{
    double F1 = h * f(t0, y0);
    double F2 = h * f(t0 + b.c2 * h, y0 + b.a21 * F1);
    double F3 = h * f(t0 + b.c3 * h, y0 + b.a31 * F1 + b.a32 * F2);
    double F4 = h * f(t0 + b.c4 * h, y0 + b.a41 * F1 + b.a42 * F2 + b.a43 * F3);
    double F5 = h * f(t0 + b.c5 * h, y0 + b.a51 * F1 + b.a52 * F2 + b.a53 * F3 + b.a54 * F4 );
    double F6 = h * f(t0 + b.c6 * h, y0 + b.a61 * F1 + b.a62 * F2 + b.a63 * F3 + b.a64 * F4 + b.a65 * F5);
    
    double y4 =   y0 + b.b41 * F1 + b.b43 * F3 + b.b44 * F4 + b.b45 * F5;
    double y5 =   y0 + b.b51 * F1 + b.b53 * F3 + b.b54 * F4 + b.b55 * F5 + b.b56 * F6;
    error = std::abs(y5 - y4);
    return y5;
}

