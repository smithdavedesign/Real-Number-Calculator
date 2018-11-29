#include<vector>
#include"Real.h"
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
/*
  Author: David Smith
  Date: 2017 spring
  File: Real.cpp
  Class: CS460 HW6
  Description: Real implentation
  purpose: calculate real numbers
*/
string add_Helper(std::vector<char>, std::vector<char>, std::vector<char>, std::vector<char>, bool real_is_bigger);
string subtract_Helper(std::vector<char>, std::vector<char>, std::vector<char>, std::vector<char>, bool real_is_bigger, bool add_helper);   

Real::Real()
{
  backside = false;
  negative = false;
  carry = false;
}

Real::~Real()
{
  front.clear();
  back.clear();   
}

Real::Real( const Real & number )
{
  front.clear();
  back.clear();
  carry = false;
  backside = false;
  negative = number.negative;
  
  for(int i = 0; i < number.front.size(); i++)
    {
      front.push_back(number.front[i]);
    }
  for(int x = 0; x < number.back.size(); x++)
    {
      back.push_back(number.back[x]);
    }
}

Real::Real( const std::string & string_number)
{
    //negative check, if it is true do the following
  negative = negative_check(string_number);
  backside = false;
  carry = false;
  front.clear();
  back.clear();
  
  for (int i =0; i < string_number.length(); i++)
    {
      
      if(string_number[i] == '.')
	{
	  backside = true;
	}
      if(backside == true)
	{
	  back.push_back(string_number[i]);
	}
      else
	{
	  front.push_back(string_number[i]);
	}
    }
}


Real::Real( int number)
{
  //puting my int into a string
  string sNumber = to_string(number);
  backside = false;
  carry = false;
  front.clear();
  back.clear();
  //negative check, if it is true do the following
  negative = negative_check(sNumber);
   
  for (int i =0; i < sNumber.length(); i++)
    {
      front.push_back(sNumber[i]);
      
    }
}

Real::Real( long long number)
{
  //storing my long long into a string
  string sNumber = to_string(number);
  backside = false;
  carry = false;
  front.clear();
  back.clear();;
  //negative check, if it is true do the following  
  negative =  negative_check(sNumber);
  for (int i =0; i < sNumber.length(); i++)
    {
      
      if(sNumber[i] == '.')
	{
	  backside = true;
	}
      if(backside == true)
	{
	  back.push_back(sNumber[i]);
	}
      else
	{
	  front.push_back(sNumber[i]); 
	}
    }
 
}

Real::Real(double number)
{ 
  backside = false;
  carry = false;
  front.clear();
  back.clear();
  
  long long whole = number;

  //store number into string
  string num = to_string(whole);

  num += '.';

  double decimal = number - whole;

  negative = negative_check(num);

  if(negative == false)
    {
      while(decimal > 0)
	{
	  decimal*= 10;
	  whole = decimal;
	  num+= to_string(whole);
	  decimal-= whole;
	}
    }
  else
    {
      string digit = "";
      while(decimal < 0)
	{
	  decimal*= 10;
	  whole = decimal;
	  digit = to_string(whole);
	  if(digit[0] == '-')
	    num+= digit[1];
	  else
	    num+= digit[0];
	  decimal-= whole;
	}
    }

  //negative check
  if(negative == true)
    num = num.substr(1,num.length());

  //num += dd;
  for (int i =0; i < num.length(); i++)
    {
      // cout << num.length() << "num length " << endl;
      if(num[i] == '.')
	{
	  backside = true;
	}
      if(backside)
	{
	  back.push_back(num[i]);
	}
      else
	{
	  front.push_back(num[i]);
	}
    }

  
}
//ask questions
Real::Real( double d, int i)
{
  Real R(d);
  R.round(i);
  *this = R;
    //round at the given precision  
}

void Real::round (int round)
{
  //  round = round +1;
  //get rid of the negative to make calculaions easier

  if(negative == true)
    {
      remove_negative();
    }
  /*
  cout <<"round +1 in vector " << back[round+1] << endl;
  cout << "fronts size after eg removed : " <<front.size() << endl;
  cout << "backs size : " <<back.size() << endl;
  */  
//if the desired round point does not exist in your numbe, we cannot round.
  if(back.size() < round + 1)
    {
      // cout << "backs size : " << back.size() << "   round+1: " << round +1 << endl <<endl;
      //add 0s till we hit the spot they want to round
      while(back.size() != round + 1)
	{
	  // cout << "There is no number to round in this spot so I am adding 0s to make this possible" << endl; 
	  back.push_back('0');
	}
    }
  //set a flag for the carry
  if(back[round+1] >= '5')
    {
      carry =true;
    }
  //loop through the numbers after the decimal point and round.
  int max_vect_size = back.size();
  for(int i = 0; i < max_vect_size; i++)
    {
      if(back.size() > round + 1)
	{
	  back.pop_back();  	
	}
    }
  
  //the spot that was asked to round was greater then 5
  //while we can the one on to the next number we will make the 9s into 0s.
  //if we come to the end of the backvector and we still have carry as true we need to adjust the front vector
  if(carry == true)
    {
      for(int c = back.size() - 1; c > 1; c--)
	{
	  if(carry == true)
	    {
	      if(back[c] == '9')
		{
		  back[c] = '0';
		}
	      else
		{
		  //back[c] = (back[c] + '1');
		  int tempnum = (back[c] - '0') + 1;
		  back[c] = tempnum + '0';
		  carry = false;
		}
	    }
	  else
	    carry = false;
	}
    }
    //update front since we carried all throughtout the back
  if(carry == true)
    {
      for(int f = front.size() - 1; f > 0; f--)
	{
	  if(carry == true)
	    {
	      if(front[f] == '9')
		{
		  front[f] = '0';
		}
	      else
		{
		  int tempnum = (front[f] - '0') + 1; // Fixed it!...
		  front[f] = tempnum + '0'; // ...You're welcome -Naz :P
		  carry = false;
				  
		}
	    }
	  else
	    carry = false;
	}
    }
  //if we have gone through the entire number and our carry is still there we can add a one to the front side
  if(carry == true)
    {
      front.insert(front.begin(), '1');
}

//check if it was a negative number and put a - back into it if so.
  if(negative == true)
    {
     add_negative();
    }

}

