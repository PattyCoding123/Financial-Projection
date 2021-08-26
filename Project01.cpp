//==========================================================
//
// Title:      Financial Projection
// Course:     CSC 1101
// Author:     Patrick Ducusin
// Date:       <03/04/2021>
// Description:
//   We will be making a program that will calculate and project
// the finances for a four-unit rental company.
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

int main()
{
  // We will be gathering information from the user to project their finances
  // for a four-unit rental company. We will also be checking their values they
  // enter to make sure they are valid.

  // Declare random number generator
  srand(time(NULL));

  // Declare variables
  double propertyValue;
  double propertyTaxRate;
  double income;
  double expenses;
  double tax;
  double net;
  double incomeTotal;
  double expensesTotal;
  double taxTotal;
  double netTotal;
  int numOfRenters;
  int numOfMonths;
  int i;

  // Declare constants
  const double MONTHLY_RENT = 1000;
  const int MIN_EXPENSE = 500;
  const int MAX_EXPENSE = 2000;
  const int COLWIDTH1 = 15;
  const int COLWIDTH2 = 15;
  const int COLWIDTH3 = 15;
  const int COLWIDTH4 = 15;
  const int COLWIDTH5 = 15;
  const int COLWIDTH6 = 25;
  const int COLWIDTH7 = 15;
  
  // Show the application header
  cout << "Welcome to Financial Projection!" << endl;
  cout << "-----------------------------" << endl << endl;

  // Get user input using validation loops
  // Prompt and get property value from user
  cout << "Enter the property value in thousands (100-1,000): ";
  cin >> propertyValue;
  while (propertyValue < 100 || propertyValue > 1000)
  {
	  cout << "Error: the property value is not between 100 and 1,000 (" << propertyValue << ")" << endl << endl;
	  cout << "Enter the property value in thousands (100-1,000): ";
	  cin >> propertyValue;
  }
  propertyValue = propertyValue * 1000;

  // Prompt and get property tax rate
  cout << endl;
  cout << "Enter the property tax rate (1-7%): ";
  cin >> propertyTaxRate;
  while (propertyTaxRate < 1 || propertyTaxRate > 7)
  {
	  cout << "Error: the property tax rate is not between 1 and 7 (" << propertyTaxRate << ")" << endl << endl;
	  cout << "Enter the property tax rate (1-7%): ";
	  cin >> propertyTaxRate;
  }

  // Prompt and get the number of renters
  cout << endl;
  cout << "Enter the number of renters (0-8): ";
  cin >> numOfRenters;
  while (numOfRenters < 0 || numOfRenters > 8)
  {
	  cout << "Error: the number of renters is not between 0 and 8 (" << numOfRenters << ")" << endl << endl;
	  cout << "Enter the number of renters (0-8): ";
	  cin >> numOfRenters;
  }
  
  // Prompt and get the number of months for projection
  cout << endl;
  cout << "Enter the number of months to project finanaces for (1-36): ";
  cin >> numOfMonths;
  while (numOfMonths < 1 || numOfMonths > 36)
  { 
	  cout << "Error: the number of months is not between 1 and 36 (" << numOfMonths << ")" << endl << endl;
	  cout << "Enter the number of months to project finanaces for (1-36): ";
	  cin >> numOfMonths;
  }
  
  // Display the project parameters
  cout << endl;
  cout << "Projection Parameters" << endl;
  cout << "-------------------------------------------------------------------------------" << endl;
  cout << setw(COLWIDTH6) << left << "Property value ($):" << setw(COLWIDTH7) << right << fixed << setprecision(2) << propertyValue << endl;
  cout << setw(COLWIDTH6) << left << "Property tax rate (%):" << setw(COLWIDTH7) << right << fixed << setprecision(2) << propertyTaxRate << endl;
  cout << setw(COLWIDTH6) << left << "Renters:" << setw(COLWIDTH7) << right << numOfRenters << endl;
  cout << setw(COLWIDTH6) << left << "Months to project:" << setw(COLWIDTH7) << right << numOfMonths << endl;

  // Headers for each column 
  cout << endl;
  cout << "Projection" << endl;
  cout << "-------------------------------------------------------------------------------" << endl;
  cout << setw(COLWIDTH1) << right << "Months" << setw(COLWIDTH2) << right << "Income ($)" << setw(COLWIDTH2) << right << "Expenses ($)" << setw(COLWIDTH2)
	  << right << "Tax ($)" << setw(COLWIDTH2) << right << "Net ($)" << endl;

  // Math for for income and tax
  income = numOfRenters * MONTHLY_RENT;
  tax = propertyValue * (propertyTaxRate / 100) / 12;

  // Initialize each variable
  i = 0;
  incomeTotal = 0;
  expensesTotal = 0;
  taxTotal = 0;
  netTotal = 0;

  // Loop for each month's expenses and net value, i is the month number, and we add each iteration 
  // towards the totals 
  while (i < numOfMonths)
  {
	  expenses = rand() % (MAX_EXPENSE - MIN_EXPENSE + 1) + MIN_EXPENSE;
	  net = income - expenses - tax;
	  incomeTotal = incomeTotal + income;
	  expensesTotal = expensesTotal + expenses;
	  taxTotal = taxTotal + tax;
	  netTotal = netTotal + net;
	  
	  cout << fixed << setprecision(2) << setw(COLWIDTH1) << right << i + 1 << setw(COLWIDTH2) << right << income << setw(COLWIDTH2) << right << expenses
		  << setw(COLWIDTH2) << right << tax << setw(COLWIDTH2) << right << net << endl;
	  
	  
	  i = i + 1;
  }

  // Display totals at the end
  cout << endl;
  cout << "Totals" << endl;
  cout << "-------------------------------------------------------------------------------" << endl;
  cout << setw(COLWIDTH1) << "" << setw(COLWIDTH2) << right << incomeTotal << setw(COLWIDTH2) << right << expensesTotal << setw(COLWIDTH2)
	  << right << taxTotal << setw(COLWIDTH2) << right << netTotal << endl;

  
  // Show the closing application comment
  cout << "\nEnd of Financial Projection!" << endl;
	 
  }
  
