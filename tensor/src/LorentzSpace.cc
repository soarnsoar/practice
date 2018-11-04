#include "../include/LorentzSpace.h"
int LorentzSpace::dim=4;
Vector LorentzSpace::e0(LorentzSpace::dim);
Vector LorentzSpace::e1(LorentzSpace::dim);
Vector LorentzSpace::e2(LorentzSpace::dim);
Vector LorentzSpace::e3(LorentzSpace::dim);


LorentzSpace::LorentzSpace(){
  e0[0]=1;  e1[1]=1;  e2[2]=1;  e3[3]=1;

  
}
