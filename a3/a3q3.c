/* Liam Gowan B00673126 CSCI 2132 Assignment 3 Question 3
 * This program was designed to take in the maximum value 
 * of c in a^2+b^2=c^2, and then find the total number of 
 * possibilities for this maximum value where a<b<c and 
 * c is <= maximum value.
 */
#include <stdio.h>

int main(void){
  int a=0,b=0,c=0,a2plusb2,max,count=0;
  scanf("%d",&max);
  //Ensures user enters positive number
  while(max<1){
    printf("The number you entered was not positive. Enter another number: )");
    scanf("%d",&max);
  }
  //Uses triple nested for loop, if a^2+b^2 is equal to c^2, increase count
  for(c;c<=max;c++){
    for(b;b<c;b++){
      for(a;a<b;a++){
	a2plusb2=(a*a+b*b);
	if(a2plusb2==c*c)
	  count++;
      }
      a=0;
    }
    b=0;
  }
  //Display the count
  printf("%d\n", count);
  return 0;
}
