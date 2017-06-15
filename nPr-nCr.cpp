/*
 *  Author: Adam Hudson
 *  Date: 2017-06-14
 *  Description: Simple calculator to compute permutations and combinations. I have gotten tired
                 of doing them by hand.
 */

#include <iostream>

using namespace std;

// Functions

// Compute a real factorial
// Carfull! This will exceed what an int can store quick
int factorial( int a, int result ){
  if( a == 1 ){
    return result;
  }
  else{
    return factorial( a - 1, a * result );
  }
}

// This function makes it easier for the computer so the values
// do not get so big as quickly
int pFactorial( int a, int b, int result ){
  // Calculate the partial factorial
  if( a == b ){
    return result;
  }
  else{
    return pFactorial( a - 1, b, a * result );
  }
}

int combination( int n, int r ){
  int bottom = n - r;
  
  // Result will always be 1 to start out with.
  // A factorial will never be 0.
  return pFactorial(n, bottom, 1)/factorial(r,1);
}

int permutation( int n, int r ){
  int bottom = n - r;

  // Result will always be 1 to start out with.
  // A factorial will never be 0.
  return pFactorial(n, bottom, 1);
}

int main(){
  //
  int choice, n, r;

  cout << "What type of problem do you want to solve?" << endl;
  cout << "1) Combination" << endl;
  cout << "2) Permutation" << endl;
  
  while( true ){
    cout << ">";
    cin >> choice;

    // Break out of the loop if the user gets it right
    if( choice == 1 || choice == 2 ){
      break;
    }
    cout << "Error: invalid choice" << endl;
  }
  
  // Debug output
  /*cout << "The choice entered is: " << choice << endl;*/

  while( true ){
    cout << "Please enter value for n" << endl;
    cout << ">";
    cin >> n;

    cout << "Please enter value for r" << endl;
    cout << ">";
    cin >> r;

    // Break out of the loop if the user gets it right
    if( n >= r ){
      break;
    }
    cout << "Error: r cannot be bigger than n" << endl;
  }

  if( choice == 1 ){
    combination(n,r);
    cout << "The result of the combination is: " << combination(n,r) << endl;
  }

  if( choice == 2){
    cout << "The result of the permutation is: " << permutation(n,r) << endl;
  }

  return 0;
}