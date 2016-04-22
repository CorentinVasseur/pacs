#include "Polygon.hpp"
#include "Grid.hpp"
#include <iostream>
//! Main program
int main()
{
  using namespace Geometry;

  Grid grip;
  grip.read("mesh.dat");

  std::cout << "Sum of the areas: " << grip.sum_area() << "\n" << std::endl;

}
  

