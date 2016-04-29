#include <vector>

class Edge
{
private:
	unsigned int unsigned_vector_;
	unsigned int boundary_vector_;

public: 
	//! default constructor
	Edge()=default;
	//8copy constructor
    Edge (const Edge & )=default;
    //!assignable
    Edge & operator= (const Edge & )=default;

    Edge(unsigned int unsigned_vector, unsigned int boundary_vector): unsigned_vector_(unsigned_vector), boundary_vector_(boundary_vector) {};

    unsigned int get_unsigned() {return unsigned_vector_;};
    unsigned int get_boundary() {return boundary_vector_;};

};