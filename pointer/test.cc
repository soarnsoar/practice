#include <iostream>
#include <vector>
using namespace std;
int main(){

  int a=0;
  cout<<"a="<<a<<endl;//0
  cout<<"&a="<<&a<<endl;//0x7ffd50cdae04

  int *b= new int;//b는int를 향하는  바로가기가 됨. 
  *b=1;//1을 향해 가는 바로가기임.
  cout<<"b="<<b<<endl; //0x1a5e010 그냥 포인터 자체를 내놓고 다니면 그 주소를내놓고다님.
  cout<<"&b="<<b<<endl;//0x1a5e010
  cout<<"*b="<<*b<<endl;//1
  b=&a;;
  cout<<"b=&a"<<endl;
  cout<<"b="<<b<<endl; //0x7ffd50cdae04
  cout<<"&(b)="<<b<<endl;//0x7ffd50cdae04
  cout<<"*b="<<*b<<endl;//0
  
  *b=2;
  cout<<"*b=2"<<endl;
  cout<<"b="<<b<<endl;
  cout<<"&(b)="<<b<<endl;
  cout<<"*b="<<*b<<endl;
  cout<<"a="<<a<<endl;
  cout<<"&a="<<&a<<endl;
  //따라서 *b를 쓰면 a를 부르는 것과 같은 효과가 난다.
  //하지만 포인터 b를 쓰는 건 마치 우리가 수식을 계산할 때에 일단 변수로 치환해서 정리한 후에 마지막에 수치계산을 하는 것과 같은 이유다.  

  vector<int*> v;
  int *c;
  
  for(int i = 0; i < 5; i++){
    c=&i;
    cout<<"*c in for = "<<*c<<endl;
    cout<<"&i in for = "<<&i<<endl;
    v.push_back(c);
    cout<<"c in for = "<<c<<endl;
  }
  cout<<"v[0]="<<v[0]<<endl;
  cout<<"v[1]="<<v[1]<<endl;
  cout<<"v[2]="<<v[2]<<endl;
  cout<<"v[3]="<<v[3]<<endl;
  cout<<"v[4]="<<v[4]<<endl;
  cout<<"c="<<c<<endl;


  //레퍼러스 변수를 공부해보자.//
  int &d = a;// 포인터와 유사함. 하지만 바로가기와 더 유사함. d값을 출력하면 주소가 아니라 값 자체를 출력할 것임.
  //할당시에도 그 변수자체를 할당한다.
  //대신 참조대상을 변경할 수 없음. 평생 안고감.
  return 0;
  
}
