class tensor {

 private:
  int      m_nRows;
  int      m_nCols;
  float    *m_pfMat;

 public:
  tensor();
  ~tensor();

  tensor(const tensor &mxInput);

  void    Show();
  void    SetValue(int* pnValue, int nRows, int nCols);
  void    SetValue(float* pfValue, int nRows, int nCols);
  float   GetValue(int nRows, int nCols);
 
  tensor&   operator =(const tensor &mxInput);
  tensor    operator +(const tensor &mxInput) const;
  tensor    operator -(const tensor &mxInput) const;
  tensor    operator *(const int nInput) const;
  tensor    operator *(const float fInput) const;
  tensor    operator *(const double dInput) const;
  tensor    operator *(const tensor &mxInput) const;
 
  friend    tensor operator *(int nInput, tensor &mxInput);
  friend    tensor operator *(float fInput, tensor &mxInput);
  friend    tensor operator *(double dInput, tensor &mxInput);
 

};



/*

class tensor{
 private:
  vector<double> elements;
    
 public:
  tensor();
  double at(int i);
  static double e1[4];
  static double e2[4];
  static double e3[4];
  static double e4[4];
  static double kronecker[4][4];
  static double metric[4][4];
  operator*(const tensor &a);

};
*/
//double tensor::kronecker[0][0]={};
//double tensor::metric[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
//double tensor::kronecker[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
