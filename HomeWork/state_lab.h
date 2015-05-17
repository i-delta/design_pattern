/*
 * State design pattern lab
 * Author: jia ya wei
 * StudentID: SA14011066
 * Mail: ywjia@mail.ustc.edu.cn
 */
class FSMstate;

class FSM
{
    public:
        FSM();
        void on();
        void off();
        void ack();
    private:
        friend class FSMstate;
        void changeState(FSMstate *state);
    private:
        FSMstate *_state;
        
};

class FSMstate
{
    public:
        virtual void on(FSM *fsm);
        virtual void off(FSM *fsm);
        virtual void ack(FSM *fsm);
    protected:
        void changeState(FSM *fsm, FSMstate *fsmstate);
};


class A : public FSMstate
{
    public:
        static FSMstate *instance();
        void on(FSM *fsm);
        void off(FSM *fsm);
        void ack(FSM *fsm);

    private:
        static FSMstate *_instance;
};

class B: public FSMstate
{
     public:
        static FSMstate *instance();
        void on(FSM *fsm);
        void off(FSM *fsm);
        void ack(FSM *fsm);
     private:
        static FSMstate *_instance;

};


class C: public FSMstate
{
     public:
        static FSMstate *instance();
        void on(FSM *fsm);
        void off(FSM *fsm);
        void ack(FSM *fsm);
     private:
        static FSMstate *_instance;

};
