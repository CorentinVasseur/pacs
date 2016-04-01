

class Matrix 
{
protected: 
  int nl_; 
  int nc_;
  Matrix (int nl_, int nc);

public: 
  ~Matrix();
  int get_nl() const {return nl_;}
  int get_nc() const {return nc_;}




};
