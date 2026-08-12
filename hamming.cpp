#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string data;

    cout << "Enter data bits: ";
    cin >> data;

    int m = data.length();

    // -----------------------------------------
    // Find number of parity bits
    // 2^r >= m + r + 1
    // -----------------------------------------

    int r = 0;

    while ((1 << r) < (m + r + 1))
    {
        r++;
    }

    int n = m + r;

    string code(n, '0');

    // -----------------------------------------
    // Insert data bits WITHOUT changing order
    // -----------------------------------------

    int j = 0;

    // Fill from LEFT to RIGHT
    for (int i = 0; i < n; i++)
    {
        // Position from RIGHT
        int position = n - i;

        // Check whether position is parity position
        if ((position & (position - 1)) == 0)
        {
            // R1, R2, R4, R8...
            continue;
        }

        code[i] = data[j];
        j++;
    }

    // -----------------------------------------
    // Calculate R1, R2, R4, R8...
    // -----------------------------------------

    for (int p = 1; p <= n; p *= 2)
    {
        int count = 0;

        for (int position = 1; position <= n; position++)
        {
            if (position & p)
            {
                int index = n - position;

                if (code[index] == '1')
                {
                    count++;
                }
            }
        }

        // Even parity
        if (count % 2 != 0)
        {
            int index = n - p;
            code[index] = '1';
        }
    }

    // -----------------------------------------
    // Display
    // -----------------------------------------

    cout << "\nData entered      : " << data << endl;

    cout << "\nHamming Code:\n\n";

    cout << "Bit      : ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << code[i];
    }

    cout << "\nType     : ";

    for (int i = 0; i < n; i++)
    {
        int position = n - i;

        if (position == 1)
            cout << setw(4) << "R1";
        else if (position == 2)
            cout << setw(4) << "R2";
        else if (position == 4)
            cout << setw(4) << "R4";
        else if (position == 8)
            cout << setw(4) << "R8";
        else
            cout << setw(4) << "D";
    }

    cout << "\n\n";

    // Display parity bits
    cout << "Parity bits: ";

    for (int p = 1; p <= n; p *= 2)
    {
        int index = n - p;

        cout << "R" << p << "=" << code[index] << " ";
    }

    cout << "\n";

    cout << "Final Hamming Code: " << code << endl;

    return 0;
}