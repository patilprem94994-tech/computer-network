#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string code;

    cout << "Enter received Hamming code: ";
    cin >> code;

    int n = code.length();

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
            cout << setw(4) << ("D" + to_string(position));
    }

    cout << "\n\n";

    int errorPosition = 0;

    
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

        
        if (count % 2 != 0)
        {
            errorPosition += p;
        }
    }

    
    cout << "Parity Check:\n";

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

        cout << "R" << p << " = ";

        if (count % 2 == 0)
            cout << "0 (Even)";
        else
            cout << "1 (Odd)";

        cout << endl;
    }

  

    cout << "\n";

    if (errorPosition == 0)
    {
        cout << "No error detected.\n";
        cout << "Received codeword is CORRECT.\n";
    }
    else if (errorPosition <= n)
    {
        cout << "Error detected!\n";

        cout << "Error position = "
             << errorPosition
             << "\n";

       
        int index = n - errorPosition;

        if (code[index] == '0')
            code[index] = '1';
        else
            code[index] = '0';

        cout << "Corrected codeword = "
             << code << endl;
    }
    else
    {
        cout << "Error position = "
             << errorPosition << endl;

        cout << "Multiple-bit error or invalid Hamming code.\n";
    }

    return 0;
}