int Real::precision () const
{
  return back.size() - 1;
}

std::string Real::toString() const
{
  string string_to_return = "";
  for(int i = 0; i < front.size(); i ++)
    {
      string_to_return += front[i];
    }
  for(int i = 0; i < back.size(); i ++)
    {
      string_to_return += back[i];
    }
  return string_to_return;
}

// I/O stream
istream & operator >> (std::istream & ins, Real & real)
{
  char c;
  string input = "";
  ins.get(c);
  if(c == '-')
    {
      input += c;
      ins.get(c);
    }
  while(c >= '0' && c <= '9')
    {
      input += c;
      ins.get(c);
    }
  if(c == '.')
    {
      input += c;
      ins.get(c);
    }
  while(c >= '0' && c <= '9')
    {
      input += c;
      ins.get(c);
    }
  Real temp(input);
  real = temp;
  while(!ins.eof() && c!= ' ' && c!= '\n' && c!= '\t')
    {
      ins.get(c);
    }
  return ins;
}

ostream & operator << (std::ostream & outs, const Real & real)
{
  if(real.negative == true && real.front[0] != '-') 
    outs << '-'; 
  if(real.front.size() == 0)
    outs << "0";
  for(int i = 0; i < real.front.size(); i++)
    {
      outs << real.front[i];
    }
  
  for(int j = 0; j < real.back.size(); j++)
    {
      outs <<  real.back[j];
    }
  if(real.back.size() == 0)
    outs << ".0";
   return outs;
}

////////////////////////
// Operator overloads //
////////////////////////

bool Real::operator <  (const Real & real ) const
{
    if(negative == true && real.negative == false)
    {
      return true;
    }

    //Real- R1+
  if(real.negative == true && negative == false)
    {
      return false;
    }
  //BOTH NEGATIVE
  if(real.negative == true && negative == true)
    {
      if(front.size() > real.front.size())
	{
	  //cout << "this.front.Size > Real.front.size " << endl;
	  return true;
	}
      
      if(front.size() < real.front.size())
	{
	  //cout << "this.front.Size < Real.front.size " << endl;
	  return false;
	}
      
      //if they are both -.some numbers
      //if front[i] > real[i]...true since -.9 < -.1
      if(front.size() == 1 && real.front.size() == 1)
	{
	  cout << "-.  problem" << endl;
       }
      
      for(int i = 1; i < front.size(); i ++)
	{
	  //cout << "loop " << front[i] << " " << real.front[i]  << endl;
	  if(front[i] > real.front[i])
	    {
	      return true;
	    }
	  if(front[i] < real.front[i])
	    {
	      return false;
	    }
	}
      //BACK CHECK
     //if this.size.back is biger then real.size
      if(back.size() > real.back.size())
	{
	  for(int b = 1; b < back.size(); b ++)
	    {
	      if(back[b] > real.back[b])
		{
		  return true;
		}
	      if(back[b] < real.back[b])  
		{
		  return false;
		}
	      //else there equal continue looping
	    }
	  return true;
	}
      
      //BACK CHECK
      //if this.size.back is smaller then real.size
      if(real.back.size() >= back.size())
	{
	  for(int r = 1; r < real.back.size(); r ++)
	    {
	      if(back[r] > real.back[r])
		{
		  return true;
		}
	      if(back[r] < real.back[r])
		{
		  return false;
		}
	    }
	  return false;
	}
    }//END OF BOTH NEGATIVE
  
  
  //BOTH ARE POSITIVE
  if(real.negative == false && negative == false)
    {
      if(front.size() > real.front.size())
	{
	  return false;
	}
      
      if(front.size() < real.front.size())
	{
	  return true;
	}
      
      //they have equal number of digits
      for(int i = 0; i < front.size(); i ++)
	{
	  if(front[i] < real.front[i])
	    {
	      return true;
	    }
	  if(front[i] > real.front[i])
	    {
	      return false;
	    }
	}
          
  //BACK CHECK POSITIVE
  //if this.size.back is biger then real.size
  if(back.size() > real.back.size())
    {
      for(int b = 1; b < back.size(); b ++)
	{
	  if(back[b] > real.back[b])
	    {
	      return false;
	    }
	  if(back[b] < real.back[b])
	    {
	      return true;
	    }
	  //else there equal continue looping
	}
      return false;
    }
  
  //BACK CHECK POSITIVE
  //if this.size.back is smaller then real.size
  if(real.back.size() >= back.size())
    {
      for(int r = 1; r < real.back.size(); r ++)
	{
	  if(back[r] >real.back[r])
	    {
	      return false;
	    }
	  if(back[r] < real.back[r])
	    {
	      return true;
	    }
	}
      return false;
    }
  
    }//END of both positive
  
  //THEY ARE EQUAL!
  return false;
 
}

bool Real::operator >  (const Real & real ) const
{
  return (!(*this < real) && (!(*this == real)));
}

bool Real::operator <= (const Real & real) const
{
  if((*this < real) == true || (real == *this) == true)
    return true;
  else
    return false;
}

bool Real::operator >= (const Real & real) const
{
  if(!(*this < real) || (real == *this))
    return true;
  else
    return false;
}

bool Real::operator == (const Real & real) const
{
  if(((*this < real) == false) && ((real < *this) == false))
    return true;
  else
    return false;
}

bool Real::operator != (const Real & real) const
{
  if(real == *this)
    return false;
  else
    return true;
}

