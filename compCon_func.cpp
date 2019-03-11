// This will implement all functions for BST build


#include "compCon.h"




// wrapper for display range
int compCon::display_range(){

  char var1 = ' ';
  char var2 = ' ';
  cout << "Please enter the range you are looking to display. ex.(a-m)" << endl;
  cout << "Enter first character: ";
  cin >> var1;
  cin.ignore(100,'\n');
  cout << "Enter second character: ";
  cin >> var2;
  cin.ignore(100,'\n');

  display_range_p(root,var1,var2);

}
int compCon::display_range_p(bst * root,char var1,char var2){

  if(!root) return 0;


  else
  {
    if(root->name[0] >= var1 && root->name[0] <= var2)
    {
      display_range_p(root->left,var1,var2);
      cout << "Name: " << root->name << endl;
      cout << "Description: " << root->descrip << endl;
      cout << "Relationship: " << root->relation << endl << endl;
      display_range_p(root->right,var1,var2);
    }
    else
    {
      display_range_p(root->left,var1,var2);
      display_range_p(root->right,var1,var2);
    }
  }
}
// wrapper for is_efficient
bool compCon::efficient(){

  bool check = is_efficient(root);

  return check;
}
// function to check efficiency
bool compCon::is_efficient(bst * root){

  if(!root) return false;

  sum = 0;

  int height = get_height();


  int countNodes = count_nodes(root);
  if(sum < -1 || sum > 1)
    return false;

  else
  {
    int efficient = (pow(2,(height - 1)) - 1);
    if(countNodes > efficient)
      return true;
    else
      return false;
  }


}
// counts nodes to measure efficiency
int compCon::count_nodes(bst * root){
  
  if(!root) return 0;

  return(count_nodes(root->left) + count_nodes(root->right) + 1);
}
// wrapper function to remove
int compCon::remove(bst * to_find){

  int check = 0;

  to_find->name = new char[100];
  cout << "Please enter the concept you are looking to remove: ";
  cin.get(to_find->name,100);
  cin.ignore(100,'\n');
  to_find->key = getKey(to_find);

  check = remove_p(root,to_find);

  if(check == 0)
    cout << "No match found" << endl << endl;

  else
    cout << "Removed succesfully" << endl << endl;

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
    if(strcmp(root->name,to_find->name) == 0)
    {
      if(!root->left && !root->right) // at leaf
      {
        delete root;
        root = NULL;
        return 1;
      }
      else if(!root->left) // if left is null
      {
        bst * temp = root;
        root = root->right;
        delete temp;

        return 1;
      }
      else if(!root->right) // if right is null
      {
        bst * temp = root;
        root = root->left;
        delete temp;

        return 1;
      }
      else // if match has to children
      {
        if(!root->right->left)
        {
          bst * temp = root;
          bst * current = root->right;
          root = current;
          root->left = temp->left;

          delete temp;

          return 1;
        }
        else
        {
          bst * prev = root;
          bst * current = root->right;
          while(current->left)
          {
            prev = current;
            current = current->left;
          }
          root->name = current->name;
          prev->left = current->right;

          delete current;

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

  int height = get_height_p(root,sum);

  return height;
}
// recursive function to get the height of tree
int compCon::get_height_p(bst * root,int & sum){

  if(!root) return 0;

  else
  {
    int left = get_height_p(root->left,sum);
    int right = get_height_p(root->right,sum);
    if(left > right)
    {
      sum = ((left +1) - (right+1)); // used for balance efficiency
      return left+1;
    }
    else
    {
      sum = ((left +1) - (right+1)); 
      return right+1;
    }

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
    cout << "Description: " << root->descrip << endl;
    cout << "Relationship: " << root->relation << endl << endl;
    display_all(root->right);
  }
}
// for grader to use if they want to manually enter data
void compCon::addNew(bst * to_add){


  to_add->name = new char[100];
  cout << "Please enter the computer science concept/term you are looking to add: ";
  cin.get(to_add->name,100);
  cin.ignore(100,'\n');
  to_add->descrip = new char[500];
  cout << "Please enter the description of concept/term: ";
  cin.get(to_add->descrip,500);
  cin.ignore(500,'\n');
  to_add->relation = new char[100];
  cout << "Please enter the data structure it is related to: ";
  cin.get(to_add->relation,100);
  cin.ignore(100,'\n');
  to_add->key = getKey(to_add);

  insert(to_add);

  delete to_add->name;
  delete to_add->descrip;
  delete to_add->relation;

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
    root->descrip = new char[strlen(to_add->descrip)+1];
    strcpy(root->descrip,to_add->descrip);
    root->relation = new char[strlen(to_add->relation)+1];
    strcpy(root->relation,to_add->relation);
    root->key = getKey(to_add);
    root->left=root->right=NULL;
    ++count;
    return count;
  }
  
  else if(root->key > to_add->key)
  {
    return insert_p(root->left,to_add);
  }

  else
  {
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

  delete name;
  delete descrip;
  delete relation;

}
compCon::compCon(){

  root = NULL;

}
compCon::~compCon(){



}
