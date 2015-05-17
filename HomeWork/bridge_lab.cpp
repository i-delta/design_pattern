#include<iostream>

using namespace std;


enum ImplementationType { ArrayImplementation, ListImplementation };


class StackImp
{
    public:
        virtual void push(int val) = 0;
        virtual int pop() = 0;
        virtual int isEmpty() = 0;
        virtual int isFull() = 0;
};

class ArrayImp : public StackImp{
public:
   ArrayImp( int size = 10 );
   ~ArrayImp();
   void push( int val );
   int  pop();
   int  isEmpty();
   int  isFull();
private:
   int* _array;
   int  _sp;
   int  _size;
};

class Node {
public:
   Node( int val, Node* next );
   int getValue();
   Node* getNext();
private:
   int    _value; 
   Node*  _next;
};

class ListImp : public StackImp{
public:
    ListImp();
    ~ListImp();
    void push( int val );
    int  pop();
    int  isEmpty();
    int  isFull();
private:
    Node* _head;
};

class Stack
{
    public:

        Stack(int size);
        Stack()
        {
            _stackimp = new ArrayImp;
        }
        Stack(ImplementationType type)
        {
            if(type == ArrayImplementation)
                _stackimp = new ArrayImp;
            else 
                _stackimp = new ListImp;

        }
        ~Stack()
        {
            delete _stackimp;
            _stackimp = NULL;
        }
        void push(int val)
        {
            _stackimp ->push(val);
        }
         int pop() 
         {
             return _stackimp ->pop();
         }
        int isEmpty() 
        {
            return _stackimp ->isEmpty();
        }

        int isFull() 
        {
            return _stackimp ->isFull();
        }

    private:
        StackImp *_stackimp;

};
int main ( void ) {
   Stack stack1;
   Stack stack2( ListImplementation );

   int i;
   for (i=1; i < 16; i++) {
      stack1.push( i );
      stack2.push( i );
   }

   cout << "Array stack: ";
   for (i=1; i < 18 ; i++)
      cout << stack1.pop() << "  ";
   cout << endl;

    cout << "List stack:  ";
    for (i=1; i < 18 ; i++)
       cout << stack2.pop() << "  ";
    cout << endl;
    return 0;
}

// Array stack: 10  9  8  7  6  5  4  3  2  1  0  0  0  0  0  0  0  
// List stack:  15  14  13  12  11  10  9  8  7  6  5  4  3  2  1  0  0  


ArrayImp::ArrayImp( int size ) {
   _array = new int[size];
   _size = size;
   _sp = 0; }
ArrayImp::~ArrayImp() { delete _array; }
void ArrayImp::push( int val ) {
   if ( ! isFull())
      _array[_sp++] = val; }
int ArrayImp::pop() {
   if (isEmpty()) return 0;
   else return _array[--_sp]; }
int ArrayImp::isEmpty() { return _sp == 0 ? 1 : 0; }
int ArrayImp::isFull()  { return _sp == _size ? 1 : 0; }

Node::Node( int val, Node* next ) {
   _value = val;
   _next = next; }
int   Node::getValue() { return _value; }
Node* Node::getNext()  { return _next; }

ListImp::ListImp() { _head = NULL; }
ListImp::~ListImp() {
   Node  *current, *previous;
   current = _head;
   while (current) {
      previous = current;
      current = current->getNext();
      delete previous; }
}
void ListImp::push( int val ) {
   Node*  temp = new Node( val, _head );
   _head = temp; }
int ListImp::pop() {
   if (isEmpty()) return 0;
   Node*  temp = _head;
   int    val  = _head->getValue();
   _head = _head->getNext();
   delete temp;
   return val; }
int ListImp::isEmpty() { return _head ? 0 : 1; }
int ListImp::isFull()  { return 0; }
