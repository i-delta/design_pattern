/*
 * Strategy design pattern lab
 * Author: jia ya wei
 * Mail: ywjia@mail.ustc.edu.cn
 */

#include<iostream>
#include<string.h>
using namespace std;

class Validation
{
    public:
        virtual int validate( char* input ) = 0;
};
class Ntype : public Validation
{
    public:
        int validate(char *input)
        {
            int i, valid = 1;
            for(i = 0; i < strlen(input); i++)
            {
                if(!isdigit(input[i]))
                {
                    valid = 0;
                    break;
                }
            }
            return valid;
        }
};
class Utype : public Validation
{
    public:
        int validate(char *input)
        {
            int i, valid = 1;
            for(i = 0; i < strlen(input); i++)
            {
                if(!isupper(input[i]))
                {
                    valid = 0;
                    break;
                }
            }
            return valid;
        }
};
class Ltype : public Validation
{
    public:
        int validate(char *input)
        {
            int i, valid = 1;
            for(i = 0; i < strlen(input); i++)
            {
                if(!islower(input[i]))
                {
                    valid = 0;
                    break;
                }
            }
            return valid;
        }
};

class DataEntry 
{
    public:
         void setValidationType(char ch ) 
         {
            if(ch == 'n')
                v = new Ntype();
            else if(ch == 'u')
                v = new Utype();
            else 
                v = new Ltype();
         }
         void interact()
         {
            char  answer[20];
            cout << "Prompt: ";
            cin >> answer;
            while (strcmp( answer, "quit" ))
            {
                if (v ->validate( answer )) 
                    cout << "*** good ***" << endl;
                else       
                    cout << "*** bad ***" << endl;
          cout << "Prompt: ";
          cin >> answer;
       }
         }
    private:
         Validation *v;
};


    

int main( void ) 
{
     DataEntry  dialog;
     char       answer;

     cout << "Input type [ (n)umber, (u)pper, (l)ower, e(x)it ]: ";
     cin >> answer;
     while (answer != 'x')
     {
        dialog.setValidationType(answer);
        dialog.interact();
         cout << "Input type [ (n)umber, (u)pper, (l)ower, e(x)it ]: ";
        cin >> answer;
      }
     return 0;
}


