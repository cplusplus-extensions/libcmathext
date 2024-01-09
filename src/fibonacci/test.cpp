#include<iostream>
#include"fibonacci.h"

int main(){
   Fibonacci matematico(1);
   int i=1;
   while(i<10){
      std::cout<<matematico.sumEvenFib(i)<<std::endl;
      ++i;
   }
}