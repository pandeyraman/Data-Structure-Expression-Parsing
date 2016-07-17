/* 
* Evaluate a postfix expression.
* Author : Raman Pandey
* Date : 07/07/2016
* Ref : Data Structure using c and c++, chapter 2 , page 100
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define MAXITEMS 100

typedef struct{
	int top;
	double items[MAXITEMS];
}stack;

void eval(char []);
void push(stack *, double);
double pop(stack *);
double oper(char,double,double);

int main()
{
   	int i;
   	char exp[MAXITEMS];
   	gets(exp);
   	printf("Entered postfix expression: ");
   	for(i=0;i<strlen(exp);i++)
   	printf("%c", exp[i]); 	
   	eval(exp);
   	getch();
}             /* end of main function*/

void eval(char exp[])
{
    int i;
   	double opnd1,opnd2,value;
   	stack s;
   	s.top= -1;
   	int symb;
    for(i=0;i<strlen(exp);i++)
    {
    	symb=exp[i];
    	if ((symb>='0')&&(symb<='9'))
    	push(&s, (double)(symb-'0'));
   		else if(symb=='+'||symb=='-'||symb=='*'||symb=='/'||symb=='$')
   			{
   				opnd2= pop(&s);
   				opnd1= pop(&s);
   				value = oper(symb,opnd1,opnd2);
   				push(&s,value);
  			} 	
   	}
    	
     printf("\nevaluation=%0.2lf", pop(&s));   
 }                 /* end of eval function*/
 
  
void push(stack *s, double x)
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
     
     
double pop (stack*s)
{
  	if (s->top == -1)
   	{
       printf("stack underflow");
   	   exit(1);
   	}
   	return s->items[s->top--];
}                            /* end of pop function*/
    
double oper(char sign, double op1,double op2)
{
 	switch(sign)
   	{
   		case '+':return(op1+op2);
   		case '-':return(op1-op2);
   		case '*':return(op1*op2);
   		case '/':return(op1/op2);
   		case '$':return(pow(op1,op2));
   		default : printf("invalid");
   	}
}                             /* end of oper function*/
