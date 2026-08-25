#include <iostream>
#include <string>
using namespace std;

int main() {
    string data, divisor, temp;

    cout << "Enter data: ";
    cin >> data;

    cout << "Enter divisor: ";
    cin >> divisor;

    int n = divisor.length();

    // Append n-1 zeros
    temp = data;
    for (int i = 0; i < n - 1; i++)
        temp += '0';

    // CRC division
    for (int i = 0; i <= temp.length() - n; i++) {
        if (temp[i] == '1') {
            for (int j = 0; j < n; j++) {
                temp[i + j] =
                    (temp[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }

    string crc = temp.substr(temp.length() - (n - 1));

    string codeword = data + crc;

    cout << "\nCRC: " << crc;
    cout << "\nTransmitted Codeword: " << codeword << endl;

    return 0;
}