Real Real::operator +  (const Real & real) const  //This function has to return a real type!
{
  vector <char> real_helper_back; //for my helper
  vector <char> real_helper_front; //for my helper
  vector <char> this_helper_back; //for my helper
  vector <char> this_helper_front; //for my helper
  bool real_is_bigger = false;

  if(real.front.size() > front.size())
    {
      real_is_bigger =true;

    }
  
  
  if(real.front.size() == front.size())
    {
      for(int i =0; i < real.front.size(); i ++)
	{
	  if(real.front[i] == front[i])
	    {
	      continue;
	    }
	  if(real.front[i] > front[i])
	    {
	      real_is_bigger = true;
	      break;
	    }
	  if(real.front[i] < front[i])
	    {
	      real_is_bigger = false;
	      break;
	    }
	  
	}
    }
  
  real_helper_back = real.back;
  real_helper_front = real.front;
  this_helper_back = back;
  this_helper_front = front;

  if(real.front.size() == 0 || ((real.front.size() == 1 ) && ( real.front[0] == '-')))
    {
      if(real.front.size() == 0)
	{
	  real_helper_front.push_back('0');
	}
      else
	{
	  real_helper_front.pop_back();
	  real_helper_front.push_back('0');
	  real_helper_front.push_back('-');
	}
    }
  
  if(front.size() == 0 || ((front.size() == 1 ) && ( front[0] == '-')))
    {
      if(real.front.size() == 0)
	{
	  this_helper_front.push_back('0');
	}
      else
	{
	  this_helper_front.pop_back();
	  this_helper_front.push_back('0');
	  this_helper_front.push_back('-');
	}

    }
  
  if(real.back.size() == 0)
    {
      real_helper_back.push_back('.');
      real_helper_back.push_back('0');
    }
  if(back.size() == 0)
    {
      this_helper_back.push_back('.');
      this_helper_back.push_back('0');
    }
  
  /*
  cout << real_helper_front[0] << endl;
  cout << real_helper_front[0] << endl;
  cout << real_helper_back[0] << endl;
  cout << real_helper_back[0] << endl;
  */
    
  string reversed_result = "";
  string result = "";
  reversed_result = add_Helper(this_helper_front, this_helper_back, real_helper_front, real_helper_back, real_is_bigger);
  //aswer is backwards now flip it and call the string Real constructor
  for(int i = reversed_result.length(); i > 0; i--)
    {
      result += reversed_result[i]; 
    }
  Real answer(result);
  return answer;  

}

Real Real::operator -  (const Real & real) const
{
  vector <char> real_helper_back; //for my helper
  vector <char> real_helper_front; //for my helper
  vector <char> this_helper_back; //for my helper
  vector <char> this_helper_front; //for my helper
  bool real_is_bigger = false;
  bool add_helper =false;
  real_helper_back = real.back;
  real_helper_front = real.front;
  this_helper_back = back;
  this_helper_front = front;



  if(real.front.size() > front.size())
    {
      real_is_bigger =true;

    }


  if(real.front.size() == front.size())
    {
      for(int i =0; i < real.front.size(); i ++)
	{
	  if(real.front[i] == front[i])
	    {
	      continue;
	    }
	  if(real.front[i] > front[i])
	    {
	      real_is_bigger = true;
	      break;
	    }
	  if(real.front[i] < front[i])
	    {
	      real_is_bigger = false;
	      break;
	    }

	}
    }

  
  if(real.front.size() == 0 || ((real.front.size() == 1 ) && ( real.front[0] == '-')))
    {
      if(real.front.size() == 0)
	{
	  real_helper_front.push_back('0');
	}
      else
	{
	  real_helper_front.pop_back();
	  real_helper_front.push_back('0');
	  real_helper_front.push_back('-');
	}
    }

  if(front.size() == 0 || ((front.size() == 1 ) && ( front[0] == '-')))
    {
      if(real.front.size() == 0)
	{
	  this_helper_front.push_back('0');
	}
      else
	{
	  this_helper_front.pop_back();
	  this_helper_front.push_back('0');
	  this_helper_front.push_back('-');
	}
      
    }
  if(real.back.size() == 0)
    {
      real_helper_back.push_back('.');
      real_helper_back.push_back('0');
    }
  if(back.size() == 0)
    {
      this_helper_back.push_back('.');
      this_helper_back.push_back('0');
    }

  string reversed_result = "";
  string result = "";
  reversed_result = subtract_Helper(this_helper_front, this_helper_back, real_helper_front, real_helper_back, real_is_bigger, add_helper);
  //aswer is backwards now flip it and call the string Real constructor
  for(int i = reversed_result.length(); i > 0; i--)
    {
      result += reversed_result[i];
    }
  Real answer(result);
  return answer;
   
}

Real Real::operator *  (const Real & real) const
{ // This function has to return a real type!
  /*
  vector <char> mult_result; 
  string result = "";
  bool carry = false;

  string back_result = "";
  string front_result = "";
  if(*this > real)
    {
      for(int i = real.back.size() -1; i < 0; i++)
	{
	  for( int j = back.size() - 1; i++)
	    {
	      backresult += floor (real.back[i] * back[j]);
	    }
	}
    }

  if(*this <= real)
    {

    }
  */
  
  return *this; 
}

Real Real::operator /  (const Real & real) const
{ // This function has to return a real type!
  return *this; 
}

