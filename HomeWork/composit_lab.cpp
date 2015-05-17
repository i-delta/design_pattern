/*
 * Composite_lab design pattern 
 * Author: jia ya wei
 * StudentID: SA14011066
 * Mail: ywjia@mail.ustc.edu.cn
 */

#include<iostream>
using namespace std;

class Component
{
    public:
        Component(int val) : value(val){}
        virtual void traverse() = 0;
 
    protected:
        int value;
};

class Primitive : public Component 
{
    public:
        Primitive(int val):Component(val){}
        void traverse()
        {
            cout << value << " ";
        }

};

class Composite : public Component
{
    public:
        Composite(int val):Component(val)
        {
            total = 0;
        }
        void traverse()
        {
            cout << value << " ";
            for (int i=0; i < total; i++)
                children[i]->traverse();
        }
        void add(Component *c ) 
        {
            children[total++] = c;
        }

    private:
        int total;
        Component *children[99];
 
};

int main( void ) {
   Composite  first(1), second(2), third(3);

   first.add( &second );
   first.add( &third );
   first.add( new Primitive(4) );
   second.add( new Primitive(5) );
   second.add( new Primitive(6) );
   third.add(  new Primitive(7) );
   first.traverse();
   cout << endl;
   return 0;
}


