/*
 * State design pattern lab
 * Author: jia ya wei
 * StudentID: SA14011066
 * Mail: ywjia@mail.ustc.edu.cn
 */
#include<iostream>
#include"state_lab.h"

using namespace std;

void FSM::on()
{
    _state -> on(this);
}

void FSM::off()
{
    _state -> off(this);
}
void FSM::ack()
{
    _state -> ack(this);
}

void FSM::changeState(FSMstate *state)
{
    _state = state;
}

FSM::FSM()
{
    _state = B::instance();
}

/*************FSMstate ***********/
void FSMstate::changeState(FSM *fsm, FSMstate *fsmstate)
{
    fsm->changeState(fsmstate);
}

void FSMstate::on(FSM *fsm)
{
    cout << "undefined combo" << endl;
}

void FSMstate::off(FSM *fsm)
{
    cout << "undefined combo" << endl;
}
void FSMstate::ack(FSM *fsm)
{
    cout << "undefined combo" << endl;
}

/* subclass of FSMstate */

FSMstate* A::_instance = NULL;
void A::on(FSM *fsm)
{
    cout << "A, on ==> A" << endl;
}

void A::off(FSM *fsm)
{
    cout << "A, off ==> B" << endl;
    changeState(fsm, B::instance());
}

void A::ack(FSM *fsm)
{
    cout << "A, ack ==> C" << endl;
    changeState(fsm, C::instance());
}

FSMstate* A::instance()
{
    if(_instance == NULL)
        _instance = new A();
    return _instance;
}


FSMstate* B::_instance = NULL;
void B::on(FSM *fsm)
{
    cout << "undefined combo" << endl;
}

void B::off(FSM *fsm)
{
    cout << "B, off ==> A" << endl;
    changeState(fsm, A::instance());
}

void B::ack(FSM *fsm)
{
    cout << "B, ack ==> C" << endl;
    changeState(fsm, C::instance());
}

FSMstate* B::instance()
{
    if(_instance == NULL)
        _instance = new B();
    return _instance;
}


FSMstate* C::_instance = NULL;
void C::on(FSM *fsm)
{
    cout << "undefined combo" << endl;
}

void C::off(FSM *fsm)
{
    cout << "undefined combo" << endl;
}

void C::ack(FSM *fsm)
{
    cout << "C, ack ==> B" << endl;
    changeState(fsm, B::instance());
}

FSMstate* C::instance()
{
    if(_instance == NULL)
        _instance = new C();
    return _instance;
}

int main(int argc, char **argv)
{
    FSM fsm;
    enum Message { on, off, ack };

    Message messageArray[10] = { on,off,off,ack,ack,ack,ack,on,off,off };
    
    for(int i = 0; i < 10; i++)
    {
        if(messageArray[i] == on)
            fsm.on();
        else if(messageArray[i] == off)
            fsm.off();
        else
            fsm.ack();
    }
    return 0;
}
