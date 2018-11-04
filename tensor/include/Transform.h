#ifndef TRANSFORM_H
#define TRANSFORM_H


#include <vector>
#include "Vector.h"

class Transform{

 public:
  std::vector< std::vector<double> > elements;
  
  
  int nRow; //행->층수
  int nCol; //렬->좌우



  Transform(int nRow,int nCol);  
  std::vector<double> operator [](int iR);

  Vector operator *(Vector v);

};

#endif
