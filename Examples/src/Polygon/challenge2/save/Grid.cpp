#include "Grid.hpp"

#include <iostream>
#include <fstream>
#include <string>

static int NB_POLYGONS=0;
static int NB_POINTS=0;

//! method 1: reads the file mesh.dat
void Grid::read (std::string filename)
{


	//to initialize the Grid
	point2d_vector.clear();
	polygon_vector.clear();

	//open the file in reading 
	std::ifstream file(filename);

	if (!file)
 	{
    	std::cerr<<"ERROR: Parameter file "<<filename<<" does not exist"<<std::endl;
    	file.close();
 	}
 	else
	{ 
		std::cout<<"\nReading parameters from "<<filename<<"\n"<<std::endl;

		//read the first line to know the number of points (P) and connectivity
		file >> NB_POINTS >> NB_POLYGONS;

		int id;
		double x,y;

		//Points:
		std::cout<<"\nPoints: "<<"\n"<<std::endl;		
		for (int i = 0; i < NB_POINTS; ++i)
		{
			file >> id >> x >> y;
			point2d_vector.push_back(Geometry::Point2D(x,y));
			std::cout << x << " " << y << std::endl;
		}
			std::cout << "\n" << std::endl;


		//Connectivity :
		std::cout<<"\nPolygon: "<<"\n"<<std::endl;	
		int type;
		int n1,n2,n3,n4;
		Geometry::Vertices v;

		for (int i = 0; i < NB_POLYGONS; ++i)
		{

			file >> id >> type;

			switch (type)
			{
				case(0): //triangle
				{
					file >> n1 >> n2 >> n3;

					std::cout << "Triangle: "<< n1 << n2 << n3 << std::endl;

			 		v.push_back(point2d_vector[n1]);
			 		v.push_back(point2d_vector[n2]);
			 		v.push_back(point2d_vector[n3]);

     	  			std::shared_ptr<Geometry::Triangle> share_type(new Geometry::Triangle(v));
     	  			polygon_vector.push_back(share_type);
     	  			v.clear();

					break;
				}
				case(1): //square
				{

					file >> n1 >> n2 >> n3 >> n4;

					std::cout << "Square: "<< n1 << n2 << n3 << n4 << std::endl;

			 		v.push_back(point2d_vector[n1]);
			 		v.push_back(point2d_vector[n2]);
			 		v.push_back(point2d_vector[n3]);
			 		v.push_back(point2d_vector[n4]);
			 				 					 		
     	  			std::shared_ptr<Geometry::Square> share_type(new Geometry::Square(v));
     	  			polygon_vector.push_back(share_type);
     	  			v.clear();

					break;				

				}
				case(2): // other polygon
				{
					file >> n1 >> n2 >> n3 >> n4;

					std::cout << "Other Polygon: " << n1 << n2 << n3 << n4 << std::endl;

			 		v.push_back(point2d_vector[n1]);
			 		v.push_back(point2d_vector[n2]);
			 		v.push_back(point2d_vector[n3]);
			 		v.push_back(point2d_vector[n4]);

     	  			std::shared_ptr<Geometry::Polygon> share_type(new Geometry::Polygon(v));
     	  			polygon_vector.push_back(share_type);
     	  			v.clear();			 		

					break;	
				}
			}
		}

		std::cout << "\n" << std::endl;
    	file.close();		

	}
}
//! method 2: compute the sum of the areas of all polygons stored in the grid
double Grid::sum_area ()
{
	double sum=0.;
	for (std::shared_ptr<Geometry::AbstractPolygon> polygon : polygon_vector)
	{
		sum = sum + polygon->area();
	}
	return sum;
}
