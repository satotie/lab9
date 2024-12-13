#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double loan , interestrate , payment;

	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> interestrate;
	cout << "Enter amount you can pay per year: ";
	cin >> payment;


	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	int year = 1;
	double prevBalance = loan;
	double interest, total, newBalance;

	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	cout << fixed << setprecision(2); 
    while (prevBalance > 0) {
        interest = prevBalance * (interestrate / 100); 
        total = prevBalance + interest;            

        double currentPayment = (total < payment) ? total : payment;

        newBalance = total - currentPayment;    

        cout << setw(13) << left << year;
        cout << setw(13) << left << prevBalance;
        cout << setw(13) << left << interest;
        cout << setw(13) << left << total;
        cout << setw(13) << left << currentPayment;
        cout << setw(13) << left << newBalance;
        cout << "\n";

        prevBalance = newBalance;
        year++;
    }
	
	return 0;
}
