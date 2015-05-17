/*
 * Chain of Responsibility design pattern
 * Author: jia ya wei
 * StudentID: SA14011066
 * Mail: ywjia@mail.ustc.edu.cn
 */

#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;
class Slot
{

    public:
       Slot( int val , Slot *s = 0)
       {
           value_ = val;
           count_ = 0;
           successor = s;
       }
       void accept( int coin ) 
       {
           if (coin == value_)
           {
                count_++;
           }
           else 
               successor ->accept(coin);
       }
       int getCount()
       {
      
           return count_;
       }
       void report(const char *s)
       {
            cout << s << " - " << getCount() << endl;
       }
    private:
       int  value_;
       int  count_;
    public:
       Slot *successor;
};

class Quarter : public Slot 
{
    public:
       Quarter(Slot*s = 0) : Slot( 25, s ) { }

};

class Dime : public Slot 
{
    public:
       Dime(Slot *s = 0) : Slot( 10 ,s ) { }
};

class Nickel : public Slot 
{
    public:
       Nickel(Slot *s = 0) : Slot( 5 , s) { }
};

class Penny : public Slot 
{
    public:
       Penny(Slot *s = 0) : Slot( 1, s ) { }
};

int pickCoin()
{
   static int choices[4] = { 1, 5, 10, 25 };
   return choices[rand() % 4];
}

Slot *arraySet()
{
    Penny *p = new Penny();
    Nickel *n = new Nickel(p);
    Dime *d = new Dime(n);
    Quarter *q = new Quarter(d);

    return q;
}

int main( void )
{
   Slot*    slots = arraySet();
   int      i, coin, total;
   time_t   t;
   const char *Name[] = {"quarters", "dimes", "nickels", "pennies"};
   srand((unsigned) time(&t));

   for (i=0, total=0; i < 10; i++)
   {
      coin = pickCoin();
      cout << coin << " ";
      total += coin;
      slots->accept( coin );
   }
   cout << "\ntotal deposited is $" << total/100 << "."
      << (total%100 < 10 ? "0" : "") << total%100 << endl;
   int j = 0;
    while(slots )
    {
        slots ->report(Name[j++]);
        slots = slots -> successor;
    }
    return 0;
}
