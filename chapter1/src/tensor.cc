#include "../include/tensor.h"
tensor::tensor(){

  for(int i = 0 ; i < 4 ; i ++ ){
    for(int j = 0 ; j < 4 ; j ++){
      kronecker[i][j]=0;
      if(i==j){
	kronecker[i][j]=1;
	metric[i][j]=-1;
      }
    }
  }
  metric[0][0]=1;



  

  
      
  
}
double tensor::at(int i){
  return elements[i];

}
//double tensor::kronecer[4];
//double tensor::metric[4];

