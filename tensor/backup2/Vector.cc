#include <iostream>
#include "../include/Vector.h"
using namespace std;
Vector::Vector(int dim){
  this->dim = dim;
  this->elements=new double[dim];

  for(int i = 0; i < dim;i++){
    this->elements[i]=0;
  }
}

double& Vector::operator[](int i){
  return this->elements[i];//refer to the value in elements pointer
}

double Vector::operator*(Vector v){
  if(v.dim != this->dim){
    cout<<"dimensions are not matched"<<endl;

    return -1;
  }
  double product=0;
  for(int i = 0 ; i < this->dim; i++){
    product+=this->elements[i]*v[i];
  }
  return product;
}

Vector Vector::operator=(Vector v){
  if(v.dim != this->dim){
    cout<<"dimensions are not matched"<<endl;

    return -1;
  }
  
  Vector vnew(this->dim);
  for(int i = 0 ;  i < this->dim; i++){
    vnew[i]=v[i];
  }
  return vnew;
}

Vector Vector::operator+(Vector v){
  if(v.dim != this->dim){
    cout<<"dimensions are not matched"<<endl;

    return -1;
  }
  
  Vector vnew(this->dim);
  
  for(int i = 0 ; i < this->dim; i++){
    vnew[i]=this->elements[i]+v[i];
    
  }
  return vnew;
}



