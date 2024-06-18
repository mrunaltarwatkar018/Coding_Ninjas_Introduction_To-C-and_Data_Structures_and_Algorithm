#include <vector>
using namespace std;
template <typename T>

class TreeNode {

    public :
    T data;
    vector <TreeNode<T> *> children;

    TreeNode( T data ) {
        this -> data = data;
    }

    // destructor : for deleting the Tree which is dynamically created 
    ~TreeNode() {
        for ( int i < children.size(); i++ ) {
            delete children[i];
        }
    }
};
