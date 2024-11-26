#include <iostream>
#include <vector>
#include <string>

using namespace std;

string intToRoman(int num)
{
    
    vector<pair<int, string>> valueRoman =
    {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
        {1, "I"}
    };

    string result;

    
    for (const auto& [value, roman] : valueRoman)
    {
        while (num >= value)
        {
            result += roman; 
            num -= value;    
        }
    }

    return result;
}


int main()
{
    int num;

    cout << "Enter an integer (1-3999): ";
    cin >> num;

    if (num < 1 || num > 3999)
    {
        cout << "Number out of range!" << endl;
        return 0;
    }

    cout << "Roman numeral: " << intToRoman(num) << endl;

    return 0;
}
