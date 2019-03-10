// This will implement all functions for BST build


#include "compCon.h"



// wrapper for display all 
int compCon::display(){

  int check = display_all(root);

  if(check == -1)
    cout << "End of Tree" << endl << endl;

}
// displays entire tree
int compCon::display_all(bst * root){

  if(!root) return -1;

  else
  {
    display_all(root->left);
    cout << "Name: " << root->name << endl;
    display_all(root->right);
  }
}
// for grader to use if they want to manually enter data
void compCon::addNew(bst * to_add){


  to_add->name = new char[100];
  cout << "Please enter the concept you are looking to add. ";
  cin.get(to_add->name,100);
  cin.ignore(100,'\n');
  to_add->key = getKey(to_add);

  insert(to_add);

  delete to_add->name;

  return;
}
// get key
int compCon::getKey(bst * to_add){

  int sum = 0;

  sum = to_add->name[0];


  return sum;

}
// wrapper insert
int compCon::insert(bst * to_add){

  insert_p(root,to_add);

}
// recursive function to add at end of bst
int compCon::insert_p(bst *& root,bst * to_add){


  if(!root)
  {
    root = new bst;
    root->name = new char[strlen(to_add->name)+1];
    strcpy(root->name,to_add->name);
    root->key = getKey(to_add);
    root->left=root->right=NULL;
    ++count;
    return count;
  
  else if(root->key > to_add->key)
    return insert_p(root->left,to_add);

  else
    return insert_p(root->right,to_add);

  return count;

}
bst::bst(){

  name = NULL;
  descrip = NULL;
  relation = NULL;

}
bst::~bst(){


}
compCon::compCon(){


  root = NULL;

}
compCon::~compCon(){



}