Real & Real::operator  = (const Real & real)
{
  if(*this == real)
    return *this;
  front.clear();
  back.clear();
  negative = real.negative;
  carry = false;
  backside = false;
  
  for(int i = 0; i < real.front.size(); i++)
    {
      front.push_back(real.front[i]);
    }
  for(int i = 0; i < real.back.size(); i++)
    {
      back.push_back(real.back[i]);
    }
  
  return *this;
}
//adds one real to another and stores back in the orignial real
Real Real::operator += (const Real & real)
{ // This function has to return a real type!
  *this = *this + real;
  return *this; 
}
// subtracts one real from another and stores in the original real
Real Real::operator -= (const Real & real)
{ // This function has to return a real type!
  *this = *this - real;
  return *this; 
}
//times one real to another and stores back in original real
Real Real::operator *= (const Real & real)
{ // This function has to return a real type!
  return *this; 
}
//divides on real to another and stores back into the orginal real
Real Real::operator /= (const Real & real)
{ // This function has to return a real type!
  return *this; 
}


bool Real::negative_check(std::string  string_to_check)
{
  if(string_to_check[0] == '-')
    return true;
  else
    return false;
}

void Real::remove_negative()
{
  if(front[0] != '-')
    return; 
  reverse(front.begin(), front.end());
  front.pop_back();
  reverse(front.begin(), front.end());
  
}

void Real::add_negative()
{
  reverse(front.begin(), front.end());
  front.push_back('-');
  reverse(front.begin(), front.end());
}

void Real::set_Neg(bool sn)
{
  negative = sn;
}

string add_Helper(vector<char> tf, vector<char> tb,vector<char> rf,vector<char> rb, bool real_is_bigger)
{
  // reversed_result = add_Helper(this_helper_front, this_helper_back, real_helper_front, real_helper_back, real_is_bigger);
  string string_result = "";
  bool this_negative_helper = false;
  bool real_negative_helper = false;
  bool carry = false;
  bool add_flag =false;
  int real_backsize = rb.size() -1;
  int this_backsize = rf.size() -1;
  
  if(tf.size() > 0 && tf[0] == '-' )
    {
      this_negative_helper = true;
    }
  if(rf.size() > 0 && rf[0] == '-' )
    {
      real_negative_helper = true;
    }
  //call the negative helper if one positve other negative
  if(this_negative_helper == true && real_negative_helper == false)
    {
      add_flag = true;
      string_result = subtract_Helper(tf,tb,rf,rb,real_is_bigger, add_flag);
      if(real_is_bigger == true)
	{
	  return string_result;
	}
      else
	{
	  string_result += '-';
	  return string_result;
	}
    }
  if(this_negative_helper == false  && real_negative_helper == true)
    {
      add_flag = true;
      string_result = subtract_Helper(tf,tb,rf,rb, real_is_bigger, add_flag);
      if(real_is_bigger == true)
	{
	  string_result += '-';
	  return string_result;
	}
      else
	{
	  return string_result;
	}
    }
  //remove negative to do addition
  if(tf[0] == '-' )
    {
      reverse(tf.begin(), tf.end());
      tf.pop_back();
      reverse(tf.begin(), tf.end());
    }
  if(rf[0] == '-' )
    {
      reverse(rf.begin(), rf.end());
      rf.pop_back();
      reverse(rf.begin(), rf.end());
    }

  
  //add padding
  //PADDING FOR ALL POSITIVE AND NEGATIVE NUMBERS
  //front
  if(tf.size() > rf.size())
    {
      int temp = tf.size() - rf.size();
      for(int i =0; i < temp; i++)
	{
	  reverse(rf.begin(), rf.end());
	  rf.push_back('0');//insert 0s untill we have an equal front.size for real and this
	  reverse(rf.begin(), rf.end());
	}
    }
  //front #2 this front < real front
  if(tf.size() < rf.size())
    {
      int temp = rf.size() - tf.size();
      for(int i = 0; i < temp; i++)
	{
	  reverse(tf.begin(), tf.end());
	  tf.push_back('0');//insert 0s untill we have an equal front.size for real and this
	  reverse(tf.begin(), tf.end());
	}
    }
  //PADING BACK FOR ANY POSITVE OR NEGATIVE NUMBER
  //back dont need to check for negatives
  //back 1
  if(tb.size() > rb.size())
    {
      int temp = tb.size() - rb.size();
      for(int i =0; i < temp; i++)
	{
	  rb.push_back('0');//insert 0s untill we have an equal front.size for real and this
	}
    } 
  //back 2
  if(tb.size() < rb.size())
    {
      int temp = rb.size() - tb.size();
      for(int i =0; i < temp; i++)
	{
	  tb.push_back('0');//insert 0s untill we have an equal front.size for real and this
	}
    }
  //after we have padded 
  //PADDING FINISHED
  //update temps
  real_backsize = rb.size() -1;
  this_backsize = tb.size() -1;
  carry == false;
  //CALCULATIONS OF TWO POSITIVE OR TWO NEGATIVES, this and real
  //push back to vector result
  if((this_negative_helper == false && real_negative_helper == false) || (this_negative_helper == true && real_negative_helper == true))
    {
      for(int i = rb.size(); i > 0; i--)
	{
	  int number = ((tb[i] - '0') + (rb[i] - '0'));
	  if(carry == true)
	    {
	      number += 1;
	    }
	  if(number >= 10)
	    {
	      carry = true;
	      char number2 = ((number - 10) + '0');
	      string_result += number2;
	      //result.back.push_back(number2);
	    }
	  if(number < 10)
	    {
	      carry = false;
	      char number2 = number + '0';
	      string_result += number2;
	      //result.back.push_back(number2);     
	    }
	}
      string_result += '.';
      //result.back.push_back('.');//push the d
      //reverse(result.back.begin(), result.back.end());
      for(int i = tf.size() - 1; i >= 0; i--)
	{
	  int number = ((tf[i] - '0') + (rf[i] - '0'));; 
	  if(carry == true)
	    {
	      number += 1;
	    }
	  if(number >= 10)
	    {
	      carry = true;
	      char number2 = ((number - 10) + '0');
	      string_result += number2;
	      // result.front.push_back(number2);
	    }
	  if(number < 10)
	    {
	      carry = false;
	      char number2 = number + '0';
	      //result.front.push_back(number2);
	      string_result += number2;
	    }
	  if(i == 0 && carry ==true)
	    {
	      //result.front.push_back('1');
	      string_result += '1';
	    }
	}
    }
  if(this_negative_helper == true && real_negative_helper == true)
    {
      string_result += '-';
    }
  
  return string_result;
}

