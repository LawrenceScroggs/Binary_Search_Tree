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
//recursively displays range
int compCon::display_range_p(bst * root,char var1,char var2){

  if(!root) return 0;


  else
  {
    if(root->name[0] >= var1 && root->name[0] <= var2) // if in range
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
  if(sum < -1 || sum > 1) // if the balance of tree is within -1 and 1
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

  delete [] to_find->name;
  to_find->name = NULL;

  return check;

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
          bst * current = root;
          current = current->right;
          while(current->left)
          {
            prev = current;
            current = current->left;
          }
          root->name = new char[strlen(current->name) + 1];
          strcpy(root->name,current->name);
          root->descrip = new char[strlen(current->descrip)+1];
          strcpy(root->descrip,current->descrip);
          root->relation = new char[strlen(current->relation)+1];
          strcpy(root->relation,current->relation);
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

  delete [] to_add->name;
  to_add->name = NULL;
  delete [] to_add->descrip;
  to_add->descrip = NULL;
  delete [] to_add->relation;
  to_add->relation = NULL;

  return;
}
// get key
int compCon::getKey(bst * to_add){

  int key = 0;

  key = to_add->name[0];


  return key;

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
    delete [] to_add->name;
    to_add->name = NULL;
    delete [] to_add->relation;
    to_add->relation = NULL;
    delete [] to_add->descrip;
    to_add->descrip = NULL;


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

  left = NULL;
  right = NULL;

}
bst::~bst(){

  delete [] name;
  delete [] descrip;
  delete [] relation;

}
compCon::compCon(bst to_add,bst to_find){

  root = NULL;

  file_in(to_add);

}
compCon::~compCon(){

  delete_all(root);

}
// delete for destructor
int compCon::delete_all(bst *& root){

  int value = 0;
  if(!root){
  
    return 0;
  }
  value = delete_all(root->left) + delete_all(root->right);
  delete [] root->name;
  root->name = NULL;
  delete [] root->descrip;
  root->descrip = NULL;
  delete [] root->relation;
  root->relation = NULL;
  delete root;
  root = NULL;
  delete to_add;
  delete to_find;
}
//reads from file
int compCon::file_in(bst to_add){
 
  ifstream file_in;
  file_in.open("BST.txt");

  if(file_in){

    if(file_in.peek() == -1) return -1;

    while(file_in && !file_in.eof()){

      if(file_in.peek() == -1){
        
        file_in.clear();
        file_in.close();
        return -1;
      }

      to_add.name = new char[100];
      file_in.get(to_add.name,100,'@');
      file_in.ignore(100,'@');
      to_add.descrip = new char[500];
      file_in.get(to_add.descrip,500,'@');
      file_in.ignore(500,'@');
      to_add.relation = new char[100];
      file_in.get(to_add.relation,100,'\n');
      file_in.ignore(100,'\n');
      to_add.key = getKey(&to_add);

      insert(&to_add);

      delete to_add.name;
      to_add.name = NULL;
      delete to_add.relation;
      to_add.relation = NULL;
      delete to_add.descrip;
      to_add.descrip = NULL;
    }
  }
  file_in.clear();
  file_in.close();
}
