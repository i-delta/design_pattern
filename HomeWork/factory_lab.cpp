/*
 * Author: jia ya wei
 * mail: ywjia@mail.ustc.edu.cn
 * StudentID: SA14011066
 */

#include<iostream>
using namespace std;

class Factory
{
    public:
        virtual void createSocket() = 0;
        virtual void createPipe() = 0;
        virtual void createThread() = 0;

};


class UnixFactory : public Factory
{
    public:
        void createSocket()  { cout << "createUnixSocket:" << endl; }
        void createPipe()    { cout << "createUnixPipe:" << endl; }

        void createThread()  { cout << "createUnixThread:" << endl; }
};

class VmsFactory : public Factory
{
    public:

        void createSocket()   { cout << "createVmsSocket:" << endl; }
        void createPipe()     { cout << "createVmsPipe:" << endl; }
        void createThread()   { cout << "createVmsThread:" << endl; }
};

class NtFactory : public Factory 
{
    public:

        void createSocket()    { cout << "createNtSocket:" << endl; }
        void createThread()   { cout << "createVmsThread:" << endl; }
        void createPipe()      { cout << "createNtPipe:" << endl; }
};



int main(int argc, char **argv)
{
    Factory *factory = NULL;
#ifdef UNIX
    factory = new(UnixFactory);
#elif VMS
    factory = new(VmsFactory);
#elif NT
    factory = new(NtFactory);
#endif

    factory->createPipe();
    factory->createSocket();
    factory->createThread();
    cout << "main: complete\n";
    delete factory;
    return 0;
}
