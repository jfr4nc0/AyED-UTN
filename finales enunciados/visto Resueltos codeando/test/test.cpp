#include <iostream>
using namespace std;

struct Nodo{
  int x;
  Nodo* sig;
};

void agregarX(Nodo*& p){
int y;

  cout << "su X: ";
  cin >> y;
  p->x = y;

}

int main(){
Nodo* p = NULL;
agregarX(p);
p->sig = NULL;
cout << p->x << endl;
return 0;
}
