#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string strongString(int input1, string& input2) {
    int guests = input1;
    

    sort(input2.begin(),input2.end());

    string result = "";
    for(int i=input2.size()-4;i>=0;i--)
    {
        result+=input2[i];
    }
    

    return result;
}

int main() {
    int guests = 4;
    std::string input_str = "abacadae";
    std::cout << strongString(guests, input_str) << std::endl;

    return 0;
}
