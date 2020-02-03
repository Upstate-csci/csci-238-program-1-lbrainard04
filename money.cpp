/********
 Author: Lenae Brainard
 Program: Money class - program assignment #1
 Due Date: February 3, 2020
 Purpose: To design a program to teach employees how to give change
 ********/
// The functions are too long, I know.
// Since I couldn't call previous functions I just copied and pasted what I
// needed from one function to another and added/changed stuff.
#include "money.h"
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

	int hundreds, tens, fives, ones, quarters, dimes, nickels, cents;
	float costFloat;
	string change;
	float changeBack;
	/*
	I had difficulty calling this method so I just didn't use it.
	// convert current currency values to a string
	string Money::toString() {
		cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >>
		nickels >> cents;

		change = (to_string(hundreds)) + " hundreds "  + (to_string(tens)) +
						" tens " + (to_string(fives)) + " fives "  + (to_string(ones)) +
						" ones " + (to_string(quarters)) + " quarters " + (to_string(dimes))
						 + " dimes " + (to_string(nickels)) + " nickels " +
						 (to_string(cents)) + " cents " + "= ";

		return change;
	}
 */
	/* I don't understand the point of this method when
		you could just do a setprecision and add a dollar sign??
		Especially since this program doesn't require to work with other
		currencies.
		I had difficulty calling this method so I just didn't use it.

	// format amount as a local currency and return
	string Money::toCurrency(double amount) {
		stringstream ss;

		ss.imbue(locale(""));
		ss << showbase << put_money(amount*100);
		return ss.str();
	}
	*/

	// convert currency to float
	// read currency values from stdin and compute value
	// return results
	string Money::processChange() {
		cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes
		>> nickels >> cents;

		change = (to_string(hundreds)) + " hundreds "  + (to_string(tens)) +
						" tens " + (to_string(fives)) + " fives "  + (to_string(ones)) +
						" ones " + (to_string(quarters)) + " quarters " + (to_string(dimes))
						 + " dimes " + (to_string(nickels)) + " nickels " +
						 (to_string(cents)) + " cents " + "= ";

		float dollarFormat;
		dollarFormat = hundreds * 100 + tens * 10 + fives * 5 + ones * 1 + quarters
									 * .25 + dimes * .10 + nickels *.05 + cents * .01;

		stringstream currency;
		currency << change << "$" << setprecision(2) << fixed << dollarFormat;

		return currency.str();
	}


	// read from stdin and process float command
	// convert float to change
	// return results
	string Money::processFloat() {

		float floatNum;
		int floorValue;
		int coins;
		cin >> floatNum;

		// find floor value, e.g. floor(432.57) = 432
		// calculate the number of hundreds, tens, fives, and ones
		floorValue = floor(floatNum);
		hundreds = floorValue / 100;
		tens = (floorValue % 100) / 10;
		fives = (floorValue % 10) / 5;
		ones = floorValue % 5;

		// calculating the number of quarters, dimes, nickels, and cents
		// subtract floatValue from the floor value of the floatValue
		// and multiply by 100 to remove decimal
		coins = (floatNum - floorValue) * 100;
		quarters = coins / 25;
		dimes = (coins - (quarters * 25)) / 10;
		nickels = (coins - ((quarters * 25) + (dimes * 10))) / 5;
		cents = (coins - ((quarters * 25) + (dimes * 10) + (nickels * 5))) + 1;

		stringstream changeFormat;
		changeFormat << (to_string(hundreds)) << " hundreds "  << (to_string(tens)) <<
						" tens " << (to_string(fives)) << " fives "  << (to_string(ones)) <<
						" ones " << (to_string(quarters)) << " quarters " << (to_string(dimes))
						 << " dimes " << (to_string(nickels)) << " nickels " <<
						 (to_string(cents)) << " cents " << endl;

		return changeFormat.str();
	}

	/*
	// read from stdin and process check command
	// convert float to dollar words & cents
	// return results
	string Money::processCheck() {
		return "";
	}
 */

	// read from stdin and process change-float command
	// read float of customer payment
	// read float of transaction cost
	// calculate difference and compute change values
	// return the results
	string Money::processChangeFloat() {
		float floatNum;
		cin >> floatNum >> costFloat;

		changeBack = floatNum - costFloat;

		// formatting all these numbers into currency format for the output
		stringstream costCurrency;
		costCurrency << change << "$" << setprecision(2) << fixed << costFloat;
		stringstream floatNumCurrency;
		floatNumCurrency << change << "$" << setprecision(2) << fixed << floatNum;
		stringstream changeBackCurrency;
		changeBackCurrency << change << "$" << setprecision(2) << fixed << changeBack;

		int floorValue;
		int coins;
		int cbHuns, cbTens, cbFives, cbOnes, cbQuarts, cbDimes, cbNicks, cbCents;

		floorValue = floor(changeBack);
		cbHuns = floorValue / 100;
		cbTens = (floorValue % 100) / 10;
		cbFives = (floorValue % 10) / 5;
		cbOnes = floorValue % 5;

		coins = (changeBack - floorValue) * 100;
		cbQuarts = coins / 25;
		cbDimes = (coins - (cbQuarts * 25)) / 10;
		cbNicks = (coins - ((cbQuarts * 25) + (cbDimes * 10))) / 5;
		cbCents = (coins - ((cbQuarts * 25) + (cbDimes * 10) + (cbNicks * 5)));

		string changeFormat = (to_string(cbHuns)) + " hundreds "  + (to_string(cbTens)) +
					 					 " tens " + (to_string(cbFives)) + " fives "  + (to_string(cbOnes)) +
					 					 " ones " + (to_string(cbQuarts)) + " quarters " + (to_string(cbDimes))
					 						+ " dimes " + (to_string(cbNicks)) + " nickels " +
					 						(to_string(cbCents)) + " cents ";


		string changeFloat;
		changeFloat = "Change back on " + floatNumCurrency.str() +
				 					" for a purchase of " + costCurrency.str() + " is " +
				 					changeBackCurrency.str() + " which is ";

		return changeFloat + changeFormat;
	}


	// read from stdin and process change-change command
	// read change of customer payment
	// read float of transaction cost
	// calculate difference and compute change values
	// output the results
	string Money::processChangeChange() {
		float costFloat;
		float changeBack;
		cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes
		>> nickels >> cents >> costFloat;

		float dollarFormat = hundreds * 100 + tens * 10 + fives * 5 + ones * 1 +
							quarters * .25 + dimes * .10 + nickels *.05 + cents * .01;

		changeBack = dollarFormat - costFloat;

		stringstream costCurrency; // to format costFloat in output
		costCurrency << change << "$" << setprecision(2) << fixed << costFloat;

		stringstream changeBackCurrency; // to format changeBack in output
		changeBackCurrency << change << "$" << setprecision(2) << fixed << changeBack;

		string changeChange;
		changeChange = "Change back on " + (to_string(hundreds)) + " hundreds "  +
							(to_string(tens)) + " tens " + (to_string(fives)) + " fives "  +
							(to_string(ones)) + " ones " + (to_string(quarters)) + " quarters "
							+ (to_string(dimes)) + " dimes " + (to_string(nickels)) +
							" nickels " + (to_string(cents)) + " cents " +
							"for a purchase of " + costCurrency.str() + " is " +
							changeBackCurrency.str() + " which is ";

		// couldn't call functions, improvised here:
		int floorValue;
		int coins;
		int cbHuns, cbTens, cbFives, cbOnes, cbQuarts, cbDimes, cbNicks, cbCents;

		floorValue = floor(changeBack);
		cbHuns = floorValue / 100;
		cbTens = (floorValue % 100) / 10;
		cbFives = (floorValue % 10) / 5;
		cbOnes = floorValue % 5;

		coins = (changeBack - floorValue) * 100;
		cbQuarts = coins / 25;
		cbDimes = (coins - (cbQuarts * 25)) / 10;
		cbNicks = (coins - ((cbQuarts * 25) + (cbDimes * 10))) / 5;
		cbCents = (coins - ((cbQuarts * 25) + (cbDimes * 10) + (cbNicks * 5)));

		string changeFormat = (to_string(cbHuns)) + " hundreds "  + (to_string(cbTens)) +
					 					 " tens " + (to_string(cbFives)) + " fives "  + (to_string(cbOnes)) +
					 					 " ones " + (to_string(cbQuarts)) + " quarters " + (to_string(cbDimes))
					 						+ " dimes " + (to_string(cbNicks)) + " nickels " +
					 						(to_string(cbCents)) + " cents ";

		return changeChange + changeFormat;
	}
