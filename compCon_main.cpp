// Lawrence Scroggs CS163 03/02/19
// This program will take computer science terms and put them into a binary
// search tree.  We will use a key to place the item into the binary search tree.


#include "compCon.h"


int main(){

  bst to_add,to_find;
  compCon build;

  int height = 0;

  bool efficient = false;

  char again = ' ';

  while(again != 'n')
  {
    build.addNew(&to_add);
    cout << "Would you like to add another? ";
    cin >> again;
    cin.ignore(100,'\n');
  }

  build.display();

  height = build.get_height();

  cout << "Height of tree: " << height << endl;

  build.remove(&to_find);

  build.display();

  efficient = build.efficient();

  if(efficient == true)
    cout << "Tree is efficient" << endl;
  else if(efficient != true)
    cout << "Tree is inefficient" << endl;

  build.display_range();


  return 0;

}
