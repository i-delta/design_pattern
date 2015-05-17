/*
 * Iterator design pattern lab
 * Author: jia ya wei
 * StudentID: SA1411066
 * Mail:ywjia@mail.ustc.edu.cn
 */

#include<iostream>
#include<sys/time.h>
#include<stdlib.h>
#include"iterator_lab.h"
using namespace std;

Node:: Node() { left = right = 0; }

BST::BST() {
      root = 0;
   }
  
Iterator BST::createIterator()
   {
       BST* bst = new BST;
       return Iterator(bst); 
   }
   void  BST::add( int in ) {
      if (root == 0) {
         root = new Node;
         root->value = in;
         size = 1;
         return;
      }
      add( in, root );
   }
void BST:: traverse() { BST::traverse( root ); }
   void BST::add( int in, Node* current ) {
      if (in < current->value)
         if (current->left == 0) {
            current->left = new Node();
            current->left->value = in;
            size++;
         }
         else BST::add( in, current->left );
      else
         if (current->right == 0) {
            current->right = new Node();
            current->right->value = in;
            size++;
         }
         else BST::add( in, current->right );
   }
   void BST::traverse( Node* current ) {
      if (current->left != 0) BST::traverse( current->left );
      cout << current->value << "  ";
      if (current->right != 0) BST::traverse( current->right );
   }

Iterator::Iterator(BST *b)
        { 
            bst = b;
            list = NULL;
        }

        void Iterator::first()
        {
            if(list)
            {
                delete list;
                list = NULL;
            }
            nextNode = 0;
            list = new Node* [bst->size];
            Iterator::buildList(bst->root);
            nextNode = 0;
        }
        void Iterator::next()
        {
            nextNode++;
        }
        int Iterator::isDone()
        {
            if (nextNode == bst->size)
            {
                delete list;
                list = NULL;
                return 0;
            }
            return -1;
        }
        Node &Iterator::currentItem()
        {
            return *list[nextNode];
        }
void Iterator::buildList( Node* current ) 
        {

             if (current->left != 0)
                 buildList( current->left );
             list[nextNode++] = current;
             if (current->right != 0)
                 buildList( current->right );
        }



int main( void ) 
{
   BST  bst;
   time_t  t;
   srand((unsigned) time(&t));

   cout << "original:  ";
   for (int i=0, val; i < 15; i++) {
      val = rand() % 49 + 1;
      cout << val << "  ";
      bst.add( val );
   }
   cout << "\ntraverse:  ";
   bst.traverse();
   cout << endl;
   cout << "Iterator:  ";
   Iterator I(&bst);
   for( I.first(); I.isDone(); I.next())
   {
       Node x = I.currentItem();
       cout << x.value << "  " ; 
   }
   cout << endl;
   cout << "Iterator:  ";
   for( I.first(); I.isDone(); I.next())
   {
       cout << (I.currentItem()) << "  " ; 
   }
   cout << endl;
   return 0;
}


