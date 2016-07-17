/* 
*  Find if a mathematical expression is valid or not.
* Author : Raman Pandey
* Date : 07/07/2016
* Ref : Data Structure using c and c++, chapter 2 , page 82
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAXITEMS 100

typedef struct{
	int top;
	char items[MAXITEMS];
}stack;

void push(stack *, char);
int pop(stack *);
void checkvalid(char []);

int main()
{   
    char exp[80];
    int i;  
   	gets(exp);
   	for(i=0;i<strlen(exp);i++)
   	{
   		printf("%c", exp[i]);
   	}
   	checkvalid(exp);
   	getch();
}                    /* end of main function*/


void push(stack *s, char x)
{
	if(s->top == MAXITEMS-1)
	{
		printf("stack overflow\n");
		exit(1);
	}
	else
	s->items[++(s->top)] = x;
	return;
}                          /* end of push function*/                        

int pop (stack*s)
{
	if (s->top == -1)
	{
		printf("stack underflow");
		exit(1);
	}
	return s->items[s->top--];
}                          /* end of pop function*/


void checkvalid(char exp[])
{
     stack s;
     s.top = -1;
     int i;
     int valid=1;
     char symb,j;
     for(i=0;i<strlen(exp);i++) /* for loop begin*/
     {
    	symb=exp[i];
    	if(symb=='('||symb=='['||symb=='{')
    	{
    		push(&s,symb);
    	}
    	else if(symb==')'||symb==']'||symb=='}')
    	{
    	  if (s.top == -1)
        	{
    		printf("Empty\n");
    		valid = 0;
    		}
    		else{
    			j=pop(&s);
    			if((symb == ')' && j!= '(') || (symb == '}' && j != '{') || (symb == ']' && j!= '['))
   				valid=0;				
    			} /* end of else */
    	}  /* end of else if */
    }                                       /* End of for loop*/
    	if(s.top!=-1)
    	{
          valid=0;	
    	}
    	
    	if(valid==1)
    	printf("%c\nstring is valid",exp[i]);
    	else
    	printf("%c string is not valid",exp[i]);
}                                           /* end of checkvalid function*/
