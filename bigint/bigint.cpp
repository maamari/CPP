#include "bigint.h"
#include <iostream>
using namespace std;

BigInt::BigInt(string s) {
   int l = s.length() - 1;

   for (int i = l; i >= 0 ; i--){
      digits.push_back((int)(s[i] - 48));
   }

   baseB = 10;
}

BigInt::BigInt(string s, int Base) {
   baseB = Base;
   int l = s.length() - 1;

   for (int i = l; i >= 0 ; i--){
      int num = (int)(s[i]);

      if(num - 49 <= 9){
         digits.push_back(num - 48);
      }

      else{
         digits.push_back(num - 55);
      }
   }
}

string BigInt::to_string() {
   string strDig;
   int s = digits.size() - 1;

   for (int i = s; i >= 0; i--){
      int num = (int)(digits[i]);

      if((num >= 0) && (num <= 9)){
         strDig.push_back((char)digits[i] + '0');
      }

      else{
         strDig.push_back((char)digits[i] + '7');
      }
   }
   return strDig;
}

void BigInt::add(BigInt b) {
   int carryOver = 0; int add = 0;

   if(baseB != b.baseB){
      std::cerr << "Unable to add numbers with different bases" << std::endl;
   }
     
   else if(digits.size() > b.digits.size()){
      while(b.digits.size() < digits.size()){
         b.digits.push_back(0);
      }
   }
      
   else if(digits.size() < b.digits.size()){
      while(digits.size() < b.digits.size()){
         digits.push_back(0);
      }
   }

   for (int k = 0; k < digits.size(); k++)  {
      add = digits[k] + b.digits[k] + carryOver;
      digits[k] = add%baseB;
      carryOver = add/baseB;
   }

   if (carryOver > 0){
      digits.push_back(carryOver);
   }
}