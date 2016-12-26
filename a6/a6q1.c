/*Liam Gowan B00673126 CSCI Assignment 6 Question 1 WITH BONUS
 *This program will evalutate fully parenthesized expressions using two stacks. It accounts for the following
 *error checks: stack overflow and underflow, illegal character entry, still operators left in stack, still >1
 *operand in stack, division by 0, and when entering bonus question queries to make sure they have been
 *entered properly. 
 */

#include <stdio.h>
#include <stdlib.h>

//function prototypes
void push(int *stack, int* top, int element);
int pop(int *stack,int* top);
void calculate(int* numStack, int* numTop, int* opStack, int* opTop); 

int main(void){
  int numStack[20], operStack[20], numTop=0, operTop=0, i=0,result=0, leftBracketCounter=0,rightBracketCounter=0;
  char expression[302],c;
  //accepts user entry up to 300 characters
  fgets(expression, 300, stdin);
  //while loop ensures that no invalid characters were entered and that there is the same # of left brackets as right brackets
  //, or terminates
  while(expression[i]!='\n'){
    if(expression[i]=='(')
      leftBracketCounter++;
    else if(expression[i]==')')
      rightBracketCounter++;
    else if(expression[i]!='+'&&expression[i]!='-'&&expression[i]!='%'&&expression[i]!='/'&&expression[i]!='*'&&
	    expression[i]!='0'&&expression[i]!='1'&&expression[i]!='2'&&expression[i]!='3'&&expression[i]!='4'&&
	    expression[i]!='5'&&expression[i]!='6'&&expression[i]!='7'&&expression[i]!='8'&&expression[i]!='9'&&
	    expression[i]!=' '&&expression[i]!='<'&&expression[i]!='>'&&expression[i]!='='&&expression[i]!='!'){
      printf("Error: You entered an invalid key.\n");
      return 1;
    }
    i++;
  }
  
  if(leftBracketCounter!=rightBracketCounter){
    printf("Error: The number of left and right parentheses are not the same.\n");
    return 1;
  }
  leftBracketCounter=0;
  rightBracketCounter=0;
  i=0;
  //if something is entered with no paratheses at all, this will allow it to still be computed.
  while(expression[i]!='\n'){
    i++;
    if(expression[i]==')')
      rightBracketCounter++;
  }
  if(rightBracketCounter==0){
    expression[i]=')';
    expression[i+1]='\0';
  }
  else
    expression[i]='\0';
  i=0;
  //runs main evaluation
  while((c=expression[i])!='\0'){
    //ignores ('s and whitespace
    if(c=='('||c==' '){
      i++;
      continue;
    }
    //adds -,+,*,& and / operators to stack
    else if(c=='-'||c=='+'||c=='*'||c=='%'||c=='/'){
      push(operStack,&operTop,c);
      //overflow error check
      if(operStack[19]!='\0'){
	printf("Error: Operator stack overflow.\n");
	return 1;
      }
    }
    //adds <,<=,>,>=,==,!= to operator stack
    else if(c=='<'||c=='>'||c=='!'||c=='-'||c=='='){
      if(c=='<'&&expression[i+1]!='=')
	push(operStack,&operTop,'<');
      else if(c=='<'&&expression[i+1]=='='){
	push(operStack,&operTop,'l');
	i++;
      }
      else if(c=='>'&&expression[i+1]!='=')
	push(operStack,&operTop,'>');
      else if(c=='>'&&expression[i+1]=='='){
	push(operStack,&operTop,'g');
	i++;
      }
      else if(c=='='&&expression[i+1]=='='){
	push(operStack,&operTop,'=');
	i++;
      }
      //error check
      else if(c=='='&&expression[i+1]!='='){
	printf("Error: Invalid keystroke.\n");
	return 1;
      }
      else if(c=='!'&&expression[i+1]=='='){
	push(operStack,&operTop,'!');
	i++;
      }
      //error check
      else if(c=='!'&&expression[i+1]!='='){
	printf("Error: Invalid keystoke.\n");
	return 1;
      }
    }
    //The following adds numbers to number stack. If the next char is a number, multiply sum by 10, and add the char as a num
    //to it, and repeat.
    else if(c>=48&&c<=57){
      int sum=(c-48);
      i++;
      c=expression[i];
      while(c>=48&&c<=57){
	sum=sum*10;
	sum=sum+(c-48);
	i++;
	c=expression[i];
      }
      if(numStack[19]!='\0'){
	printf("Error: Operand stack overflow.\n");
	return 1;
      }
      push(numStack,&numTop,sum);
      continue;
    }
    //Induces calculation
    else if(c==')')
      calculate(numStack,&numTop,operStack,&operTop);
    else//error check
      printf("\nError: The sign %c is invalid.\n",c);
      i++;
  }
  //prints answer
  printf("%d\n",pop(numStack,&numTop));
  return 0;
}
//pushes to stack
void push(int *stack, int* top, int element){
  stack[*top]=element;
  (*top)++;
}
//pops from stack
int pop(int *stack, int* top){
  int temp;
  (*top)--;
  temp=stack[*top];
  return temp;
}
//calculates
void calculate(int* numStack, int* numTop, int* operStack, int* operTop){
  int num1,num2,result;
  char sign;
  num1=pop(numStack,numTop);
  num2=pop(numStack,numTop);
  sign=pop(operStack,operTop);
  //error check to ensure nothing is divided by 0
  if(num1==0&&(sign=='/'||sign=='%')){
      printf("Error: Division by 0 is not allowed.\n");
      exit(0);
  }
  //performs all calculations given the sign
  if(sign=='+')
    result = (num1+num2);
  else if(sign=='-')
    result = (num2-num1);
  else if(sign=='*')
    result = (num1*num2);
  else if(sign=='/')
    result = (num2/num1);
  else if(sign=='%')
    result = (num2%num1);
  else if(sign=='<')
    result =(num2<num1);
  else if(sign=='l')
    result = (num2<=num1);
  else if(sign=='>')
    result=(num2>num1);
  else if(sign=='g')
    result=(num2>=num1);
  else if(sign=='=')
    result=(num2==num1);
  else if(sign=='!')
    result=(num2!=num1);
  //sends result to top of numStack
  push(numStack,numTop,result);
}
