// Purpose.  Abstract Factory design pattern lab.
// 
// Problem.  #ifdef case statements are spread throughout the code to
// accomodate 3 different porting targets.  This makes maintenance
// difficult, and porting to a 4th platform onerous.
// 
// Assignment.
// o Create an abstract base class Factory.
// o Define pure virtual member functions createSocket(), createPipe(),
//   and createThread().
// o Subclass UnixFactory, VmsFactory, and NtFactory off of Factory.
// o Refactor the "create" free functions to be member functions of one of
//   the Factory derived classes.
// o Declare a Factory* pointer local to main().
// o Use a single #ifdef case statement in main() to instantiate the desired
//   Factory derived class.
// o Do not optimize-out the doOneLaneIPC(), doTwoLaneIPC(), and
//   doParallelProcessing() free functions.
// o Pass the Factory pointer to each of these free functions so that they
//   can create sockets, pipes, and threads without regard to race, creed,
//   or platform.
// o Supply the desired "compiler directive" at compile time.
// o Extra credit: implement the Factory class as a Singleton.

#include <iostream.h>

void createUnixSocket()  { cout << "createUnixSocket:" << endl; }
void createVmsSocket()   { cout << "createVmsSocket:" << endl; }
void createNtSocket()    { cout << "createNtSocket:" << endl; }
void createUnixPipe()    { cout << "createUnixPipe:" << endl; }
void createVmsPipe()     { cout << "createVmsPipe:" << endl; }
void createNtPipe()      { cout << "createNtPipe:" << endl; }
void createUnixThread()  { cout << "createUnixThread:" << endl; }
void createVmsThread()   { cout << "createVmsThread:" << endl; }
void createNtThread()    { cout << "createNtThread:" << endl; }

void doOneLaneIPC() {
#ifdef UNIX
   createUnixSocket();
#elif VMS
   createVmsSocket();
#elif NT
   createNtSocket();
#endif
}

void doTwoLaneIPC() {
#ifdef UNIX
   createUnixPipe();
#elif VMS
   createVmsPipe();
#elif NT
   createNtPipe();
#endif
}

void doParallelProcessing() {
#ifdef UNIX
   createUnixThread();
#elif VMS
   createVmsThread();
#elif NT
   createNtThread();
#endif
}


void main( void ) {
   doOneLaneIPC();
   doTwoLaneIPC();
   doParallelProcessing();
   cout << "main: complete" << endl;
}

// -- current output --
// createVmsSocket:
// createVmsPipe:
// createVmsThread:
// main: complete

// -- target output --
// VmsFactory: createSocket
// VmsFactory: createPipe
// VmsFactory: createThread
// main: complete
