#include <vector>
using namespace std;
class tensor{
 private:
  vector<double> elements;
    
 public:
  tensor();
  double at(int i);
  double kronecker[4][4];
  double metric[4][4];


};
