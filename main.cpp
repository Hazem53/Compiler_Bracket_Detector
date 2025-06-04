#include <iostream>
#include <string.h>
#include "stackk.h"
using namespace std;
/**********************************************
@author__ -> HAZEM MOHAMED HAMDY , HAMDY AYMAN HAMDY , SARA SROUR AHMED , AHMED BADR
@ PROJECT ABOUT  ({BRACKET DETECTOR}) MISSING LINE NUMBER X using stack ,
@ THIS CODE WILL DETECT THE ERROR BRACKET BY BRACKET UNTILL SOLVING ALL OF THEM WITH THE RETURNING OF THE LINE NUMBER OF THE ERROR
@date___ 2/5/2024
***********************************************************/


/***************FUNCTION DECLERATION **********************/
unsigned int  enter_code(string exp);
/**********************************************************/

//HAMDY
/**make an object with char data type**/
STACK <char>s;

int main()
{

    while(1)
    {
        int h=0;
        string userInput; // will save the line by line
        string allText;// will save all the lines as a one code "text"

        string terminator = "done"; // User enters this to signal they're done

        cout << "Enter your code (type 'done' on a new line to finish):\n";

        // Keep reading lines until the terminator is entered
        while (true)
        {
            getline(cin, userInput);
            if (userInput == terminator)
            {
                break; // Exit the loop if the terminator is entered
            }
            allText += userInput + "\n"; //+ to Concatenate the line to the existing text
        }
        /*
        allText: This is likely a string variable that already contains some text.
        +=: This operator adds the value on the right-hand side to the value on the left-hand side, and then assigns the result to the variable on the left-hand side.
        userInput: This is likely another string variable that holds some text input by the user.
        +: This is the concatenation operator for strings. When used between two strings, it concatenates them, meaning it joins them end-to-end.
        */
        cout << "You entered:\n" << allText;

        h=enter_code(allText);
        cout<<h<<endl;

    }
    return 0;
}

/*************FUNCTION DEFENITION*******************/
//SARA
unsigned int enter_code(string exp )
{

    unsigned int line_number=0;
    //////////////////////
    unsigned int i=0;
    for(i=0; i<exp.length(); i++)
    {
        if(exp[i]==';' ||exp[i]=='{' ||exp[i]=='}')
        {
            line_number=line_number+1;
        }
        else
        {
            if(exp[i]=='v'&&exp[i+1]=='o'&&exp[i+2]=='i'&&exp[i+3]=='d')
            {
                line_number=line_number+1;

            }
            else if(exp[i]=='f'&&exp[i+1]=='o'&&exp[i+2]=='r')
            {

                line_number=line_number+1;
                // this to solve this problem while or for ..etc  while x< 100 without opened or closed bracket
                int f1=0;
                unsigned int j;
                for(j=3+i;j<=exp.length();j++)
                {


                if(exp[j]=='(')
                {
                 f1=1;
                }


                }
                if (f1==0)
                {
                cout<<"missed bracket line number"<<line_number<<endl;
                return 0;
                }

            }
            else if(exp[i]=='e'&&exp[i+1]=='l'&&exp[i+2]=='s'&&exp[i+3]=='e')
            {
                line_number=line_number+1;

            }
            else if(exp[i]=='i'&&exp[i+1]=='f')
            {
                line_number=line_number+1;

                int f2=0;
                unsigned int j;
                for(j=2+i;j<=exp.length();j++)
                {


                if(exp[j]=='(')
                {
                 f2=1;
                }


                }
                if (f2==0)
                {
                cout<<"missed bracket line number"<<line_number<<endl;
                return 0;
                }
            }


            else if(exp[i]=='w'&&exp[i+1]=='h'&&exp[i+2]=='i'&&exp[i+3]=='l'&&exp[i+4]=='e')
            {
                                line_number=line_number+1;

                int f=0;
                unsigned int j;
                for(j=5+i;j<=exp.length();j++)
                {


                if(exp[j]=='(')
                {
                 f=1;
                }


                }
                if (f==0)
                {
                cout<<"missed bracket line number"<<line_number<<endl;
                return 0;
                }

            }

            else {}
        }
        /////////////////
        //HAZEM
        ///////////////
        if(exp[i]=='{'||exp[i]=='('||exp[i]=='[')
        {
            s.push(exp[i]);

            s.push(line_number);

        }
        else if(exp[i]=='}'||exp[i]==')'||exp[i]==']')
        {
            if(s.is_emptyy())
            {
                cout<<"MISSING BRACKET ,LINE NUMBER = " << line_number<<endl;

               return 0;
            }
            else
            {
                s.pop();
                s.pop();
            }

        }


    } ////end of the main for

    ///HAMDY

    if(s.is_emptyy() )
    {

        cout<<"NO ERRORS_YOUR CODE IS BALANCED"<<endl;
        int h=0;
        return h;
    }

    else
    {

        cout<<"ERROR MISSING BRACKET "<<endl;
        cout<<"line number"<<endl;



        int h=s.pop(); //THE POPED VALUE IS THE LINE NUMBER NOT BRACKET
                      //IT DETECTS LINE BY LINE UNTILL SOLVING IT
        return h;
    }


}
