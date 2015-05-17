class Primitive;
class Link;
class Composite;

class Visitor
{
    public:
        virtual void visit(Primitive *) = 0;
        virtual void visit(Link *) = 0;
        virtual void visit(Composite* ) = 0; 
};


class Component {
public:

   virtual void accept(Visitor &v ) = 0;
   virtual void streamOut()        = 0;
   virtual void add( Component* ) { };
};

class Primitive : public Component {
public:
   Primitive( int id ) ;
   void accept(Visitor &v);
   void streamOut();
private:
   int identity;
};

class Link : public Component {
public:
   Link( Component& ele ) ; 
   void       streamOut(); 
   Component& getSubject();
   void accept(Visitor &v);
  
private:
   Component& linkElement;
};

class Composite : public Component {
public:
   Composite(); 
   void     add( Component* ele );
   void     streamOut();
   void accept(Visitor &v);
  
private:
   int         index;
   Component*  array[20];
};


class CatVisitor : public Visitor
{
    public:
        void visit(Primitive *);
        void visit(Composite *);
        void visit(Link *);
};

class WcVisitor : public Visitor
{
    public:
        void visit(Primitive *);
        void visit(Composite *);
        void visit(Link *);

};

