// This will hold all of the classes and prototypes 
// for the BST

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;


class bst(){

  public:
    bst();
    ~bst();
    char * name;
    char * descrip;
    char * relation;

    bst * left;
    bst * right;

  private: 

};
class compCon(){

  public:
    compCon();
    ~compCon();
    int insert();
    int remove();
    int get_height();
    
    bool is_efficient();



  private:

    bst * root;

};
