#include <functional>
#include <vector>
#include <cmath>
#include <stdexcept>


namespace ODE
{
    
    constexpr std::size_t MAX_STEPS=10000;

    
    template <class R>
    class RK
    {
    public:
        
        //defintion function
        double rk_step (std::function<double (double const &, double const &)> const & f,double const & y0, double const & t0,double const & h,double & error);
        
    };
    
    
    //template function rk45_step()
    template <class R>
    double RK<R>::rk_step (
                        std::function<double (double const &, double const &)> const & f,
                        double const & y0,
                        double const & t0,
                        double const & h,
                        double & error
                        )
        {
            R rk;
            return rk.rk_step(rk.get_B(),f,y0,t0,h,error);
        }
    
    //template function rk45()
    template <class R, typename D>
    std::vector<std::pair<double,double>> rk (
                                                    D c1, D c2,
                                                     std::function<double (double const &, double const &)> const & dy,
                                                     double const & t0,
                                                     double const & T,
                                                     double const & y0,
                                                     double const & h_initial,
                                                     double const & h_max,
                                                     double const & final_error,
                                                     int & status,
                                                     std::size_t const & maxSteps
                                                     )
    {
        RK<R> rkbis;
        status=0;
        // ?? unsused const std::size_t maxReduction=maxSteps;
        // parameters for decreasing/increasing time step
        //double const c1=1.0;
        // I need to have a sufficient decrease of the local error
        // to allow time step coarsening
        //double const c2=1./64.;
        double length=T-t0;
        //! Make sure that h allows to reach T
        std::size_t initialNSteps=std::max(static_cast<size_t>(1),static_cast<size_t>(length/h_initial));
        double h=length/initialNSteps;
        // To avoid underflow we need in any case to limit the time step to a positive number
        // Here I allow h to become 128 time smaller than that giving the maximal number of steps
        double h_min = length/(128*maxSteps);
        // SOme counters
        std::size_t stepsCounter(0);
        // Initial data
        double time(t0);
        double y(y0);
        double errorPerTimeStep=final_error/initialNSteps;
        if (initialNSteps>=maxSteps) throw std::runtime_error("RK: initial time step h too small!");
        std::vector<std::pair<double,double>> solution;
        solution.emplace_back(std::make_pair(t0,y0));
        double localError;
        double newy;
        while (time<T && stepsCounter <maxSteps)
        {
            //Do a step
            //adjust h if needed for the last step
            if (time + h > T) h = T-time;
            newy = rkbis.rk_step(dy,y,time,h,localError);
            while (h> h_min && localError > c1*errorPerTimeStep)
            {
                // half time step
                h /=2;
                errorPerTimeStep /=2;
                newy = rkbis.rk_step(dy,y,time,h,localError);
            }
            if (localError>errorPerTimeStep)status=1;
            //! advance
            y = newy;
            time +=h;
            ++stepsCounter;
            solution.emplace_back(std::make_pair(time,y));
            //! check if we reached end
            if(localError<c2*errorPerTimeStep && h<h_max)
            {
                // Double step
                h *=2;
                errorPerTimeStep *=2;
            }
        }
        //handle exceptions
        if(stepsCounter>=maxSteps && time < T)
        {
            status=2;
            throw std::runtime_error("RK: Max number of time steps exceeded");
        }
        return solution;
        
    }

    
    class RK23
    {
        struct B
        {
            // Butcher array (row 1 is trivial) R23
            double a21;
            double c2 ;
            double a31;
            double a32;
            double c3;
            double a41;
            double a42;
            double a43;
            double c4;
            double b21;
            double b22;
            double b23;
            double b24;
            double b31;
            double b32;
            double b33;
            double b34;
        };
    private:
        struct B b = {1./2.,1./2.,0.,3./4,3./4.,2./9.,1./3.,4./9.,1.,7./24.,1./4.,1./3.,1./8.,2./9.,1./3.,4./9.,0};
        
    public:
        struct B get_B() {return b;}
        double rk_step (struct B b, std::function<double (double const &, double const &)> const & f, double const & y0, double const & t0, double const & h, double & error);
    };





    class RK45
    {
        struct B
        {
            double a21;
            double c2;
            double a31;
            double a32;
            double c3;
            double a41;
            double a42;
            double a43;
            double c4;
            double a51;
            double a52;
            double a53;
            double a54;
            double c5;
            double a61;
            double a62;
            double a63;
            double a64;
            double a65;
            double c6;
            double b41;
            double b43;
            double b44;
            double b45;
            double b51;
            double b53;
            double b54;
            double b55;
            double b56;
        };
        
    private:
        struct B b = {1./4.,1./4.,3./32,9./32,3./8.,1932./2197.,-7200./2197.,7296./2197.,12./13.,439./216.,- 8.,3680./513.,-845./4104.,1.,-8./27., 2.,-3544./2565.,1859./4104.,-11./40.,1./2.,25./216.,1408./2565.,2197./4104.,-1./5.,16./135.,6656./12825.,28561./56430.,-9./50.,2./55.};
    public:
        struct B get_B() {return b;}
        double rk_step (struct B b, std::function<double (double const &, double const &)> const & f, double const & y0, double const & t0, double const & h, double & error);
    };

}//end namespace ODE