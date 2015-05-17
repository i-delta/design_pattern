/*
 * Author: jia ya wei
 * StudentID: SA14011066
 * Mail: ywjia@mail.ustc.edu.cn
 */

#include<iostream>
#include<string.h>
using namespace std;
class FederalFraudvillian
{
    public:
        FederalFraudvillian( const char* pp = "Democrat" )
        { 
           strcpy( party, pp );
        }
        virtual void partyLine() = 0;
    protected:
        char party[20];
};

class President : public FederalFraudvillian 
{
    public:
        President(const char *pp):FederalFraudvillian(pp)
        { 
        }
        void partyLine() { cout << party << ": speak no evil" << endl; }
};

class AttorneyGeneral : public FederalFraudvillian 
{
    public:
        AttorneyGeneral(const char *pp):FederalFraudvillian(pp){}
        void partyLine() { cout << party << ": see no evil" << endl; }
};

class MinorityPartyCongressPerson : public FederalFraudvillian {
    public:
        MinorityPartyCongressPerson(const char *pp): FederalFraudvillian(pp){}
        void partyLine() { cout << party << ": hear no evil" << endl; }
};

class Factory 
{
    public:
        virtual FederalFraudvillian *createPresident(int arg) = 0;

};

class DemocratFactory : public Factory
{
    public:
        FederalFraudvillian *createPresident(int arg)
        {
            if(arg == 1)
            {
                return new President("Democrat");
            }else if(arg == 2)
                return new AttorneyGeneral("Democrat");
            else
                return new MinorityPartyCongressPerson("Democrat");
        }
};

class RepublicanFactory : public Factory
{
    public:
        FederalFraudvillian *createPresident(int arg)
        {
            if(arg == 1)
            {
                return new President("Republican");
            }else if(arg == 2)
                return new AttorneyGeneral("Republican");
            else
                return new MinorityPartyCongressPerson("Republican");
        }
};


int main(int argc, char **argv)
{
#ifdef DEMOCRAT
    Factory *factory = new DemocratFactory;
#else
    Factory *factory = new RepublicanFactory;
#endif
    FederalFraudvillian  *moralMisfits[10];
    int in, i, total = 0;

   cout << "President(1) AG(2) MPCP(3) Go(0): ";
   cin >> in;
   while (in) {
       moralMisfits[total++] = factory ->createPresident(in); 
       cout << "President(1) AG(2) MPCP(3) Go(0): ";
       cin >> in;
   }
   for (i=0; i < total; i++) moralMisfits[i]->partyLine();
   for (i=0; i < total; i++) delete moralMisfits[i];
   return 0;
}
