//Shyam Patel
//project1_Patel_sjp0059.cpp
//I used the "hints" in the canvas files
//I used the lecture slides found on canvas to help structure my code
//I used the website stackoverflow to learn how to implement my while loops

#include <iostream>
using namespace std; using std::cin; using std::cout; using std::endl;

int main()  {
//VARIABLES
    int count = 0;
    float loan = 0;
    float interest = 0;
    float interestC = 0;
    float interestR = 0;
    int monthly = 0;

//CURRENCY FORMATTING
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

// USER INPUT
// NOTE: For valid input, the loan, interest, and monthly payment must
// be positive. The monthly payment must also be large enough to
// terminate the loan.
    cout << "\nLoan Amount: ";
    cin >> loan;
    if (loan <= 0) {
        cout << "Invalid Loan";
        return(0);
    }

    cout << "\nInterest Rate (% per year): ";
    cin >> interest;
    if (interest < 0) {
        cout << "Invalid Interest Rate";
        return(0);
    }

// GET PROPER INTEREST RATES FOR CALCULATIONS
    interest /= 12;
    interestC = interest / 100;
    interestR = interestC * loan;
    cout << "\nMonthly Payment: ";
    cin >> monthly;

    if (monthly <= 0) {
        cout << "Invalid Payment";
        return(0);
    }
    if (monthly <= interestR) {
        cout << "Insufficient Payment";
        return(0);
    }
    
    cout << endl;



// AMORTIZATION TABLE
    cout << "*****************************************************************\n"
         << "\tAmortization Table\n"
         << "*****************************************************************\n"
         << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";


    float total = 0;
// LOOP TO FILL TABLE
    while (loan > 0) {
        if (count == 0) {
            cout << count++ << "\t$" << loan;
        if (loan < 1000) cout << "\t"; // Formatting MAGIC
            cout << "\t" << "\tN/A\tN/A\tN/A\t\tN/A\n";
        }
        else {
            float interestP = loan * interestC;
            float principal = monthly - interestP;
            loan -= principal;
            total += interestP;

            if (loan < 0){
                principal += loan;
                monthly += loan;
                loan = 0;
            }

            cout << count++ << "\t$" << loan;

            if (loan < 1000) cout << "\t";
            cout << "\t$" << monthly << "\t" << (interestC * 100) << "\t$" << interestP << "\t\t$" << principal << "\n";            
        }
    }
    cout << "****************************************************************\n";
    cout << "\nIt takes " << --count << " months to pay off "
         << "the loan.\n"
         << "Total interest paid is: $" << total;
    cout << endl << endl;
        return 0;
}