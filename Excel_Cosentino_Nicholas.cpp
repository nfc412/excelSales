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

double Enter_Double(string);
string Enter_String(string);
int Enter_Int(string);
double retailValue(double, double);


int main() {

	string partID, partDescription;
	int partQuantity;
	double partWholesalePrice, partMargin;
	string prompt;
	char loopCondition = 'Y';
	double retailPrice;


	ofstream excelOutput;
	excelOutput.open("C:\\Users\\Nicholas\\source\\repos\\Excel_Cosentino_Nicholas\\excelOutput.txt", ios::out);

	ofstream textOutput;
	textOutput.open("C:\\Users\\Nicholas\\source\\repos\\Excel_Cosentino_Nicholas\\textOutput.txt", ios::out);


	excelOutput << "Part ID\tPart Description\tParts on Hand\tWholesale Price\tProfit Margin\tRetail Price\n";



	while (loopCondition == 'Y' || loopCondition == 'y') {
		//
		prompt = "Enter the Part ID: ";

		partID = Enter_String(prompt);
		
		cout << partID << '\n';
		textOutput << partID << '\n';
		excelOutput <<partID << "\t";
		//


		//
		prompt = "Enter the Part Description: ";

		partDescription = Enter_String(prompt);
		

		cout << partDescription << '\n';
		textOutput << partDescription << '\n';
		excelOutput << partDescription << "\t";
		cin.ignore();
		//



		//
		prompt = "Enter the quantity on hand: ";

		partQuantity = Enter_Double(prompt);
		
		cout << partQuantity << '\n';
		textOutput << partQuantity << '\n';
		excelOutput << partQuantity << "\t";
		//



		//
		prompt = "Input the wholesale price: ";
		
		partWholesalePrice = Enter_Double(prompt);
		
		cout << partWholesalePrice << '\n';
		textOutput << partWholesalePrice << '\n';
		excelOutput << partWholesalePrice << "\t";
		//


		//
		prompt = "Input the profit margin percentage (non decimal form): ";

		partMargin = Enter_Double(prompt);
		
		cout << partMargin << '\n';
		textOutput << partMargin << '\n';
		excelOutput << partMargin << "\t";
		//

		//
		
		retailPrice = retailValue(partWholesalePrice, partMargin);
		
		cout << "The retail price is " << retailPrice << " with a wholesale price of " << partWholesalePrice << " and a profit margin of " << partMargin << "." << '\n';
		excelOutput << retailPrice << "\n";







		cout << "Would you like to input more parts? [Y] or [N]: ";
		cin >> loopCondition;
	}

	textOutput.close();
	excelOutput.close();
}




string Enter_String(string prompt) {
	string stringValue;

	
	cout << prompt;
	cin >> stringValue;

	return stringValue;

}

double Enter_Double(string prompt) {
	double doubleValue;

	cout << prompt;
	cin >> doubleValue;

	return doubleValue;
}



int Enter_Int(string prompt) {
	int intValue;

	cout << prompt;
	cin >> intValue;

	return intValue;

}

double retailValue(double wholesalePrice, double profitMargin) {
	double retailPrice;

	profitMargin = profitMargin / 100;

	retailPrice = wholesalePrice * (1 + profitMargin);
	return retailPrice;


}