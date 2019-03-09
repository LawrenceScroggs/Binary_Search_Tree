// This will implement all functions for BST build


#include "compCon.h"



// for grader to use if they want to manually enter data
void compCon::addNew(){

  bst * data;

  cout << "Please enter the concept you are looking to add. ";
  data->name = new char[100];
  cin.get(data->name,100);
  cin.ignore(100,'\n');

  insert(data);

  return;
}
// get key
int compCon::getKey(bst * to_add){

  int sum = 0;

  for(int i=0;i < strlen(to_add->name);++i)
    sum += to_add->name[i];


  return sum;

}
// wrapper insert
int compCon::insert(bst * to_add){


  insert_p(root,to_add);


}
// recursive function to add at end of bst
int compCon::insert_p(bst *& root,bst * to_add){

  int temp = getKey(to_add);

  if(!root)
  { 
    root = new bst;
    root->name = to_add->name;
    root->key = getKey(to_add);
    root->left=root->right=NULL;
    return 1;
  }
  else if(root->key > temp)
    insert_p(root->left,to_add);

  else if(root->key <= temp);
    insert_p(root->right,to_add);

    

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
