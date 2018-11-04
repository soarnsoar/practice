#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
class Vector{
  //Vector = Tensor(0,N) dim.
  
 private:

  //  double *elements;


 public:
  std::vector<double> elements;
  ///Constructor///
  Vector(int dim);
  int dim; 
  //Get element//
  double& operator[](int i);    
  
  //Equal//
  Vector operator =(Vector v);
  //inner product//
  double operator *(Vector v);
  //add//
  Vector operator +(Vector v);


    
  
};
#endif
