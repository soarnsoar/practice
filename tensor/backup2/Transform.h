#include "Vector.h"
class Transform{
 private:
  int nRow; //행->층수
  int nCol; //렬->좌우
  double** elements;

 public:
  Transform(const int nRow,const int nCol);
  //  double& operator[](int i);

  Vector operator =(Transform v);
  double operator *(Vector v);
  Vector operator +(Transform v);
  
  
  class Row{
  private:
    double *elements;
    int nCol;
  public:
    Row(nCol);
    double& operator [](Row iC);    
  };
  
  Row*& operator [](int iR);    
  
  

};
