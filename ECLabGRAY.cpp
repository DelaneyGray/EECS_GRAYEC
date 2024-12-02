#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double extractNumeric(const string &str) {
    bool dig = false;
    bool neg = false;
    double result = 0.0;
    
    
    double fractionFactor = 0.1;
    bool inFraction = false;

    for (size_t i = 0; i < str.length(); ++i) {
        char symbol = str[i];

        if (i == 0 && (symbol == '+' || symbol == '-')) {
            neg = (symbol == '-');
        } else if (symbol >= '0' && symbol <= '9') {
            dig = true;
            if (inFraction) {
                result += (symbol - '0') * fractionFactor;
                fractionFactor /= 10.0;
            } else {
                result = result * 10 + (symbol - '0');
            }
        } else if (symbol == '.' && !inFraction) {
            inFraction = true;
        } else {
            return -999999.99;
        }
    }

    if (!dig) {
        return -999999.99;
    }

    return neg ? -result : result;
}

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}
