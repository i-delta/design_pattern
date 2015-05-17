/*
 * Visitor design pattern lab
 * Author: jia ya wei
 * StudentID: SA14011066
 * Mail: ywjia@mail.ustc.edu.cn
 */

#include<iostream>
#include"visitor_lab.h"
using namespace std;


Primitive::Primitive( int id ) 
   {
       identity = id;
   }
void Primitive::accept(Visitor &v)
   {
       v.visit(this);
   }
void Primitive::streamOut()
   {
       cout << identity << " "; 
   }

Link::Link( Component& ele ) : linkElement(ele)  { }
void Link::streamOut() 
{
    linkElement.streamOut();
}
Component &Link:: getSubject() 
{
    return linkElement; 
}

void Link::accept(Visitor &v)
{

    v.visit(this);
}



Composite:: Composite()
{
    index = 0;
}
void Composite:: add( Component* ele )
{
    array[index++] = ele;
}
void Composite::streamOut() 
{
    for (int i=0; i < index; i++)
         array[i]->streamOut();
}
void Composite::accept(Visitor &v)
   {
       v.visit(this);
   }
  


void CatVisitor::visit(Primitive *node)
        {

             cout << "cat: ";  
             node->streamOut();
             cout << endl;
        }

void CatVisitor::visit(Composite *node)
 {
        cout << "cat: Can't cat a directory." << endl;
 }
void CatVisitor::visit(Link *node)

        {
            CatVisitor cat;
            (node->getSubject()).accept(cat);

        }
void WcVisitor::visit(Primitive *node)
        {

             cout << "wc: ";  
             node->streamOut();
             cout << endl;
        }

void WcVisitor::visit(Composite *node)
        {
             cout << "wc: Can't wc a directory." << endl;
        }
void WcVisitor:: visit(Link *node)
        {
            WcVisitor wcObject;
            //WcVisitor::visit(&(((Link*)node)->getSubject()));
            (node->getSubject()).accept(wcObject);
            
        }
int main( void ) {
   Composite        dir;
   Primitive        file1(1), file2(2);
   Link             alias( file1 );
   Component*       array[4];
   WcVisitor wcObject;
   CatVisitor catObject;
   dir.add( &file1 );
   dir.add( &file2 );
   dir.add( &alias );
   dir.streamOut();
   cout << endl;

   array[0] = &dir;
   array[1] = &file1;
   array[2] = &file2;
   array[3] = &alias;
   for (int i = 0; i < 4; i++) {
       array[i] ->accept(wcObject);
       array[i] ->accept(catObject);
    } 
   return 0;
}



