#include <vector>
#include "Polygon.hpp"

using namespace Geometry;


class Grid
{
private:
	std::vector<std::shared_ptr<AbstractPolygon>> polygon_vector;
	Vertices point2d_vector;
public: 
	//! default constructor
	Grid()=default;
	//! destructor
	~Grid()=default;
	//! method 1: reads the file mesh.dat
	void read (std::string file);
	//! method 2: compute the sum of the areas of all polygons stored in the grid
	double sum_area ();
	};
