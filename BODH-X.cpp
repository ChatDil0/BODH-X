// BODH-X.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

string decimalToBinary(double decimal){

    string binary = "";

    int intPart = floor(decimal);
    double fracPart = decimal - intPart;

    while (intPart > 0)
    {
        binary = to_string(intPart % 2) + binary;
        intPart /= 2;
    }

    if (fracPart > 0)
    {
        binary += ".";

        while (fracPart > 0)
        {
            fracPart *= 2;

            if (fracPart >= 1)
            {
                binary += "1";
                fracPart -= 1;
            }
            else
            {
                binary += "0";
            }
        }
    }

    return binary;
}

string decimalToOctal(double decimal) {

    int intPart = int(decimal);
    double fracPart = decimal - intPart;
    int intOct = 0, fracOct = 0;
    int power = 1;

    while (intPart > 0) {
        intOct += (intPart % 8) * power;
        intPart /= 8;
        power *= 10;
    }

    power = 1;
    while (fracPart > 0) {
        fracPart *= 8;
        int temp = int(fracPart);
        fracOct += temp * power;
        fracPart -= temp;
        power /= 10;
    }

    if (fracOct == 0) {
        return to_string(intOct);
    }
    else {
        return to_string(intOct) + '.' + to_string(fracOct);
    }

}

string decimalToHexa(double decimal) {

    int intPart = static_cast<int>(decimal);

    double fracPart = decimal - intPart;

    stringstream ss;
    ss << hex << intPart;
    string hexStr = ss.str();

    ss.str("");
    for (int i = 0; i < 6; i++) {
        fracPart *= 16;
        int hexDigit = static_cast<int>(fracPart);
        ss << hex << hexDigit;
        fracPart -= hexDigit;
    }
    string fracHexStr = ss.str();

    if (fracHexStr == "0") {
        return hexStr;
    }
    else {
        return hexStr + "." + fracHexStr;
    }
}

string binaryToDecimal(double binary)
{

    string binaryNo = to_string(binary);

    int len = binaryNo.length();

    size_t point = binaryNo.find('.');

    if (point == string::npos)
        point = len;

    double intDecimal = 0, fracDecimal = 0, twos = 1;

    for (int i = point - 1; i >= 0; --i)
    {
        intDecimal += (binaryNo[i] - '0') * twos;
        twos *= 2;
    }

    twos = 2;
    for (int i = point + 1; i < len; ++i)
    {
        fracDecimal += (binaryNo[i] - '0') / twos;
        twos *= 2.0;
    }

    return to_string(intDecimal + fracDecimal);
}

string octalToDecimal(double octal) {

    string octalFraction = to_string(octal);

    int decimalWhole = 0;
    double decimalFraction = 0.0;
    int octalPoint = octalFraction.find('.'); 

    for (int i = 0; i < octalPoint; i++) {
        decimalWhole += (octalFraction[i] - '0') * pow(8, octalPoint - i - 1);
    }

    for (int i = octalPoint + 1; i < octalFraction.length(); i++) {
        decimalFraction += (octalFraction[i] - '0') * pow(8, octalPoint - i);
    }

    return to_string(decimalWhole + decimalFraction);
}

double  hexaToDecimal(string hexFraction){

    double result = 0.0;

    int len = hexFraction.length();
    int point = hexFraction.find('.');

    int wholePart = stoi(hexFraction.substr(0, point), 0, 16);

    result += wholePart;

    for (int i = point + 1; i < len; i++) {
        int num = hexFraction[i] - '0';
        if (num > 9) {
            num = tolower(hexFraction[i]) - 'a' + 10;
        }
        double fracPart = num * pow(16, point - i);
        result += fracPart;
    }

    return result;
}

int main(){

    cout << "Decimal\t--> d\nBinary\t--> b\nOctal\t--> o\nHexa\t--> h" <<endl;

    string input;
    char inputBase, outputBase;

    cout << "\nInput\t: ";
    cin >>  input;

    cout << "From\t: ";
    cin >> inputBase;

    cout << "To\t: ";
    cin >> outputBase;

    cout << "Output\t: ";

    if (inputBase == 'd' && outputBase == 'b') {
        double finput = std::stod(input);
        cout << decimalToBinary(finput);
    }
    else if (inputBase == 'd' && outputBase == 'o') {
        double finput = std::stod(input);
        cout << decimalToOctal(finput);
    }
    else if (inputBase == 'd' && outputBase == 'h') {
        double finput = std::stod(input);
        cout << decimalToHexa(finput);
    }
    else if (inputBase == 'b' && outputBase == 'd') {
        double finput = std::stod(input);
        cout << binaryToDecimal(finput);
    }
    else if (inputBase == 'b' && outputBase == 'o') {
        double finput = std::stod(input);
        double decimal = std::stod(binaryToDecimal(finput));
        cout << decimalToOctal(decimal);
    }
    else if (inputBase == 'b' && outputBase == 'h') {
        double finput = std::stod(input);
        double decimal = std::stod(binaryToDecimal(finput));
        cout << decimalToHexa(decimal);
    }
    else if (inputBase == 'o' && outputBase == 'd') {
        double finput = std::stod(input);
        cout << octalToDecimal(finput);
    }
    else if (inputBase == 'o' && outputBase == 'b') {
        double finput = std::stod(input);
        double decimal = std::stod(octalToDecimal(finput));
        cout << decimalToBinary(decimal);
    }
    else if (inputBase == 'o' && outputBase == 'h') {
        double finput = std::stod(input);
        double decimal = std::stod(octalToDecimal(finput));
        cout << decimalToHexa(decimal);
    }
    else if (inputBase == 'h' && outputBase == 'd') {
        cout << hexaToDecimal(input);
    }
    else if (inputBase == 'h' && outputBase == 'b') {
        double decimal = hexaToDecimal(input);
        cout << decimalToBinary(decimal);
    }
    else if (inputBase == 'h' && outputBase == 'o') {
        double decimal = hexaToDecimal(input);
        cout << decimalToOctal(decimal);
    }

    cout << endl;
}

