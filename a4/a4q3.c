/*Liam Gowan B00673126 CSCI Assignment 4 Question 3
 *This program was designed to take in 10 integers using scanf,
 *make an array of them, and then use insertion sort to arrange
 *the elements in ascending order. A linear scan is then performed
 *to check if element i-1 and i are the same. If at any point they
 *are, the array is not unique, an "n" is printed, and the program 
 *quits. If they are never the same, the array is unique and a "y"
 * is printed.
 */

#include <stdio.h>

int main(void){
  int len=10;
  int arr[len];
  int i=0;
  int j=0;
  int k=0;
  //takes in 10 integers and makes array
  for(i;i<len;i++)
    scanf("%d",&arr[i]);
  //performs insertion sort
  for(i=1;i<len;i++){
    j=i;
    while(j>0&&arr[j]<arr[j-1]){
      k = arr[j];
      arr[j]=arr[j-1];
      arr[j-1]=k;
      j--;
    }
  }	
  //performs linear scan to check if two elements are the same
  //if so print "n" to indicate it is not unique and quit
  for(i=1;i<len;i++)
    if(arr[i-1]==arr[i]){
      printf("n\n");
      return 1;
    }
  //otherwise print "y" to indicate it is unique
  printf("y\n");
  return 0;
}
