#include "Grid.hpp"
#include <iostream>

//! method 1: reads the file mesh.dat
void Grid::read (std::string file)
{

}
//! method 2: compute the sum of the areas of all polygons stored in the grid
double Grid::sum_area ()
{
	double sum=0.;
	for (std::shared_ptr<AbstractPolygon> polygon : polygon_vector)
	{
		sum = sum + polygon->area();
	}
	return sum;
}
