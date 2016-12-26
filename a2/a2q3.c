/* Liam Gowan B00673126 CSCI 2132 ASSIGNMENT 2, January 31 2016
 * This program accepts 3 integers, and then
 * converts the binary number assosciated for them in with a 3 bit width.
 */ 

#include <stdio.h>
#include <stdlib.h>
int main(void){
  int n1,n2,n3;
  //takes in integers and assigns to variables
  scanf("%d%d%d",&n1,&n2,&n3);
  int i=0;
  //makes an array of the integers
  int nums[]={n1,n2,n3};
  for(i;i<3;i++){
    //if num is greater than 3, third bit must be a 1, otherwise 0
    if(nums[i]>=4)
      printf("1 ");
    else
      printf("0 ");
    //if num greater than 1 and not 4 or 5, then it must be a 1, otherwise 0
    if(nums[i]>1&&nums[i]!=4&&nums[i]!=5)
      printf("1 ");
    else
      printf("0 ");
    //if odd number, print 1, otherwise 0
    if(nums[i]%2!=0)
      printf("1");
    else
      printf("0");
    if(i==2)
      printf("\n");
    else
      printf(" ");
  }
  return 0;
}

