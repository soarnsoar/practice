class Vector{
  //Vector = Tensor(0,N) dim.
  
 private:
  int dim; 
  double *elements;
 public:



  ///Constructor///
  Vector(int dim);
  //Get element//
  double& operator[](int i);    
  
  //Equal//
  Vector operator =(Vector v);
  //inner product//
  double operator *(Vector v);
  //add//
  Vector operator +(Vector v);


    
  
};
