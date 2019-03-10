// This will implement all functions for BST build


#include "compCon.h"



// wrapper function to remove
int compCon::remove(bst * to_find){

  int check = 0;

  to_find->name = new char[100];
  cout << "Please enter the concept you are looking to remove: ";
  cin.get(to_find->name,100);
  cin.ignore(100,'\n');
  to_find->key = getKey(to_find);

  check = remove_p(root,to_find);

  return check;

  delete to_find->name;
}
// remove function
int compCon::remove_p(bst *& root, bst * to_find){

  if(!root) return 0;

  if(root->key > to_find->key)
    return remove_p(root->left,to_find);

  else if(root->key < to_find->key)
    return remove_p(root->right,to_find);

  else //found a match
  {
    cout << "match" << endl;
    if(strcmp(root->name,to_find->name) == 0)
    {
      if(!root->left && !root->right) // at leaf
      {
        delete root;
        root = NULL;
      }
      else if(!root->left) // if left is null
      {
        cout << "test 1" << endl;
        bst * temp = root;
        root = root->right;
        delete temp;
      }
      else if(!root->right) // if right is null
      {
        cout << "test 2" << endl;
        
        bst * temp = root;
        root = root->left;
        delete temp;
      }
      else
      {
        if(!root->right->left)
        {
          cout << "test 3" << endl;
          bst * temp = root;
          bst * current = root->right;
          root = current;
          root->left = temp->left;

          delete temp;

          return 1;
        }
        else
        {
          bst * temp = root;
          bst * prev = root;
          bst * right = root->right;
          bst * current = root->left;
          while(current->left)
          {
            current = current->left;
            prev = prev->left;

          }
          prev->left = current->right;
          cout << "left: " << prev->left->name << endl;
          root = current;
          cout << "current: " << root->name << endl;
          root->left = prev;
          cout << "root left: " << root->left->name << endl;
          root->right = right;
          cout << "right: " << root->right->name << endl;

          delete temp;

          return 1;
        }
      }

    }
    else
      return remove_p(root->right,to_find); //if the key matchs but not the names
  }
}
// wrapper for get heigth p
int compCon::get_height(){

  int height = get_height_p(root);

  return height;
}
// recursive function to get the height of tree
int compCon::get_height_p(bst * root){

  if(!root) return 0;

  else
  {
    int left = get_height_p(root->left);
    int right = get_height_p(root->right);
    if(left > right)
      return left+1;
    else
      return right+1;
  }
}
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
  }
  
  else if(root->key > to_add->key)
  {
    cout << "left: " << endl;
    return insert_p(root->left,to_add);
  }

  else
  {
    cout << "right: " << endl;
    return insert_p(root->right,to_add);
  }

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
