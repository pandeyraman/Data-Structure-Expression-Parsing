/* 
* Convert an expression  from infix to postfix
* Author : Raman Pandey
* Date : 07/08/2016
* Ref : Data Structure using c and c++, chapter 2 , page 107
*/
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 50

typedef struct {
	int top;
	char items[MAXSIZE];
} stack ;

void push(stack *, char);
char pop(stack *);
void postfix(char *, char *);
int prcd(char, char);
int isoperand(int);
void popandtest(stack *, char *, int *);

int main()
{
	char infix[MAXSIZE];
	char postr[MAXSIZE];
	
	printf ("Enter an infix expression \n");
	gets(infix);
	
	printf ("Infix  Expression  = %s \n", infix);
	
	postfix(infix, postr);
	
	printf ("Postfix Expression = %s", postr);
	
	getch();
}                    /*end of main function */

void push(stack *s, char x) 
{
	if (s->top == (MAXSIZE-1))
    {
		printf ("Stack Overflow \n");
		getch();
		exit(1);	
	}
    else
    {
		s->items[++(s->top)] = x;
	}
}                                      /*end of push function */

char pop(stack *s)
{
	if (s->top == -1)
    {
		printf ("Stack Underflow \n");
		getch();
		exit (1);
	} 
    else
    {
		return(s->items[s->top--]);
	}
}                             /*end of pop function */
                                      
void postfix(char infix[], char postr[]) 
{
	
	stack s;
	s.top = -1;
	char symb, topsymb = '+';
	int i = 0, und, j = 0;
	
	for (i = 0; (symb = infix[i]) != '\0'; i++) 
    {
		
		if (isoperand(symb)) 
        {
			postr[j++] = symb;
		} 
        else 
        {
			popandtest (&s, &topsymb, &und);
			while (!und && prcd(topsymb, symb))
             {
				postr[j++] = topsymb;
				popandtest (&s, &topsymb, &und);
			}  /*end of while loop*/
    		if (!und)
            {
    		 push (&s, topsymb);
    		} 
    		if (und || (symb != ')'))
            {
    		 push (&s, symb);
    		}
            else
            {
    		 topsymb = pop(&s);
    		}
	     }/*end of else */
  }/*end of for loop */
	while (s.top != -1) {
		postr[j++] = pop(&s);
	}
		postr[j] = '\0';
		return;
}

int isoperand(int symb)
{
	return ((symb >= '0' && symb <= '9')||(symb >= 'A' && symb <= 'Z'));
}
/*end of isoperand function */

void popandtest(stack *s, char *x, int *und) {
	if (s->top == -1) {
		*und = 1;
		return;
	}
	*und = 0;
	*x = s->items[s->top--];
	return;
}
/*end of popandtest function */

int prcd(char symb1,char symb2)
{
    int value1,value2;
		
	switch (symb1) {
		case '(' :
                  value1 = 0; 
                  break;
		case '$' :
                 value1 = 3; 
                 break;
		case '*' :
                 value1 = 2;
                 break;
		case '/' :
                 value1= 2; 
                 break;
		case '+' :
                 value1 = 1;
                 break;
		case '-' : 
                 value1 = 1;
                 break;
		default  :
         printf ("Error! \n");
	}
	switch (symb2) {
		case '(' : 
                  value2 = 9;
                  break;
		case ')' :
                  value2 = 0; 
                  break;
		case '$' :
                  value2 = 3;
                  break;
		case '*' :
                  value2 = 2; 
                  break;
		case '/' : 
                 value2 = 2;
                 break;
		case '+' : 
                 value2 = 1;
                 break;
		case '-' : 
                 value2 = 1;
                 break;
		default  :
                  printf ("Invalid! \n");
	}
		
	return (value1>value2);
}
 /*end of prcd function */
