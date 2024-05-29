#include <iostream>
#include <iomanip>
/*
Collin Ward
cmw0147@auburn.edu
COMP 2710-002
Project1 

A simple program to create an amortization table.
*/

using namespace std;

int main() {
  
   int loanAmount;
   std::cout << "Loan Amount: ";
   std::cin >> loanAmount;
   while (loanAmount < 0) {
      std::cout << "Loan Amount > 0: ";
      std::cin >> loanAmount;
   }
  
   double interestRate;
   std::cout << "Interest Rate ('%' per year): ";
   std::cin >> interestRate;
   while (interestRate < 0) {
      std::cout << "Interest Rate ('%' per year) > 0: ";
      std::cin >> interestRate; 
   }
   
   double monthlyPayment;
   std::cout << "Monthly Payments: ";
   std::cin >> monthlyPayment;
   while (monthlyPayment < (interestRate/12 * loanAmount / 100)) {
      std::cout << "Larger Monthly Payments: ";
      std::cin >> monthlyPayment;
   }

   double balance = loanAmount;
   int month = 0;
   if (loanAmount <= 0 || interestRate <= 0 || monthlyPayment <= 0) {
      return 0;
   } 
   double interestTotal = 0;
 
   std::cout << "********************************************************\n";
   std::cout << "\tAmortization Table\n";
   std::cout << "********************************************************\n";
   std::cout << "Month\tBalance\tPayment\tRate\tInterest\tPrincipal\n";


   std::cout << month << "\t" << balance;
   std::cout << "\t" << "N/A\tN/A\tN/A\t";
   std::cout << "\tN/A\n";

   while (balance > 0) {
      month++;
      double interest = ((interestRate / 12) * balance) / 100;
      interestTotal = interestTotal + interest;
      double principal = monthlyPayment - interest;
   
      if (balance > principal) {
         balance = balance - principal;
      
      } 
      else {
         monthlyPayment = balance + interest;
         principal = balance;
         balance = 0;
      
      }
      std::cout << month << "\t$" << fixed << setprecision(2) << balance << "\t$" << monthlyPayment << "\t" << interestRate / 12 << "\t$" << interest << "\t";
      std::cout << "\t$" << principal << "\n";
   }
   std::cout << "********************************************************\n\n";
   std::cout << "It takes $" << fixed << setprecision(2) << month << " months to pay off the loan.\n";
   std::cout << "Total interest paid is: $" << fixed << setprecision(2) << interestTotal;

   return 0;

}