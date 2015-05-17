typedef struct Node {
   int value;  Node* left;  Node* right;

   Node(); 
friend std::ostream& operator<< ( std::ostream &os, const Node &n )
{
    os << n.value;
    return os;
}
}Node;

class BST;
class Iterator
{
    public:
        Iterator(BST *b);

        void first();
        
        void next();
        int isDone();
        Node &currentItem();
    private:
        void buildList( Node* current ) ;

        BST *bst;
        Node **list;
        int nextNode;
};


class BST {
    friend Iterator;
private:
   Node*  root;
   int    size;
public:
   BST(); 
   Iterator createIterator();
   void add( int in ); 
   void traverse(); 
private:
   void add( int in, Node* current );
   void traverse( Node* current ) ;
};


