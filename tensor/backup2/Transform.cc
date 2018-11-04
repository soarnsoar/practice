#include "../include/Transform.h"
/*
#include "Vector.h"
class Transform{
 private:
  int nRow; //행->층수                                                                                                                                        
  int nCol; //렬->좌우                                                                                                                                        
  double* elements;
  double* Row;
 public:
  Transform(int nRow, int nCol);
  double& operator[](int i);
  Vector operator =(Transform v);
  double operator *(Vector v);
  Vector operator +(Transform v);

  class Row{
  private:
    double *elements;

  public:
    Row(nCol);
    double& operator [](Row R);
  };

  Row*& operator [](int iR);




};




};
*/
Row::Row(int nCol){
  this->nCol=nCol;
  this->elemets = new double[nCol];
  for(int iC = 0; iC < nCol; iC++){
    this->elements[iC]=0;
  }
}

double& Row::operator [](int iC){
  return this->elements[iC];

}
Transform::Transform(const int nRow,const int nCol){
  this->nRow=nRow;
  this->nCol=nCol;
  /*
  this->elements = new double[nRow*nCol];
  for(int i = 0 ; i < nRow*nCol; i++){
    elements[i]=0;
  }
  this->Row = new double[nCol];
  */
  // static int nRow_=nRow;
  //static int nCol_=nCol;
  
  //  this->elements = new double[nRow_][nCol_];
  this->elements = new double*[nRow]; //nRow크기임. 원소는 nRow개이다. 원소 종류는 double을 향하는 포인터다. 그 포인터를 가리키는 포인터임.
  
  for(int iR = 0; iR < nRow; iR++){
    this->elements[iR]=new double[nCol];//elements의 i번째 원소는 포인터인데 nCol크기의 배열의 원소들을 가리킴.
    
    for(int iC = 0 ; iC < nCol; iC++){
      //      this->elements[iR][iC] = 0;

    }

  }  




}

/*
  class Row{
  private:
    double *elements;

  public:
    Row(nCol);
    double& operator [](Row R);
  };

  Row*& operator [](int iR);

*/



Row*& Transform::operator[](int iR){
  return this->Row[iR];//refer to the value in elements pointer
}