string subtract_Helper(vector<char> tf, vector<char> tb, vector<char> rf, vector<char> rb, bool real_is_bigger, bool add_flag)
{
  string string_result = "";
  bool carry = false;
  bool this_negative = false;
  bool real_negative = false;
  int real_backsize = rb.size() -1;
  int this_backsize = tb.size() -1;

  if(add_flag == true)
    {
      this_negative = false;
      real_negative = false;
    }
  else
    {
      //set negative booleans flags
      if(tf[0] == '-' )
	{
	  this_negative = true;
	}
      if(rf[0] == '-' )
	{
	  real_negative = true;
	}
    }
  //T - - R//call add
  if(this_negative == false && real_negative== true)
    {
      //   cout << " (T - - R) " <<  "PASS TO ADD" << endl;
      reverse(rf.begin(), rf.end());
      rf.pop_back();
      reverse(rf.begin(), rf.end());
      //remove rf - sign and call add
      string_result = add_Helper(tf,tb,rf,rb,real_is_bigger);
      return string_result;
    }
  //(- T - R)//call add
  if(this_negative == true  && real_negative == false)
    {
      //  cout << " (- T - R) " << "PASS TO ADD " << endl;
      reverse(tf.begin(), tf.end());
      tf.pop_back();
      reverse(tf.begin(), tf.end());
      string_result = add_Helper(tf,tb,rf,rb,real_is_bigger);
      return string_result;
    }
 
  if(tf[0] == '-' )
    {
      reverse(tf.begin(), tf.end());
      tf.pop_back();
      reverse(tf.begin(), tf.end());
    }
  if(rf[0] == '-' )
    {
      reverse(rf.begin(), rf.end());
      rf.pop_back();
      reverse(rf.begin(), rf.end());
    }
  //add padding
  //PADDING FOR ALL POSITIVE AND NEGATIVE NUMBERS
  //front
  if(tf.size() > rf.size())
    {
      int temp = tf.size() - rf.size();
      for(int i =0; i < temp; i++)
	{
	  reverse(rf.begin(), rf.end());
	  rf.push_back('0');//insert 0s untill we have an equal front.size for real and this
	  reverse(rf.begin(), rf.end());
	}
    }
  //front #2 this front < real front
  if(tf.size() < rf.size())
    {
      int temp = rf.size() - tf.size();
      for(int i = 0; i < temp; i++)
	{
	  reverse(tf.begin(), tf.end());
	  tf.push_back('0');//insert 0s untill we have an equal front.size for real and this
	  reverse(tf.begin(), tf.end());
	}
    }
  //PADING BACK FOR ANY POSITVE OR NEGATIVE NUMBER
  //back dont need to check for negatives
  //back 1
  if(tb.size() > rb.size())
    {
      int temp = tb.size() - rb.size();
      for(int i =0; i < temp; i++)
	{
	  rb.push_back('0');//insert 0s untill we have an equal front.size for real and this
	}
    }
  //back 2
  if(tb.size() < rb.size())
    {
      int temp = rb.size() - tb.size();
      for(int i =0; i < temp; i++)
	{
	  tb.push_back('0');//insert 0s untill we have an equal front.size for real and this
	}
    }
  //after we have padded
  //PADDING FINISHED
  //update temps
  real_backsize = rb.size() -1;
  this_backsize = tb.size() -1;
  /*  
  cout << endl;
  for(int i =0; i < tf.size(); i++)
    {
      cout << tf[i];
    }
  for(int i =0; i < tb.size(); i++)
    {
      cout << tb[i];
    }
  cout << endl;
  for(int i =0; i < rf.size(); i++)
    {
      cout << rf[i];
    }
  for(int i =0; i < rb.size(); i++)
    {
      cout << rb[i];
    }
  cout << endl;
  */
///////////////////////////////////////////////////////////////
  // - T - -R  //sub CASE3
  
  if(real_negative == true && this_negative == true)
    {
      
      if(real_is_bigger == false)
	{
	  for(int i = rb.size() - 1; i >  0; i--)
	    {
	      int number = ((tb[i] - '0') - (rb[i] - '0'));
	      // cout << "number at begining of loop :" << number << endl << endl;
	      //means we borrowed from earlier than this spot
	      if(carry ==true && tb[i] == '0')
		{
		  //		  cout << "front number : " << number << endl;
		  char number2 = (number + 9) + '0';
		  //cout << "number to be pushed front to back: " <<number2 << endl;
		  carry = true;
		  string_result += number2;
		}

	      if(carry == true && tb[i] != '0')
		{
		  number -= 1;
		  if(number < 0)
		    {
		      //   cout << "front number : " << number << endl;
		      char number2 = (number + 10) + '0';
		      //cout << "number to be pushed front: " <<number2 << endl;
		      carry = true;
		      string_result += number2;
		      //result.back.push_back(number2);
		    }
		  if(number >= 0)
		    {
		      char number2 = (number + '0');
		      //cout << "number to be pushed front: " <<number2 << endl;
		      //result.back.push_back(number2);
		      string_result += number2;
		      carry = false;
		    }
		}
	      if(number < 0 && carry == false)
		{
		  //cout << "front number : " << number << endl;
		  char number2 = (number + 10) + '0';
		  //cout << "number to be pushed front: " <<number2 << endl;
		  carry = true;
		  string_result += number2;
		  //result.back.push_back(number2);
		}

	      if(number >= 0 && carry == false)
		{
		  // cout << "front number : " << number << endl;
		  carry = false;
		  char number2 = (number + '0');
		  // cout << "number to be pushed front: " <<number2 << endl;
		  string_result += number2;
		  // result.back.push_back(number2);
		}
	    }
	  //adding the decimal
	  string_result += '.';
	  //cout << endl << endl << "FRONT" << endl;
	  //FRONT
	  for(int i = rf.size() - 1; i >= 0; i--)
	    {
	      bool keepgoing = false;
	      int number = ((tf[i] - '0') - (rf[i] - '0'));
	      //cout << "number at begining of loop :" << number << endl << endl;
	      //means we borrowed from earlier than this spot
	      if(carry ==true && rf[i] == '0' &&  i + 1 == rf.size())
		{
		  //  cout << "IF1" << endl;
		  // cout << "number : " << number << endl;
		  char number2 = (number + 9) + '0';
		  // cout << "number to be pushed: " <<number2 << endl;
		  carry = true;
		  string_result += number2;
		  //result.front.push_back(number2);
		}
	      if(carry ==true && rf[i] == '0' &&  i + 1 != rf.size())
		{
		  //  cout << "IF2" << endl;
		  // cout << "number : " << number << endl;
		  if(i == 0)
		    {
		      char number2 = (number - 1) +'0';
		      string_result += number2;
		    }
		  else
		    {
		      char number2 = (number + 9) + '0';
		      // cout << "number to be pushed: " <<number2 << endl;
		      carry = true;
		      string_result +=number2;
		      //result.front.push_back(number2);
		    }
		}
	      if(number >= 0 && carry == false)
		{
		  // cout << "IF3" << endl;
		  //cout << "number : " << number << endl;
		  carry = false;
		  char number2 = (number + '0');
		  // cout << "number to be pushed: " <<number2 << endl;
		  //result.front.push_back(number2);
		  string_result += number2;
		}
	      if(number < 0 && carry == false)
		{
		  //cout << "IF4" << endl;
		  //cout << "number : " << number << endl;
		  char number2 = (number + 10) + '0';
		  //cout << "number to be pushed: " <<number2 << endl;
		  carry = true;
		  keepgoing =true;
		  //result.front.push_back(number2);
		  string_result += number2;
		}                                                                   
	      if(carry == true && rf[i] != '0' && keepgoing ==false)
		{
		  if(number < 0)
		    {
		      // cout << "IF5" << endl;
		      // cout << "number : " << number << endl;
		      char number2 = ((number - 1) + 10) + '0';
		      //cout << "number to be pushed: " <<number2 << endl;
		      carry = true;
		      string_result += number2;
		      //result.front.push_back(number2);
		    }
		  if(number >= 0)
		    {
		      // cout << "IF6" << endl;
		      //cout << "number : " << number << endl;
		      char number2 = ((number - 1) + '0');
		      //  cout << "number to be pushed: " <<number2 << endl;
		      string_result += number2;
		      //result.front.push_back(number2);
		      carry = false;
		    }
		  
		}                                                             
	    }
	  //result.negative =false;
	  return string_result;
	}
      if(real_is_bigger == true)
	{
	  for(int i = real_backsize; i >= 1; i--)
	    {
	      // cout << "BACK " << endl;
	      int number = ((rb[i] - '0') - (tb[i] - '0'));
	      //cout << "number at begining of loop :" << number << endl << endl;
	      //means we borrowed from earlier than this spot
	      if(carry == true && rb[i] == '0')
		{
		  //   cout << "front number : " << number << endl;
		  char number2 = (number + 9) + '0';
		  // cout << "number to be pushed front to back: " <<number2 << endl;
		  carry = true;
		  string_result += number2;
		  //result.back.push_back(number2);
		}
	      
	      if(carry == true && rb[i] != '0')
		{
		  number -= 1;
		  if(number < 0)
		    {
		      //cout << "front number : " << number << endl;
		      char number2 = (number + 10) + '0';
		      //cout << "number to be pushed front: " <<number2 << endl;
		      carry = true;
		      string_result += number2;
		      //result.back.push_back(number2);
		    }
		  if(number >= 0)
		    {
		      char number2 = (number + '0');
		      //cout << "number to be pushed front: " <<number2 << endl;
		      string_result += number2;
		      //result.back.push_back(number2);
		      carry = false;
		    }
		}
	      if(number < 0 && carry == false)
		{
		  //cout << "front number : " << number << endl;
		  char number2 = (number + 10) + '0';
		  //cout << "number to be pushed front: " <<number2 << endl;
		  carry = true;
		  string_result += number2;
		  //result.back.push_back(number2);
		}
	      
	      if(number >= 0 && carry == false)
		{
		  //  cout << "front number : " << number << endl;
		  carry = false;
		  char number2 = (number + '0');
		  // cout << "number to be pushed front: " <<number2 << endl;
		  //result.back.push_back(number2);
		  string_result += number2;
		}
	    }
	  string_result += '.';
	  // cout << endl << endl << "FRONT" << endl;
	  //FRONT
	  for(int i = rf.size() - 1; i >= 0; i--)
	    {
	      // cout << "FRONT " << endl;
	      bool keepgoing = false;
	      int number = ((rf[i] - '0') - (tf[i] - '0'));
	      //cout << "number at begining of loop :" << number << endl << endl;
	      //means we borrowed from earlier than this spot
	      if(carry ==true && tf[i] == '0' &&  i + 1 == tf.size())
		{
		  // cout << "IF1" << endl;
		  // cout << "number : " << number << endl;
		  char number2 = (number + 9) + '0';
		   // cout << "number to be pushed: " <<number2 << endl;
		  carry = true;
		  string_result += number2;
		  //result.front.push_back(number2);
		}
	      if(carry ==true && tf[i] == '0' &&  i + 1 != tf.size())
		{
		  //cout << "IF2" << endl;
		  //cout << "number : " << number << endl;
		  char number2 = (number + 9) + '0';
		  // cout << "number to be pushed: " <<number2 << endl;
		  carry = true;
		  //result.front.push_back(number2);
		  string_result += number2;
		}
	      if(number >= 0 && carry == false)
		{
		  //cout << "IF3" << endl;
		  // cout << "number : " << number << endl;
		  carry = false;
		  char number2 = (number + '0');
		  // cout << "number to be pushed: " <<number2 << endl;
		  //result.front.push_back(number2);
		  string_result += number2;
		}
		
	      if(number < 0 && carry == false)
		{
		  //cout << "IF4" << endl;
		  //cout << "number : " << number << endl;
		  char number2 = (number + 10) + '0';
		  // cout << "number to be pushed: " <<number2 << endl;
		  carry = true;
		  keepgoing =true;
		  //result.front.push_back(number2);
		  string_result += number2;
		}                                                                   
	      if(carry == true && tf[i] != '0' && keepgoing ==false)
		{
		  if(number < 0)
		    {
		      //cout << "IF5" << endl;
		      //cout << "number : " << number << endl;
		      char number2 = ((number - 1) + 10) + '0';
		      // cout << "number to be pushed: " <<number2 << endl;
		      carry = true;
		      //result.front.push_back(number2);
		      string_result += number2;
		    }
		  if(number >= 0)
		    {
		      // cout << "IF6" << endl;
		      // cout << "number : " << number << endl;
		      char number2 = ((number - 1) + '0');
		      // cout << "number to be pushed: " <<number2 << endl;
		      //result.front.push_back(number2);
		      string_result += number2;
		      carry = false;
		    }
		  
		}                                                             
	    }
	  if(add_flag == true)
	    {
	      return string_result;
	    }
	  else
	    {
	      string_result += '-';
	      //result.negative =true;
	      return string_result;
	    }
	}
    }

  /////////////////////////////LAST CASE//////////////////
  if(real_negative == false && this_negative == false)
    {
      //       cout << "REAL NEG AND THIS NOT  T - R " << rf[0]<< endl; 
      // cout << "T - R" << endl;
      if(real_is_bigger == false)
	{
	  for(int i = real_backsize; i >= 1; i--)
	    {
	      int number = ((tb[i] - '0') - (rb[i] - '0'));
	      // cout << "number at begining of loop :" << number << endl << endl;
	      //means we borrowed from earlier than this spot
	      if(carry == true && tb[i] == '0')
		{
		  // cout << "front number : " << number << endl;
		  char number2 = (number + 9) + '0';
		  //cout << "number to be pushed front to back: " <<number2 << endl;
		  carry = true;
		  //result.back.push_back(number2);
		  string_result += number2;
		}
	      
	      if(carry == true && tb[i] != '0')
		{
		  number -= 1;
		  if(number < 0)
		    {
		      //cout << "front number : " << number << endl;
		      char number2 = (number + 10) + '0';
		      // cout << "number to be pushed front: " <<number2 << endl;
		      carry = true;
		      string_result += number2;
		      //result.back.push_back(number2);
		    }
		  if(number >= 0)
		    {
		      char number2 = (number + '0');
		      //  cout << "number to be pushed front: " <<number2 << endl;
		      //result.back.push_back(number2);
		      string_result += number2;
		      carry = false;
		    }
		}
	      if(number < 0 && carry == false)
		{
		  //  cout << "front number : " << number << endl;
		  char number2 = (number + 10) + '0';
		  // cout << "number to be pushed front: " <<number2 << endl;
		  carry = true;
		  string_result += number2;
		  //result.back.push_back(number2);
		}

	      if(number >= 0 && carry == false)
		{
		  // cout << "front number : " << number << endl;
		  carry = false;
		  char number2 = (number + '0');
		  // cout << "number to be pushed front: " <<number2 << endl;
		  string_result += number2;
		  //result.back.push_back(number2);
		}
	    }
	  //adding the decimal
	  string_result += '.';

	  //	  cout << endl << endl << "FRONT" << endl;
	  //FRONT
	  for(int i = rf.size() - 1; i >= 0; i--)
	    {
	      bool keepgoing = false;
	      int number = ((tf[i] - '0') - (rf[i] - '0'));
	      // cout << "number at begining of loop :" << number << endl << endl;
	      //means we borrowed from earlier than this spot

	      if(carry == true &&  tf[i] == '0' && i + 1 == rf.size())
		{
		  //	  cout << "IF1" << endl;
		  // cout << "number : " << number << endl;
		  // cout << number << endl;
		  char number2 = (number + 9) + '0';
		  // cout << "number to be pushed: " <<number2 << endl;
		  carry = true;
		  string_result += number2;
		  //result.front.push_back(number2);
		}
	      if(carry ==true && rf[i] == '0' )
		{
		  // cout << "IF2" << endl;
		  // cout << "number : " << number << endl;
		  if(i  == 0)
		    {
		      char number2 = (number - 1/* + 9*/) + '0';
		      string_result += number2;
		    }
		  else
		    {
		      char number2 = (number + 9) + '0';
		      //    cout << "number to be pushed: " <<number2 << endl;
		      carry = true;
		      string_result += number2;
		    }
		  //result.front.push_back(number2);
		}
	      if(number >= 0 && carry == false)
		{
		  // cout << "IF3" << endl;
		  // cout << "number : " << number << endl;
		  carry = false;
		  char number2 = (number + '0');
		  // cout << "number to be pushed: " <<number2 << endl;
		  string_result += number2;
		  //result.front.push_back(number2);
		}

	      if(number < 0 && carry == false)
		{
		  // cout << "IF4" << endl;
		  // cout << "number : " << number << endl;
		  char number2 = (number + 10) + '0';
		  // cout << "number to be pushed: " <<number2 << endl;
		  carry = true;
		  keepgoing =true;
		  string_result += number2;
		  //result.front.push_back(number2);
		}                                                                   
	      if(carry == true && rf[i] != '0' && keepgoing ==false)
		{
		  if(number < 0)
		    {
		      //     cout << "IF5" << endl;
		      // cout << "number : " << number << endl;
		      char number2 = ((number - 1) + 10) + '0';
		      // cout << "number to be pushed: " <<number2 << endl;
		      carry = true;
		      string_result += number2;
		      //result.front.push_back(number2);
		    }
		  if(number >= 0)
		    {
		      //cout << "IF6" << endl;
		      //cout << "number : " << number << endl;
		      char number2 = ((number - 1) + '0');
		      //cout << "number to be pushed: " <<number2 << endl;
		      string_result += number2;
		      //result.front.push_back(number2);
		      carry = false;
		    }

		}                                                             
	    }
	  //result.negative = false;
	  return string_result;
	}
      
      if(real_is_bigger == true)
	{
	  for(int i = real_backsize; i >= 1; i--)
	    {
	      int number = ((rb[i] - '0') - (tb[i] - '0'));
	      // cout << "number at begining of loop :" << number << endl << endl;
	      //means we borrowed from earlier than this spot
	      if(carry ==true && rb[i] == '0')
		{
		  // cout << "front number : " << number << endl;
		  char number2 = (number + 9) + '0';
		  // cout << "number to be pushed front to back: " <<number2 << endl;
		  carry = true;
		  string_result += number2;
		  //result.back.push_back(number2);
		}
	      
	      if(carry == true && rb[i] != '0')
		{
		  number -= 1;
		  if(number < 0)
		    {
		      // cout << "front number : " << number << endl;
		      char number2 = (number + 10) + '0';
		      // cout << "number to be pushed front: " <<number2 << endl;
		      carry = true;
		      string_result += number2;
		      //result.back.push_back(number2);
		    }
		  if(number >= 0)
		    {
		      char number2 = (number + '0');
		      // cout << "number to be pushed front: " <<number2 << endl;
		      //result.back.push_back(number2);
		      string_result += number2;
		      carry = false;
		    }
		}
	      if(number < 0 && carry == false)
		{
		  // cout << "front number : " << number << endl;
		  char number2 = (number + 10) + '0';
		  // cout << "number to be pushed front: " <<number2 << endl;
		  carry = true;
		  string_result += number2;
		  //result.back.push_back(number2);
		}
	      
	      if(number >= 0 && carry == false)
		{
		  // cout << "front number : " << number << endl;
		  carry = false;
		  char number2 = (number + '0');
		  // cout << "number to be pushed front: " <<number2 << endl;
		  //result.back.push_back(number2);
		  string_result += number2;
		}
	    }
	  //adding the decimal
	    string_result += '.';
	  
	  // cout << endl << endl << "FRONT" << endl;
	  //FRONT
	  for(int i = rf.size() - 1; i >= 0; i--)
	    {
	      bool keepgoing = false;
	      int number = ((rf[i] - '0') - (tf[i] - '0'));
	      // cout << "number at begining of loop :" << number << endl << endl;
	      //means we borrowed from earlier than this spot
	      if(carry ==true && tf[i] == '0' &&  i + 1 == tf.size())
		{
		  // cout << "IF1" << endl;
		  // cout << "number : " << number << endl;
		  char number2 = (number + 9) + '0';
		  // cout << "number to be pushed: " <<number2 << endl;
		  carry = true;
		  string_result += number2;
		  //result.front.push_back(number2);
		}
	      if(carry ==true && tf[i] == '0' &&  i + 1 != tf.size())
		{
		  if(i == 0)
		    {
		      char number2= (number - 1) + '0';
		      string_result += number2;
		    }
		  else
		    {
		      // cout << "IF2" << endl;
		      // cout << "number : " << number << endl;
		      char number2 = (number + 9) + '0';
		      // cout << "number to be pushed: " <<number2 << endl;
		      carry = true;
		      string_result += number2;
		      //result.front.push_back(number2);
		    }
		}
	      if(number >= 0 && carry == false)
		{
		  // cout << "IF3" << endl;
		  // cout << "number : " << number << endl;
		  carry = false;
		  char number2 = (number + '0');
		  // cout << "number to be pushed: " <<number2 << endl;
		  string_result += number2;
		  //result.front.push_back(number2);
		}
	      
	      if(number < 0 && carry == false)
		{
		  // cout << "IF4" << endl;
		  // cout << "number : " << number << endl;
		  char number2 = (number + 10) + '0';
		  // cout << "number to be pushed: " <<number2 << endl;
		  carry = true;
		  keepgoing =true;
		  string_result += number2;
		  //result.front.push_back(number2);
		}                                                                   
	      if(carry == true && tf[i] != '0' && keepgoing ==false)
		{
		  if(number < 0)
		    {
		      // cout << "IF5" << endl;
		      // cout << "number : " << number << endl;
		      char number2 = ((number - 1) + 10) + '0';
		      // cout << "number to be pushed: " <<number2 << endl;
		      carry = true;
		      string_result += number2;
		      //result.front.push_back(number2);
		    }
		  if(number >= 0)
		    {
		      // cout << "IF6" << endl;
		      // cout << "number : " << number << endl;
		      char number2 = ((number - 1) + '0');
		      // cout << "number to be pushed: " <<number2 << endl;
		      //result.front.push_back(number2);
		      string_result += number2;
		      carry = false;
		    }
		  
		}                                                             
	    }
	  if(add_flag == true)
	    {
	      return string_result;
	    }
	  else
	    {
	      string_result += '-';
	      //result.negative =true;
	      return string_result;
	    }
	}
    }
  
  return string_result;
}
