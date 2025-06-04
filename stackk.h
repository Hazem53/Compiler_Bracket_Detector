#ifndef STACKK_H_INCLUDED
#define STACKK_H_INCLUDED
#include <iostream>
#include <string.h>

using namespace std;



#define max_size 50
template<class t>
class STACK
{
private:
    t arr[max_size];
    signed int  sp_top;

public:

    STACK()
    {
        sp_top=-1;
    }
    ///////////////////////////////////

    bool is_full()
    {
        if(sp_top== (max_size-1) )
            return true;

        else
            return false;


    }
    ///////////////////////////////////////
    bool is_emptyy()
    {
        if(sp_top==-1)
        {
            return true;
        }

        else
            return false;
    }
    //////////////////////////////////////


    ///////////////////////////////

    void push(signed int x)
    {
        if(is_full())
        {
            cout<<"stack is full "<<endl;
        }
        else
        {
            arr[++sp_top]=x;
        }

    }
    /////////////////////////////////////////
    char  pop()
    {
        if(is_emptyy())
        {
            cout<<"stack is already empty " <<endl;
        }
        else
        {

        }
                    return arr[sp_top--];

    }
    /////////////////////////////
    void show_all_elements()
    {
        for(int i= sp_top ; i>=0; i-- )
        {
            cout<< arr[i] <<endl;
        }


    }
    ////////////////////////////////////
    t show_top ()
    {
        return arr[sp_top];
    }


};


#endif // STACKK_H_INCLUDED
