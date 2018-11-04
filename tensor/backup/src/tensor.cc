tensor::tensor() {
  m_nCols    = 0;
  m_nRows    = 0;
  m_pfMat    = 0;
}

 

tensor::~tensor() {

  if(m_pfMat) {
    delete(m_pfMat);
    m_pfMat    = 0;
  }
}

 

tensor::tensor(const tensor &mxInput) {
  m_nCols    = mxInput.m_nCols;
  m_nRows    = mxInput.m_nRows;
  m_pfMat    = new float[m_nRows*m_nCols];
  for(int i=0; i<m_nRows*m_nCols; i++)
    m_pfMat[i]    = mxInput.m_pfMat[i];

}

 

void tensor::Show() {
  for(int i=0; i<m_nRows; i++) {
    printf("| ");
    for(int j=0; j<m_nCols; j++) {
      printf("%5.2f ", m_pfMat[i*m_nCols+j]);
    }
    printf(" |\n");
  }
  printf("\n");
}

 

void tensor::SetValue(int *pnValue, int nRows, int nCols) {
  m_nRows    = nRows;
  m_nCols    = nCols;

  if(m_pfMat)
    delete(m_pfMat);

  m_pfMat    = new float[nRows*nCols];
  for(int i=0; i<nRows*nCols; i++)
    m_pfMat[i]    = (float)pnValue[i];

}

void tensor::SetValue(float *pfValue, int nRows, int nCols) {
  m_nRows    = nRows;
  m_nCols    = nCols;
  if(m_pfMat)
    delete(m_pfMat);

  m_pfMat    = new float[nRows*nCols];
  for(int i=0; i<nRows*nCols; i++)
    m_pfMat[i]    = pfValue[i];
}

 

float tensor::GetValue(int nRows, int nCols) {
  return    m_pfMat[(nRows-1)*m_nCols+(nCols-1)];
}

 

tensor & tensor::operator =(const tensor &mxInput) {
  if(m_pfMat)
    delete(m_pfMat);
  m_nCols    = mxInput.m_nCols;
  m_nRows    = mxInput.m_nRows;
  m_pfMat    = new float[m_nRows*m_nCols];
  for(int i=0; i<m_nRows*m_nCols; i++)
    m_pfMat[i]    = mxInput.m_pfMat[i];
  return *this;

}

 

tensor tensor::operator +(const tensor &mxInput) const {
  if(m_nRows != mxInput.m_nRows || m_nCols != mxInput.m_nCols) {
    printf("tensor dimension error, (+ operation) \n");
    exit(0);
  }

  tensor    mxSum;
  float*    pfTmp    = new float[m_nRows*m_nCols];

  for(int i=0; i<m_nRows*m_nCols; i++)
    pfTmp[i]    = mxInput.m_pfMat[i] + m_pfMat[i];

  mxSum.m_nCols = m_nCols;
  mxSum.m_nRows = m_nRows;
  mxSum.SetValue(pfTmp, m_nRows, m_nCols);

  delete(pfTmp);
  return    mxSum;

}

 

tensor tensor::operator -(const tensor &mxInput) const {
  if(m_nRows != mxInput.m_nRows || m_nCols != mxInput.m_nCols) {
    printf("tensor dimension error, (- operation) \n");
    exit(0);
  }
  tensor    mxSum;
  float*    pfTmp    = new float[m_nRows*m_nCols];

  for(int i=0; i<m_nRows*m_nCols; i++)
    pfTmp[i]    = m_pfMat[i] - mxInput.m_pfMat[i];

  mxSum.m_nCols = m_nCols;
  mxSum.m_nRows = m_nRows;
  mxSum.SetValue(pfTmp, m_nRows, m_nCols);
  delete(pfTmp);
  return    mxSum;
}

 

tensor tensor::operator *(const int nInput) const {
  tensor    mxMult;
  float*    pfTmp    = new float[m_nRows*m_nCols];

  for(int i=0; i<m_nRows*m_nCols; i++)
    pfTmp[i]    = nInput * m_pfMat[i];
  mxMult.m_nCols = m_nCols;
  mxMult.m_nRows = m_nRows;
  mxMult.SetValue(pfTmp, m_nRows, m_nCols);
  delete(pfTmp);
  return    mxMult;
}

 

tensor tensor::operator *(const float fInput) const {
  tensor    mxMult;
  float*    pfTmp    = new float[m_nRows*m_nCols];
  for(int i=0; i<m_nRows*m_nCols; i++)
    pfTmp[i]    = fInput * m_pfMat[i];

  mxMult.m_nCols = m_nCols;
  mxMult.m_nRows = m_nRows;
  mxMult.SetValue(pfTmp, m_nRows, m_nCols);

  delete(pfTmp);
  return    mxMult;
}

 

tensor tensor::operator *(const double dInput) const {
  tensor    mxMult;
  float*    pfTmp    = new float[m_nRows*m_nCols];
  for(int i=0; i<m_nRows*m_nCols; i++)
    pfTmp[i]    = (float)dInput * m_pfMat[i];

  mxMult.m_nCols = m_nCols;
  mxMult.m_nRows = m_nRows;
  mxMult.SetValue(pfTmp, m_nRows, m_nCols);

  delete(pfTmp);
  return    mxMult;
}

 

tensor tensor::operator *(const tensor &mxInput) const {

  if(m_nCols != mxInput.m_nRows) {
    printf("tensor dimension error, (* operation) \n");
    exit(0);
  }

  tensor    mxMult;
  float*    pfTmp    = new float[m_nRows*mxInput.m_nCols];

  for(int i=0; i<m_nRows*mxInput.m_nCols; i++)
    pfTmp[i]    = 0.0;

  int    nIndex    = 0;
  for(int i=0; i<m_nRows; i++) {
    for(int j=0; j<mxInput.m_nCols; j++) {
      for(int k=0; k<m_nCols; k++) {
	pfTmp[i*mxInput.m_nCols+j]    += m_pfMat[i*m_nCols+k] * mxInput.m_pfMat[j+k*mxInput.m_nCols];
      }
    }
  }

  mxMult.SetValue(pfTmp, m_nRows, mxInput.m_nCols);

  delete(pfTmp);
  return    mxMult;
}

 

tensor operator *(int nInput, tensor &mxInput) {
  return    mxInput * nInput;
}

tensor operator *(float fInput, tensor &mxInput) {
  return    mxInput * fInput;
}

tensor operator *(double dInput, tensor &mxInput) {
  return    mxInput * dInput;
}




/*#include "../include/tensor.h"
double tensor::e1[4]={1,0,0,0};// {1 0 0 0 }^T
double tensor::e2[4]={0,1,0,0};//
double tensor::e3[4]={0,0,1,0};//
double tensor::e4[4]={0,0,0,1};//

//double tensor::metric[4][4]={tensor::e1,-(tensor::e2),-(tensor::e3),-(tensor::e4)};//{ v1^T v2^T v3^T v4^T     } 
double tensor::kronecker[4][4]={tensor::e1,tensor::e2,tensor::e3,tensor::e4};

tensor::tensor(){      
  
}

double tensor::at(int i){
  return elements[i];

}


*/
