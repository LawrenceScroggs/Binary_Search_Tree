// Lawrence Scroggs CS163 03/02/19
// This program will take computer science terms and put them into a binary
// search tree.  We will use a hash_key to place the item into the binary search tree.


#include "compCon.h"


int main(){

  bst to_add;
  compCon build;

  char again = ' ';

  while(again != 'n')
  {
    build.addNew();
    cout << "Would you like to add another? ";
    cin >> again;
    cin.ignore(100,'\n');
  }

  build.display();



  return 0;

}
