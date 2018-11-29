// Project: Real Number precision
// File: Real.h
// Author: David Smith
// Description: The Real Class 

#ifndef __REAL_H
#define __REAL_H
#include <vector>
#include <iostream>

class Real
{

 public:
  Real();
  ~Real();
  Real( const Real & );
  Real( const std::string & );
  Real( int );
  Real( long long );
  Real( double );
  Real( double, int );
  void round (int );
  int precision () const;
  std::string toString() const;
  
  // I/O stream
  friend std::istream & operator >> (std::istream & ins, Real & );
  friend std::ostream & operator << (std::ostream & outs, const Real & );
  
  // Operator overloads
  bool operator <  (const Real & ) const;
  bool operator >  (const Real & ) const;
  bool operator <= (const Real & ) const;
  bool operator >= (const Real & ) const;
  bool operator == (const Real & ) const;
  bool operator != (const Real & ) const;
  Real operator +  (const Real & ) const;
  Real operator -  (const Real & ) const;
  Real operator *  (const Real & ) const;
  Real operator /  (const Real & ) const;
  Real & operator  = (const Real & );
  Real operator += (const Real & );
  Real operator -= (const Real & );
  Real operator *= (const Real & );
  Real operator /= (const Real & );
  void set_Neg(bool);		
 private:
  
  bool negative_check(std::string string_to_check);
  void remove_negative();
  void add_negative();
  std::vector <char> front;
  std::vector <char> back;
  //std::string add_Helper(std::vector<char>, std::vector<char>, std::vector<char>, std::vector<char>);
  //std::string remove_Helper(std::vector<char>, std::vector<char>, std::vector<char>, std::vector<char>);
  bool backside;
  bool negative;
  bool carry;
  bool real_negative;
  bool this_negative;
  bool global_real_bigger;
};


#endif
