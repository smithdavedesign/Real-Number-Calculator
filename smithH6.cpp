// File: barrazaH4.cpp
// Assignment: CS 460 - Homework 4 - Test file
// Author: Nazania Barraza
// Date: Sunday, March 26, 2017
// Description: This is a testing file that checks all the functions assigned to #2. Good luck on your code!!!

#include<iostream>
#include "Real.h"

using namespace std;

int main()
{

  // #1
  /*
  cout << " both positive SUB" << endl;
  Real R1 ("5.124352");
  Real R2 ("80000.903284");
  cout << "R1 : " << R1 << endl
       << "R2 : " << R2 << endl;
  cout << "R2 - R1 :" << (R2 - R1) << endl;
  cout << "R1 - R2 :" << (R1 - R2) << endl << endl << endl;

  cout << " both neg SUB" << endl;
  Real R3 ("-5.124352");
  Real R4 ("-80000.903284");
  cout << "R3 : " << R3 << endl
       << "R4 : " << R4 << endl;
  cout << "R3 - R4 :" << (R3 - R4) << endl;
  cout << "R4 - R3 :" << (R4 - R3) << endl << endl << endl;
  
  cout << " one positive SUB" << endl;
  Real R5 ("5.124352");
  Real R6 ("-80000.903284");
  cout << "1" << endl;
  cout << "R5 : " << R5 <<endl <<"R6 : " << R6 << endl;
  cout << "R5 - R6 :" << (R5 - R6) << endl << endl<< endl;
  cout << "2" << endl;
  cout << "R5 : " << R5 <<endl <<"R6 : " << R6 << endl;
  cout << "R6 - R5 :" << (R6 - R5) << endl << endl << endl;
  
  cout << " one positive SUB" << endl;
  Real R7 ("-5.124352");
  Real R8 ("80000.903284");
  cout << "1" << endl;
  cout << "R7 : " << R7 << endl << "R8 : " << R8 << endl;
  cout << "R7 - R8 :" << (R7 - R8) << endl << endl << endl;
  cout << "2" << endl;
  cout << "R7 : " << R7 << endl << "R8 : " << R8 << endl;							  
  cout << "R8 - R7 :" << (R8 - R7) << endl << endl << endl;
  */
  
  Real R1 ("5.124352");
			
   cout << "R1: " << R1 << endl;

   //  #2 - Gets called by default when you finish the program.
  
   // #4
  Real R2("-141.100055"); //("1234.4321");
  //  cout << "R2: " << R2 << endl;
  
  string s = "-11.9456"; //"5678.8765";
  Real R3(s);
   cout << "R3: " << R3 << endl;

  // #5
 

  // #6
  long long ll = 1234567890;
  Real R5 ("12.3123");
  cout << "R5: " << R5 << endl;

   #7
   double d = -1234.567890;
   Real R6(d);
   cout << "R6: " << R6 << endl;

  // #8

  double d2 = 899.899999;
  Real R7(d2, 2);
  cout << "R7: " << R7 << endl;

  
  string one = "999.999";
  Real R22 (one);
  Real R21 ("0.001");
   cout << R22 << endl;
   cout << R21 << endl << endl;
   cout << "add : " << (R22 + R21) << endl;
  
  string i = "12345";
  Real R4(i);
  // cout << "R4: " << R4 << endl;
  

   cout << endl;
  cout << R5 << endl;
   cout << R4 << endl << endl;
   cout << "R4 + R5, where R5 is: " << R5 << "answer is: " << (R4 + R5) << endl;

  Real R30 ("-8769.879");
  Real R31 ("-4859.75843");
    cout << endl;
   cout << R30 << endl;
   cout << R31 << endl << endl;
   cout << (R30 + R31) << endl;
  


  
  // #3
  Real R8 = R3;
  cout << "R8: " << R8 << endl;
  cout << "R8 should be equal to R3: " << R8 << " == " << R3 << endl;

  // #9
  R6.round(2);
  cout << "R6: " << R6 << endl;

  // #10
  int precnum = R2.precision();
  cout << "The precision of R2 is: " << precnum << endl;

  // #11
  string strnum = R5.toString();
  cout << "R5 strnum: " << strnum << endl;
  cout << "R5 strnum should be equal to R5: " << strnum << " == " << R5 << endl;


  // #12 & #13
  for(int i = 0; i < 3; i++)
    {
      cin >> R1;
      cout << "R1: " << R1 << endl;
    }

  // #14
  
  if (R2 < R3)
    cout << "R2 should (CORRECTLY) be less than R3: " << R2 << " < " << R3 << endl;
  else
    cout << "R2 should (INCORRECTLY) be greater than R3: " << R2 << " > " << R3 << endl;

  if (R3 < R2)
    cout << "R3 should (INCORRECTLY) be less than R2: " << R3 << " < " << R2 << endl;
  else
    cout << "R3 should (CORRECTLY) be greater than R2: " << R3 << " > " << R2 << endl;

  if (R3 < R8)
    cout << "R3 should (INCORRECTLY) be less than R8: " << R3 << " < " << R8 << endl;
  else
    cout << "R3 should (CORRECTLY) be equal to R8: " << R3 << " == " << R8 << endl;

  // #15
  if (R2 > R3)
    cout << "R2 should (INCORRECTLY) be greater than R3: " << R2 << " > " << R3 << endl;
  else
    cout << "R2 should (CORRECTLY) be less than R3: " << R2 << " < " << R3 << endl;

  if (R3 > R2)
    cout << "R3 should (CORRECTLY) be greater than R2: " << R3 << " > " << R2 << endl;
  else
    cout << "R3 should (INCORRECTLY) be greater than R2: " << R3 << " < " << R2 << endl;

  if (R3 > R8)
    cout << "R3 should (INCORRECTLY) be greater than R8: " << R3 << " > " << R8 << endl;
  else
    cout << "R3 should (CORRECTLY) be equal to R8: " << R3 << " == " << R8 << endl;

  // #16
  if (R2 <= R3)
    cout << "R2 should (CORRECTLY) be less than or equal to R3: " << R2 << " <= " << R3 << endl;
  else
    cout << "R2 should (INCORRECTLY) be greater than R3: " << R2 << " > " << R3 << endl;

  if (R3 <= R2)
    cout << "R3 should (INCORRECTLY) be less than or equal to R2: " << R3 << " <= " << R2 << endl;
  else
    cout << "R3 should (CORRECTLY) be greater than R2: " << R3 << " > " << R2 << endl;

  if (R3 <= R8)
    cout << "R3 should (CORRECTLY) be less than or equal to R8: " << R3 << " <= " << R8 << endl;
  else
    cout << "R3 should (INCORRECTLY) be greater than R8: " << R3 << " > " << R8 << endl;
  
  // #17
  if (R2 >= R3)
    cout << "R2 should (INCORRECTLY) be greater than or equal to R3: " << R2 << " >= " << R3 << endl;
  else
    cout << "R2 should (CORRECTLY) be less than R3: " << R2 << " < " << R3 << endl;

  if (R3 >= R2)
    cout << "R3 should (CORRECTLY) be greater than or equal to R2: " << R3 << " >= " << R2 << endl;
  else
    cout << "R3 should (INCORRECTLY) be less than R2: " << R3 << " < " << R2 << endl;

  if (R3 >= R8)
    cout << "R3 should (CORRECTLY) be greater than or equal to R8: " << R3 << " >= " << R8 << endl;
  else
    cout << "R3 should (INCORRECTLY) be less than R8: " << R3 << " < " << R8 << endl;

  // #18
  if (R2 == R3)
    cout << "R2 should (INCORRECTLY) be equal to R3: " << R2 << " == " << R3 << endl;
  else
    cout << "R2 should (CORRECTLY) be less than R3: " << R2 << " < " << R3 << endl;

  if (R3 == R2)
    cout << "R3 should (INCORRECTLY) be equal to R2: " << R3 << " == " << R2 << endl;
  else
    cout << "R3 should (CORRECTLY) be greater than R2: " << R3 << " > " << R2 << endl;

  if (R3 == R8)
    cout << "R3 should (CORRECTLY) be equal to R8: " << R3 << " == " << R8 << endl;
  else
    cout << "R3 should (INCORRECTLY) NOT be equal to R8: " << R3 << " != " << R8 << endl;

  // #19
  if (R2 != R3)
    cout << "R2 should (CORRECTLY) NOT be equal to R3: " << R2 << " != " << R3 << endl;
  else
    cout << "R2 should (INCORRECTLY) be equal to R3: " << R2 << " == " << R3 << endl;

  if (R3 != R2)
    cout << "R3 should (CORRECTLY) NOT be equal to R2: " << R3 << " != " << R2 << endl;
  else
    cout << "R3 should (INCORRECTLY) be equal to R2: " << R3 << " == " << R2 << endl;

  if (R3 != R8)
    cout << "R3 should (INCORRECTLY) be equal to R8: " << R3 << " == " << R8 << endl;
  else
    cout << "R3 should (CORRECTLY) NOT be equal to R8: " << R3 << " != " << R8 << endl;

  
  // #20
  Real R9;
  cout << "R2 + R3, R2: " << R2 << "R3: " << R3 << endl;
  R9 = R2 + R3;
  cout << "R2 + R3 = " << R2 << " + " << R3 << " = " << R9 << endl;

  Real R10 = R3 + R2;
  cout << "R3 + R2 = " << R3 << " + " << R2 << " = " << R10 << endl;

  cout << R1 << ' ' << R2 << endl;
  R9 = R1 + R2;
  cout << "R1 + R2 = " << R1 << " + " << R2 << " = " << R9 << endl;

  R9 = R2 + R1;
  cout << "R2 + R1 = " << R2 << " + " << R1 << " = " << R9 << endl;

  R9 = R3 + R4;
  cout << "R3 + R4 = " << R3 << " + " << R4 << " = " << R9 << endl;

  R9 = R4 + R3;
  cout << "R4 + R3 = " << R4 << " + " << R3 << " = " << R9 << endl;

  R9 = R5 + R6;
  cout << "R5 + R6 = " << R5 << " + " << R6 << " = " << R9 << endl;

  R9 = R6 + R5;
  cout << "R6 + R5 = " << R6 << " + " << R5 << " = " << R9 << endl;
  
  R9 = R2 + R7;
  cout << "R2 + R7 = " << R2 << " + " << R7 << " = " << R9 << endl;

  R9 = R7 + R2;
  cout << "R7 + R2 = " << R7 << " + " << R2 << " = " << R9 << endl;
  cout << "finished adds" << endl; 
  // #21
  Real R11;
  R11 = R2 - R3;
  cout << "R2 - R3 = " << R2 << " - " << R3 << " = " << R11 << endl;  

  Real R12 = R3 - R2;
  cout << "R3 - R2 = " << R3 << " - " << R2 << " = " << R12 << endl;

  R11 = R1 - R2;
  cout << "R1 - R2 = " << R1 << " - " << R2 << " = " << R11 << endl;

  R11 = R2 - R1;
  cout << "R2 - R1 = " << R2 << " - " << R1 << " = " << R11 << endl;

  R11 = R3 - R4;
  cout << "R3 - R4 = " << R3 << " - " << R4 << " = " << R11 << endl;

  R11 = R4 - R3;
  cout << "R4 - R3 = " << R4 << " - " << R3 << " = " << R11 << endl;

  R11 = R5 - R6;
  cout << "R5 - R6 = " << R5 << " - " << R6 << " = " << R11 << endl;

  R11 = R6 - R5;
  cout << "R6 - R5 = " << R6 << " - " << R5 << " = " << R11 << endl;
  
  R11 = R2 - R7;
  cout << "R2 - R7 = " << R2 << " - " << R7 << " = " << R11 << endl;

  R11 = R7 - R2;
  cout << "R7 - R2 = " << R7 << " - " << R2 << " = " << R11 << endl;
  
  string anumber1 = "-12";
  string anumber2 = "567";
  Real R13(anumber1);
  Real R14(anumber2);
  Real R15;
  R15 = R13 * R14;
  cout << "R13 x R14 = " << R13 << " x " << R14 << " = " << R15 << endl;
    
  // #24
  //R4 = R5;
  //cout << R4 << " should be equal to " << R5 << endl;
    // #25
  cout << "R2 += R3: " << R2 << " + " << R3 << " = ";
  R2 += R3;
  cout << R2 << endl;

  cout << "R3 += R2: " << R3 << " + " << R2 << " = ";
  R3 += R2;
  cout << R3 << endl;

  cout << "R1 += R2: " << R1 << " + " << R2 << " = ";
  R1 += R2;
  cout << R1 << endl;
  
  cout << "R2 += R1: " << R2 << " + " << R1 << " = ";
  R2 += R1;
  cout << R2 << endl;
  
  cout << "R3 += R4: " << R3 << " + " << R4 << " = ";
  R3 += R4;
  cout << R3 << endl;
  
  cout << "R4 += R3: " << R4 << " + " << R3 << " = ";
  R4 += R3;
  cout << R4 << endl;
  
  cout << "R5 += R6: " << R5 << " + " << R6 << " = ";
  R5 += R6;
  cout << R5 << endl;
  
  cout << "R6 += R5: " << R6 << " + " << R5 << " = ";
  R6 += R5;
  cout << R6 << endl;
  
  cout << "R2 += R7: " << R2 << " + " << R7 << " = ";
  R2 += R7;
  cout << R2 << endl;

  cout << "R7 += R2: " << R7 << " + " << R2 << " = ";
  R7 += R2;
  cout << R7 << endl;
  
  
  // #26
  cout << "R2 -= R3: " << R2 << " - " << R3 << " = ";
  R2 -= R3;
  cout << R2 << endl;

  cout << "R3 -= R2: " << R3 << " - " << R2 << " = ";
  R3 -= R2;
  cout << R3 << endl;

  cout << "R1 -= R2: " << R1 << " - " << R2 << " = ";
  R1 -= R2;
  cout << R1 << endl;
  
  cout << "R2 -= R1: " << R2 << " - " << R1 << " = ";
  R2 -= R1;
  cout << R2 << endl;
  
  cout << "R3 -= R4: " << R3 << " - " << R4 << " = ";
  R3 -= R4;
  cout << R3 << endl;
  
  cout << "R4 -= R3: " << R4 << " - " << R3 << " = ";
  R4 -= R3;
  cout << R4 << endl;
  
  cout << "R5 -= R6: " << R5 << " - " << R6 << " = ";
  R5 -= R6;
  cout << R5 << endl;
  
  cout << "R6 -= R5: " << R6 << " - " << R5 << " = ";
  R6 -= R5;
  cout << R6 << endl;
  
  cout << "R2 -= R7: " << R2 << " - " << R7 << " = ";
  R2 -= R7;
  cout << R2 << endl;

  cout << "R7 -= R2: " << R7 << " - " << R2 << " = ";
  R7 -= R2;
  cout << R7 << endl;
  
  
    return 0;
}
