#include <iostream> // input output
#include <cmath> // (for sqrt)
#include <vector>
#include <tuple>
#include "readParameters.hpp"
#include "GetPot.hpp"
#include "gnuplot-iostream.hpp"// interface with gnuplot
/*!
  @file main.cpp
  @brief Temperature distribution in a 1D bar.

  @detail
    We solve  \f$ -T^{\prime\prime}(x)+act*(T(x)-T_e)=0, 0<x<L \f$ with 
    boundary conditions \f$ T(0)=To; T^\prime(L)=0\f$
    
    **************************************************
    Linear finite elements
    Iterative resolution by Gauss Siedel.
    **************************************************
    
    Example adapted by Luca Formaggia from  a code found in 
    "Simulation numerique an C++" di I. Danaila, F. Hecht e
    O. Pironneau.
*/
//! helper function
void printHelp()
{
  std::cout<<"USAGE: main [-h] [-v] -p parameterFile (default: parameters.pot)"<<std::endl;
  std::cout<<"-h this help"<<std::endl;
  std::cout<<"-v verbose output"<<std::endl;
}

//! create function for the different choice of the user (just the result, if he wants to see the result, or both)

//! main program
int main(int argc, char** argv)
{
  using namespace std; // avoid std::
  int status(0); // final program status
  GetPot   cl(argc, argv);
 
  //if the user enter -h or --help we print the help
  if( cl.search(2, "-h", "--help") )
    {
      printHelp();
      return 0;
    }

  // check if we want verbosity
  bool verbose=cl.search(1,"-v");
  // Get file with parameter values
  string filename = cl.follow("parameters.pot","-p");
  cout<<"\nReading parameters from "<<filename<<"\n"<<std::endl;
  // read parameters
  const parameters param=readParameters(filename,verbose);
  // Transfer parameters to local variables
  // I use references to save memory (not really an issue here, it is just
  // to show a possible  use of references)
  const int& choice= param.choice; //what the user want to see (the result, just the file or both)
  const  auto& name=param.name;  //name of the file that we will find the result
  const int& norm=param.norm; //the norm that the user have chosen
  const int&    itermax= param.itermax;   //max number of iteration for Gauss-Siedel
  const double& toler=param.toler;   // Tolerance for stopping criterion
  // Here I use auto (remember that you need const and & if you want constant references)
  const auto& L= param.L;  // Bar length
  const auto& a1=param.a1; // First longitudinal dimension
  const auto& a2=param.a2; //  Second longitudinal dimension
  const auto& To=param.To; // Dirichlet condition
  const auto& Te=param.Te; // External temperature (Centigrades)
  const auto& k=param.k;  // Thermal conductivity
  const auto& hc=param.hc; // Convection coefficient
  const auto& M=param.M; // Number of grid elements
  

  // if the number in the choice variable is not 1, 2 or 3 :
   if (choice != 1 && choice != 2 && choice != 3)
  {
    //becareful input no valide
    std::cout<<"Your choice in the parameters.pot file is confused. What do you want ?"<<std::endl;
    std::cout<<"1: if you want to save the values in a file called result.dat by default"<<std::endl;
    std::cout<<"2: if you want to see the solution"<<std::endl;
    std::cout<<"3: if you want both\n"<<std::endl;
    return 0;
  }


  //! Precomputed coefficient for adimensional form of equation
  const auto act=2.*(a1+a2)*hc*L*L/(k*a1*a2);

  // mesh size
  const auto h=1./M;
  
  // Solution vector
  std::vector<double> theta_Rn(M+1);
  std::vector<double> theta_L2(M+1);
  
  // Gauss Siedel is initialised with a linear variation
  // of T
  
  for(unsigned int m=0;m <= M;++m)
     theta_Rn[m]=(1.-m*h)*(To-Te)/Te;

  theta_L2=theta_Rn;
  

 // Analitic solution

    vector<double> thetaa(M+1);
     for(int m=0;m <= M;m++)
       thetaa[m]=Te+(To-Te)*cosh(sqrt(act)*(1-m*h))/cosh(sqrt(act));

     // writing results with format
     // x_i u_h(x_i) u(x_i) and lauch gnuplot 
    Gnuplot gp;
    std::vector<double> coor(M+1);
    std::vector<double> sol(M+1);
    std::vector<double> exact(M+1);


    std::string name1;
    int test=0;

    double xnew, epsilon;


  //What do the user want ?
  if (choice==3) //if the user want all the norm 
  {
//tester si norme est conforme !!
    if (norm==1 or norm==12 or norm==123) //Rn norm
    {

      //Rn norm :
      // Gauss-Seidel
      // epsilon=||x^{k+1}-x^{k}||
      // Stopping criteria epsilon<=toler


      int iter_Rn=0;
      do
      { 
        epsilon=0.;

        // first M-1 row of linear system
        for(int m=1;m < M;m++)
        {   
          xnew  = (theta_Rn[m-1]+theta_Rn[m+1])/(2.+h*h*act);
          epsilon += (xnew-theta_Rn[m])*(xnew-theta_Rn[m]);
          theta_Rn[m] = xnew;
        }

        //Last row
        xnew = theta_Rn[M-1]; 
        epsilon += (xnew-theta_Rn[M])*(xnew-theta_Rn[M]);
        theta_Rn[M]=  xnew; 

        iter_Rn++;     
        }while((sqrt(epsilon) > toler) && (iter_Rn < itermax) );



      if(iter_Rn<itermax)
        cout << "M="<<M<<"  Convergence Rn in "<<iter_Rn<<" iterations"<<endl;
      else
      {
         cerr << "NOT CONVERGING Rn in "<<itermax<<" iterations "<<
             "||dx||="<<sqrt(epsilon)<<endl;
         status=1;
      }


      //Save file and print the result :
      cout<<"Result file Rn norm: ./results/Rn_"<<name<<"\n"<<endl;
      name1="./results/Rn_"+name;
      ofstream f(name1);
      for(int m = 0; m<= M; m++)
      {
       // \t writes a tab 
        f<<m*h*L<<"\t"<<Te*(1.+theta_Rn[m])<<"\t"<<thetaa[m]<<endl;
         
        // An example of use of tie and tuples!
         std::tie(coor[m],sol[m],exact[m])=
         std::make_tuple(m*h*L,Te*(1.+theta_Rn[m]),thetaa[m]);

      }

      // Using temporary files (another nice use of tie)
      gp<<"plot"<<gp.file1d(std::tie(coor,sol))<<
        "w lp title 'uh',"<< gp.file1d(std::tie(coor,exact))<<
        "w l title 'uex'"<<std::endl;

      //binary to know if the user can see the graph (on purpose to not see a lot of time the graph with different norm)
      test=1;

      f.close();
    }

    if (norm==2 or norm==12 or norm==123)
    {

      //L2 norm :
      // Gauss-Seidel
      // epsilon=||x^{k+1}-x^{k}||
      // Stopping criteria epsilon<=toler

      int iter_L2=0;
      xnew=0.;
      do
       { epsilon=0.;

      // first M-1 row of linear system
         for(int m=1;m < M;m++)
         {   
           xnew  = (theta_L2[m-1]+theta_L2[m+1])/(2.+h*h*act);
           epsilon += (xnew-theta_L2[m])*(xnew-theta_L2[m]);
           theta_L2[m] = xnew;
         }

      //Last row
      xnew = theta_L2[M-1]; 
      epsilon += (xnew-theta_L2[M])*(xnew-theta_L2[M]);
      epsilon = epsilon*h;
      theta_L2[M]=  xnew; 

      iter_L2++;     
       }while((sqrt(epsilon) > toler) && (iter_L2 < itermax) );



      if(iter_L2<itermax)
        cout << "M="<<M<<"  Convergence L2 in "<<iter_L2<<" iterations"<<endl;
      else
      {
         cerr << "NOT CONVERGING L2 in "<<itermax<<" iterations "<<
             "||dx||="<<sqrt(epsilon)<<endl;
         status=1;
      }


      //Save the result and print the solution : 
      cout<<"Result file L2 norm: ./results/L2_"<<name<<"\n"<<endl;
      name1="./results/L2_"+name;
      ofstream f2(name1);
      for(int m = 0; m<= M; m++)
      {
      // \t writes a tab 
       f2<<m*h*L<<"\t"<<Te*(1.+theta_L2[m])<<"\t"<<thetaa[m]<<endl;
         
        if (test==0)
        {
          std::tie(coor[m],sol[m],exact[m])=
          std::make_tuple(m*h*L,Te*(1.+theta_L2[m]),thetaa[m]); 
        } 
      }

      // Using temporary files (another nice use of tie)
      if (test==0)
     {
       gp<<"plot"<<gp.file1d(std::tie(coor,sol))<<
      "w lp title 'uh',"<< gp.file1d(std::tie(coor,exact))<<
       "w l title 'uex'"<<std::endl; 
      }

      test=1;

      f2.close();
    }
  }


  else if (choice==1)
  {
    cout<<"Result file Rn norm: ./results/Rn_"<<name<<endl;
    std::string name1="./results/Rn_"+name;
    ofstream f(name1);
    for(int m = 0; m<= M; m++)
    {
      // \t writes a tab 
     f<<m*h*L<<"\t"<<Te*(1.+theta_Rn[m])<<"\t"<<thetaa[m]<<endl;
       
      // An example of use of tie and tuples!
      std::tie(coor[m],sol[m],exact[m])=
      std::make_tuple(m*h*L,Te*(1.+theta_Rn[m]),thetaa[m]);
    }
  }

  else if (choice==2)
  {
    for(int m = 0; m<= M; m++)
    {
     // An example of use of tie and tuples!
      std::tie(coor[m],sol[m],exact[m])=
      std::make_tuple(m*h*L,Te*(1.+theta_Rn[m]),thetaa[m]);
    }

      // Using temporary files (another nice use of tie)
    gp<<"plot"<<gp.file1d(std::tie(coor,sol))<<
      "w lp title 'uh',"<< gp.file1d(std::tie(coor,exact))<<
      "w l title 'uex'"<<std::endl;
  }


     return status;
}
