/*
 * Author: jia ya wei
 * StudentID: SA14011066
 * Mail: ywjia@mail.ustc.edu.cn
 */

#include<iostream>
using namespace std;

struct StackStruct {
   int*  array;
   int   sp;
   int   size;
};
typedef StackStruct Stack;

static void initialize( Stack* s, int size ) {
   s->array = new int[size];
   s->size = size;
   s->sp = 0; }
static void cleanUp( Stack* s ) {
   delete s->array; }
static int isEmpty( Stack* s ) {
   return s->sp == 0 ? 1 : 0; }
static int isFull( Stack* s ) {
   return s->sp == s->size ? 1 : 0; }
static void push( Stack* s, int item ) {
   if ( ! isFull(s)) s->array[s->sp++] = item; }
static int pop( Stack* s ) {
   if (isEmpty(s)) return 0;
   else            return s->array[--s->sp]; }

class Queue
{
    public:
        Queue(int size)
        {
            ::initialize(&q, size);
        }
        void enque(int item)
        {
            if(::isFull(&q))
            {
                int i;
                Stack s ;
                ::initialize(&s, (q.size)*2);
                for(i = 0; i < q.size; i++)
                    ::push(&s, q.array[i]);
                ::cleanUp(&q);
                q = s;
            }
            push(&q, item);
        }
        int deque()
        {
            if(::isEmpty(&q))
                return -1;
            Stack tempStack ;
            initialize(&tempStack, q.size);
            int t, r ;
            while(!::isEmpty(&q))
            {
                t = pop(&q);
                push(&tempStack, t);
            }
            if(!::isEmpty(&tempStack))
                r = pop(&tempStack);
            while(!::isEmpty(&tempStack))
            {
                t = pop(&tempStack);
                push(&q, t);
            }
            cleanUp(&tempStack);
            return r;
        }
        int isEmpty()
        {
            return ::isEmpty(&q);

        }
        ~Queue()
        {
            cleanUp(&q);
        }

    private:
        Stack q;
};
int main( int argc, char **argv ) {
   Queue  queue(15);

   for (int i=0; i < 25; i++) queue.enque( i );
   while ( ! queue.isEmpty()) cout << queue.deque() << " ";
   cout << endl;
   return 0;
}


