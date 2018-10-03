#include "llist.h"
using namespace std;

int main(int argc, char const *argv[]) {
  char tes = 'A';
  llist <char> lista;
  for (int i = 0; i < 26; i++){
    llnode <char> *node;
    node = new llnode <char> (tes, NULL, NULL);
    lista.listInsert(node);
    tes++;
  }
  llnode<char> * lis = lista.listSearch('K');
  cout << lis->key << endl;
  //lista.print();
  return 0;
}
