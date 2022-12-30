#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

double Compute(char operator,double a,double b)
{
 if(operator=='+')
  return a+b;
 if(operator=='-')
  return a-b;
 if(operator=='*')
  return a*b;
 if(operator=='/')
  return a/b;
 if(operator=='^')
  return pow(a,b) ; 
}
void Push(double STACK[],int *top,int value)
{ if((*top)>10000)
  {
    printf("STACK is full");
    return;
  }
  (*top)++;
  STACK[(*top)]=(double)value;
}

double Pop(double STACK[],int *top)
{ 
    if((*top)==0)
    {
        printf("STACK is EMPTY");
        return -1;
    }
 double temp=STACK[(*top)];
 (*top)--;
 return temp;
}
double Evaluate_Postfix(char expression[])
{
   double stack[10000];
   int top=0;
   int i=0;
   char ch=expression[i];

   while (ch!=')')
   {
     if(isdigit(ch))
     {
        Push(stack,&top,ch-'0');
     }
     else if(ch=='+'|| ch=='-'||ch=='*'||ch=='/'||ch=='^')
     {
        double a=Pop(stack,&top);
        double b=Pop(stack,&top);
        Push(stack,&top,Compute(ch,b,a));

     }

    else
    {
        printf("Wrong input for expression evaluation\n");
        return -1;
    }
    
     ch=expression[++i];

   }

   return Pop(stack,&top);

}

int main()
{
    char Exp[10000];//={'5','6','2','+','*','8','4','/','-',')'};
    //"562+*84/-)";
    scanf("%s",Exp);
   

    printf("\n%lf",Evaluate_Postfix(Exp));
}