/*Liam Gowan B00673126 CSCI 2132 Assignment 5 Question 2
 *This program was designed to take the amount of rows and columns for two matrices,
 *fill them with user assigned values. It then multiplies the two matrices together
 *and displays the result. It will show an error message and terminate if one of the 
 *rows or columns has a size of less than 1, or if the number of columns of the first
 *matrix is not equal to the number of rows of the second matrix.
 */
#include <stdio.h>
//function prototypes
void matsMaker(int mat[][50],int row, int col);
void multiply(int mat1[][50],int mat2[][50],int mult[][50],int row1,int col1, int row2, int col2);
void displayMult(int mult[][50],int row1,int col2);
int main(void){
  int mat1[50][50], mat2[50][50], mult[50][50],row1,col1,row2,col2;
  //Takes in values for first row and column, makes sure they are greater than 0.
  scanf("%d%d",&row1,&col1);
  if(row1<1||col1<1){
    printf("Error: Rows and columns must be of a value greater than 0.");
    return 1;
  }
  //makes first matrix
  matsMaker(mat1,row1,col1);
  //Takes in values for second row and column, makes sure they are greater than 0.
  scanf("%d%d",&row2,&col2);
  if(row2<1||col2<1){
    printf("Error: Rows and columns must be of a value greater than 0.");
    return 1;
  }
  //Displays error message if col1!=row2
  if(col1!=row2){
    printf("Error: Number of columns in matrix 1 must equal number of rows in matrix 2");
    return 1;
  }
  //makes second matrix
  matsMaker(mat2,row2,col2);
  //multiplies the two matrices
  multiply(mat1,mat2,mult,row1,col1,row2,col2);
  //shows result
  displayMult(mult,row1,col2);
  return 0;
}

//Takes a matrix, fills it with values using scanf
void matsMaker(int mat[][50],int row, int col){
  int i,j;
  for(i=0;i<row;i++){
    for(j=0;j<col;j++){
      scanf("%d",&mat[i][j]);
    }
  }
}
//First fills matrix mult with 0's, then multiplies the two matrices
void multiply(int mat1[][50],int mat2[][50],int mult[][50],int row1,int col1, int row2, int col2){
  int i,j,k;
  for(i=0;i<row1;i++){
    for(j=0;j<col2;j++){
      mult[i][j]=0;
    }
  }
  for(i=0;i<row1;i++){
    for(j=0;j<col2;j++){
      for(k=0;k<col1;k++){
	mult[i][j]+=mat1[i][k]*mat2[k][j];
      }
    }
  }
}
//display all values in the mult matrix using the proper format
void displayMult(int mult[][50], int row1, int col2){
  int i,j;
  for(i=0;i<row1;i++){
    for(j=0;j<col2;j++){
      printf("%6d",mult[i][j]);
    }
    printf("\n");
  }
}
