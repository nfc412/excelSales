// Excel_Cosentino_Nicholas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>


using namespace std;

fstream excelOutput;
fstream textOutput;

//Function prototypes
double Enter_Double(string);
string Enter_String(string);
int Enter_Int(string);
double retailValue(double, double);


int main() {
	//Variable Declaration
	string partID, partDescription;
	int partQuantity;
	double partWholesalePrice, partMargin;
	string prompt;
	char loopCondition = 'Y';
	double retailPrice;

	//Opening excel text file that can be imported
	ofstream excelOutput;
	excelOutput.open("C:\\Users\\Nicholas\\source\\repos\\Excel_Cosentino_Nicholas\\excelOutput.txt", ios::out);
	if (!excelOutput) {
		cout << "File Unreachable";
		return 0;
	}
	//Openting text file that can be used as input to another program
	ofstream textOutput;
	textOutput.open("C:\\Users\\Nicholas\\source\\repos\\Excel_Cosentino_Nicholas\\textOutput.txt", ios::out);
	if (!textOutput) {
		cout << "File Unreachable";
		return 0;
	}
	//Headings for excel output file
	excelOutput << "Part ID\tPart Description\tParts on Hand\tWholesale Price\tProfit Margin\tRetail Price\n";


	//Main loop for additional data entries
	while (loopCondition == 'Y' || loopCondition == 'y') {
		
		//Prompt that passes to string function
		prompt = "Enter the Part ID: ";
		//Part id input
		partID = Enter_String(prompt);
		
		//Outputs
		cout << partID << '\n';
		textOutput << partID << '\n';
		excelOutput <<partID << "\t";
		//


		//Prompt that passes to string funtion
		prompt = "Enter the Part Description: ";
		//Part description input
		partDescription = Enter_String(prompt);
		
		//Outputs
		cout << partDescription << '\n';
		textOutput << partDescription << '\n';
		excelOutput << partDescription << "\t";
		//



		//Prompt to pass to double function
		prompt = "Enter the quantity on hand: ";
		//Part quantity input
		partQuantity = Enter_Double(prompt);
		
		//Outputs
		cout << partQuantity << '\n';
		textOutput << partQuantity << '\n';
		excelOutput << partQuantity << "\t";
		//



		//Prompt to pass to double funtion
		prompt = "Input the wholesale price: ";
		//Wholesale price input
		partWholesalePrice = Enter_Double(prompt);
		
		//Outputs
		cout << partWholesalePrice << '\n';
		textOutput << partWholesalePrice << '\n';
		excelOutput << partWholesalePrice << "\t";
		//


		//Prompt to pass to double function
		prompt = "Input the profit margin percentage (non decimal form): ";
		//Profit margin input
		partMargin = Enter_Double(prompt);
		
		//Outputs
		cout << partMargin << '\n';
		textOutput << partMargin << '\n';
		excelOutput << partMargin << "\t";
		//

		//Retail price calculation call		
		retailPrice = retailValue(partWholesalePrice, partMargin);
		
		//Output of the retail price with the factors that caused it
		cout << "The retail price is " << retailPrice << " with a wholesale price of " << partWholesalePrice << " and a profit margin of " << partMargin << "." << '\n';
		//Output to excel file
		excelOutput << retailPrice << "\n";






		//Repeat for more input values
		cout << "Would you like to input more parts? [Y] or [N]: ";
		cin >> loopCondition;
	}
	//Closing text file outputs
	textOutput.close();
	excelOutput.close();
}



//Function for inputting string values
string Enter_String(string prompt) {
	string stringValue;

	
	cout << prompt;
	cin >> stringValue;

	return stringValue;

}
//Function for inputting double values
double Enter_Double(string prompt) {
	double doubleValue;

	cout << prompt;
	cin >> doubleValue;

	return doubleValue;
}


//Function for inputting integer values
int Enter_Int(string prompt) {
	int intValue;

	cout << prompt;
	cin >> intValue;

	return intValue;

}
//Function for calculating the retail price with a given wholesale price and the profit margin
double retailValue(double wholesalePrice, double profitMargin) {
	double retailPrice;
	//Converting percent to decimal for calculation
	profitMargin = profitMargin / 100;

	//Calculating the retail price
	retailPrice = wholesalePrice * (1 + profitMargin);
	return retailPrice;


}