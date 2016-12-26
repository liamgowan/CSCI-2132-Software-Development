
/*Liam Gowan B00673126 CSCI Assignment 5 Question 1
 *This program was designed to return the lowest, highest, or average final grade.
 *First it takes in which to output. It then takes in the number of students. It then
 *takes in 4 integers for each student, calculates the final grade, and adds it to an
 *array. The program accounts for error checking. 
 */
#include <stdio.h>
#define K
//function prototypes
float lowest(float grades[],int numStudents);
float highest(float grades[],int numStudents);
float average(float grades[],int numStudents);

int main(void){
  int find=0;
  int numStudents;
  float check;
  //input is assigned to 'check' (a float), so that it can be assigned to an integer
  //and then they can be compared to test for non integer value entries. Also tests
  //to make sure that 'find' is 1, 2 or 3.
  scanf("%f",&check);
  find=check;
  if(!(find==1||find==2||find==3)||check!=find){
    printf("Error: You must enter 1, 2, or 3.\n");
    return 1;
  }
  //A float is again compared to an integer, and if the 'success' value is < 1, then
  //a non number has been entered, therefore it terminates. Also makes sure
  //the value is positive.
  int success = scanf("%f",&check);
  numStudents=check;
  if(numStudents<1||check!=numStudents||success!=1){
    printf("Error: You must enter a positive integer.\n");
    return 1;
  }
  float grades[numStudents];
  float sum=0;
  int i=0;
  int j=0;
  float displayVal=0;
  int toAdd=0;
  //For each student, this nested for loop takes in 4 integers, finds the average,
  //and adds it to an array. It also makes sure that a number between 1 and 100 is
  //entered.
  for(i;i<numStudents;i++){
    int pass[2];
    for(j;j<4;j++){
      success=scanf("%f",&check);
      toAdd=check;
      pass[0]=toAdd;
      if(toAdd<1||toAdd>100||toAdd!=check||success!=1){
	printf("Error: You must enter an integer value between 1-100\n");
	return 1;
      }
      sum+=toAdd;
    } 
    grades[i]=sum/4;
    sum=0;
    j=0;
  }
  //The following calls the appropiate function based on what the user wants to know
  if(find==1)
    displayVal=lowest(grades,numStudents);
  else if(find==2)
    displayVal=highest(grades,numStudents);
  else if(find==3)
    displayVal=average(grades,numStudents);
  printf("%.2f\n",displayVal);//prints value to two decimal places
  return 0;
}

//Function uses linear search to find the lowest integer
float lowest(float grades[],int numStudents){
  float low=grades[0];
  int i=0;
  for(i;i<numStudents;i++){
    if(grades[i]<low)
      low=grades[i];
  }
  return low;
}
//Function uses linear search to find highest integer
float highest(float grades[],int numStudents){
  float high=grades[0];
  int i=0;
  for(i;i<numStudents;i++){
    if(grades[i]>high)
      high=grades[i];
  }
  return high;
}
//Function adds all grades together, finds average
float average(float grades[],int numStudents){
  float average=0, sum=0.0;
  int i=0;
  for(i;i<numStudents;i++){
    sum+=grades[i];
  }
  average=sum/numStudents;
  return average;
}
