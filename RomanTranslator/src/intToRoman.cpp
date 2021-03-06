//============================================================================
// Name        : intToRoman.cpp
// Author      : melalonso
// Version     :
// Copyright   : BADSA Corp. All rights reserved.
// Description : Methods for converting integer value to its Roman form.
//============================================================================

#include <iostream>
#include <sstream>

using namespace std;


// Arrays for settting the representation in Roman of integer units, tens and hundreds.
string romanUnits[] = {"I","II","III","IV","V","VI","VII","VIII","IX"};
string romanTens[] = {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
string romanHundreds[] = {"C","CC","CCC","CD","D","DX","DXX","DXXX","CM"};


// This method does the translation from integer value to Roman representation.
// First it tries to do the "big part" that is for numbers bigger than 4000 and uses a special notation.
// After that it does the "small part" that is the traditional representation of not so big numbers(<4000).
// The use of "(" and ")" is to denotate what numbers are being multiplied by 1000.
string intToRoman(long n){
	string roman="";

	/*
	 * 	BIG PART
	 *  Posible big part that uses another notation. (IV)CCC = 4300
	*/
	int bigPart = n / 1000;

	int xAmount = bigPart / 10;
	int lastDigit = bigPart % 10;

    if (xAmount>0) roman += "(";
    while(xAmount--) roman += "X";
    if (lastDigit==0 || lastDigit<4) roman += ")";

    // Checks if the last digit is bigger than 3 to add this beetween the "(" and ")".
    if (lastDigit > 3){
        roman += romanUnits[lastDigit-1];
        roman += ")";
    }else while(lastDigit--) roman += "M";


    /*
     *  SMALL PART
     *  Small part that all numbers have.
    */

	int smallPart = n%1000;
    int x;
	if (smallPart){
        x = smallPart/100;
        if (x) roman += romanHundreds[x-1];
        smallPart = smallPart%100;
        x = smallPart/10;
        if (x) roman += romanTens[x-1];
        x = smallPart%10;
        if (x) roman += romanUnits[x-1];
    }

	return roman;
}

// 15320
// 99800 (X)

/*
int main(){
	cout << intToRoman(1216352173621)<<endl;
}
*/




