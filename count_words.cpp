#include <iostream>
#include <string>

using namespace std;

/*
 * Algorithm Challenge – Level 3 | #36 Count Each Word in a String
 *
 * This program reads a full line of text from the user, then counts how many words exist in the string.
 *
 * The algorithm is based on delimiter-driven string parsing:
 * - A space character is used as a word separator.
 * - Each extracted word increments a counter.
 *
 * This challenge focuses on analytical thinking, string traversal, and accurate state tracking.
 */

// Reads a full line of text from the user
string ReadString()
{
    string Text;
    cout << "Enter a string:\n";
    getline(cin, Text);
    return Text;
}

// Counts the number of words in the given string
short CountWords(string S1)
{
    string Delim = " "; // Delimiter between words (space)
    short Counter = 0;
    short Position = 0;
    string sWord; // Stores each extracted word

    // Use find() to locate each delimiter
    while ((Position = S1.find(Delim)) != string::npos)
    {
        // Extract word before the delimiter
        sWord = S1.substr(0, Position);

        // Count only non-empty words
        if (sWord != "")
        {
            Counter++;
        }

        // Remove processed word and delimiter
        S1.erase(0, Position + Delim.length());
    }

    // Count the last word (no delimiter after it)
    if (S1 != "")
    {
        Counter++;
    }

    return Counter;
}

int main()
{
    string S1 = ReadString();

    cout << "Total words in your string are = ";
    cout << CountWords(S1);

    return 0;
}
