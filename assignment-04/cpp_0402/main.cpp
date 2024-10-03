#include <iostream>
#include <string>

using namespace std;

string escape_chars(const string& input)
{
    string output;
    for (char ch : input)
    {
        if (ch == '&')
        {
            output += "&amp;";
        } else if (ch == '<')
        {
            output += "&lt;";
        } else if (ch == '>')
        {
            output += "&gt;";
        } else
        {
            output += ch;
        }
    }
    return output;
}


int main()
{
    string input = "Cricket & Smigg are crocs. They like to gape, like so <, "
                   "but when they see flamingos they turn, >, and gape the other way.";
    string escaped = escape_chars(input);
    cout << "Original: " << input << endl;
    cout << "Escaped: " << escaped << endl;
    return 0;
}
