#include <vector>
#include "Polygon.hpp"
#include "Edge.hpp"

class Grid
{
private:
	std::vector<std::shared_ptr<Geometry::AbstractPolygon>> polygon_vector;
	Geometry::Vertices point2d_vector; //Vertices<=>std::vector<Point2D>
	std::vector<Edge> edges_vector;
	std::vector<Edge> boundary_vector;
public: 
	//! default constructor
	Grid()=default;
    //! copy constructor
    Grid(Grid const &) =default;
    //! assignable
    Grid & operator=(Grid const&) =default;
	//! method 1: reads the file mesh.dat
	void read (std::string filename);
	//! method 2: compute the sum of the areas of all polygons stored in the grid
	double sum_area ();

};
