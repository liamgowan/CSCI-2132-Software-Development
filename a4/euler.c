/*This program computes the value of Euler's number using an infinite series
 *User specifies the number of items to be evaluated in this series
 *Author: Meng He
 */

#include <stdio.h>

/*Main Function
 *Parameters: none
 *Return value: 0 for successful execution, 1 for incorrect input
 */
int main(void) {
  int n;    /*The number of items to be evaluated in the series for e*/
  int i; 
  double evalue = 1.0;  /*The result of evaluation*/
  double term = 1.0;    /*The value of the current term in the series*/

  /*Read n and check whether it is positive*/
  printf("Enter the value of n:");
  scanf("%d", &n);
  if (n < 1) {
    printf("Incorrect value of n\n.");
    return 1; 
  }

  /*Evaluate e using the infinite series*/
  for (i = 1; i <= n; i++) {
    term /= i;

    evalue += term;
  }
  
  /*Print the result*/
  printf("%.10f\n", evalue);

  return 0;
}
