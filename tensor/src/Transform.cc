#include <iostream>
#include "../include/Transform.h"
#include <vector>

using namespace std;



Transform::Transform(int nRow,int nCol){
  this->nRow=nRow;
  this->nCol=nCol;
  /*
    elements = new double*[nRow][nCol]
  for(int iR = 0; iR < nRow; iR++){
  elements[iR]=new double[nCol];
    for(int iC=0; iC < nCol; iC++){
      elements[iR][iC]=0;
    }
  }
  */

  for(int iR=0;iR<nRow;iR++){
    vector<double> vRow;
    for(int iC=0;iC<nCol;iC++){      
      vRow.push_back(0);
    }
    //Now vRow has nCol elements;
    elements.push_back(vRow);
    vRow.clear();    
  }
  

  
}


std::vector<double> Transform::operator [](int iR){
  return elements[iR];
}

Vector Transform::operator *(Vector v){
  if(this->nCol != v.dim){
    cout<<"dim not match in trasf * vector"<<endl;
    return v;
  }
  Vector vnew(this->nRow);
 
  for(int iR = 0 ; iR<this->nRow; iR++){
    double temp_element=0;
    for(int iC = 0; iC<this->nCol; iC++){
      temp_element+=this->elements[iR][iC]*v.elements[iC];
    }
    vnew[iR]=temp_element;
    temp_element=0;
  }
  return vnew;
}




