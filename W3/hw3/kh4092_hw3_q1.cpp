//
// Created by Kunhua Huang on 7/24/23.
//
#include <iostream>
using namespace std;

int main()
{
    double priceA, priceB, basePrice, discountPrice, taxRate, totalPrice;
    char clubFlag = 'N';

     cout << "Enter price of first item: ";
     cin >> priceA;

     cout << "Enter price of second item: ";
     cin >> priceB;

     cout << "Does customer have a club card? ";
     cin >> clubFlag;

     cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
     cin >> taxRate;

     basePrice = priceA + priceB;
     cout << "Base price: " << basePrice << endl;

     if (priceA <= priceB)
     {
         priceA *= 0.5;
     }
     else
     {
         priceB *= 0.5;
     }

     basePrice = priceA + priceB;

     if (clubFlag == 'Y' || clubFlag == 'y')
     {
         discountPrice = basePrice * 0.9;
         totalPrice = discountPrice * (1 + taxRate / 100);

         cout << "Price after discounts: " << discountPrice << endl;
         cout << "Total price: " << totalPrice << endl;
     }
     else if (clubFlag == 'N' || clubFlag == 'n')
     {
         totalPrice = basePrice * (1 + taxRate / 100);

         cout << "Total price: " << totalPrice << endl;
     }
     else
     {
         cout << "Invalid input!" << endl;
     }

     return 0;
}