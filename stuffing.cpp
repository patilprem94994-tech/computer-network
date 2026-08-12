#include <iostream>
using namespace std;

int main()
{
    char input[100], output[200];
    int i, j = 0;
    int count = 0;

    cout << "Enter Bit Stream: ";
    cin >> input;

    for (i = 0; input[i] != '\0'; i++)
    {
        output[j] = input[i];
        j++;

        if (input[i] == '1')
        {
            count++;

            if (count == 5)
            {
                output[j] = '0';   // Stuff 0
                j++;
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    output[j] = '\0';

    cout << "Original Bit Stream : " << input << endl;
    cout << "Stuffed Bit Stream  : " << output << endl;

    return 0;
}