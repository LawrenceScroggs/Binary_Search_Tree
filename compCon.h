// This will hold all of the classes and prototypes 
// for the BST

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;


class bst{

  public:
    bst();
    ~bst();
    char * name;
    char * descrip;
    char * relation;

    int key;

    bst * left;
    bst * right;

  private: 

};
class compCon{

  public:
    compCon();
    ~compCon();
    int insert(bst * to_add); // used to insert info into bst
    int getKey(bst * to_add); // used to get numerical value for name
    int remove(bst * to_find); // used to find concept and remove
    int get_height(); // returns height of tree
    int display(); // displays entire tree

    void addNew(bst * to_add); // allows grader to manually add info 
    
    bool is_efficient(bst * root); // tests bst for efficiency



  private:

    int insert_p(bst *& root,bst * to_add); // recurses to end of bst and inserts new data
    int remove_p(bst *& root,bst * to_find); // recurses to desired data and deletes
    int get_height_p(bst * root); // recursively counts height
    int display_all(bst * root);

    bst * root;
    int count = 0;

};
