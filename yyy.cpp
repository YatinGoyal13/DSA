#include <iostream>
#include <vector>
#include <algorithm>
#include<regex>
using namespace std;

int findMinimumSum(std::vector<int> weights) {
    int sum = 0;

    while (!weights.empty()) {
       
        auto minElement = std::min_element(weights.begin(), weights.end());
        int minIndex = std::distance(weights.begin(), minElement);

        sum += *minElement;

        
        if (minIndex > 0 && minIndex < weights.size() - 1) {
            weights.erase(weights.begin() + minIndex - 1, weights.begin() + minIndex + 2);
        } else if (minIndex == 0 && weights.size() > 1) {
            weights.erase(weights.begin(), weights.begin() + 2);
        } else if (minIndex == weights.size() - 1 && weights.size() > 1) {
            weights.erase(weights.begin() + minIndex - 1, weights.end());
        } else {
            weights.clear();  
        }
    }

    return sum;
}
vector<int> giveids(vector<string> &dd)
{
     std::vector<int> extractedNumbers;

    std::regex pattern("\\d+"); // This regex pattern matches one or more digits

    for (const std::string& str : dd) {
        std::smatch matches;
        if (std::regex_search(str, matches, pattern)) {
            for (auto match : matches) {
                extractedNumbers.push_back(std::stoi(match.str())); // Convert matched string to integer and store in the vector
            }
        }
    }
    return extractedNumbers;
}

int main() {
    vector<int> weights ;
    int n;
    cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     int d;
    //     cin>>d;
    //     weights.push_back(d);
    // }
    // int minimumSum = findMinimumSum(weights);
    // std::cout << "Minimum sum of the lightest products: " << minimumSum << std::endl;
vector<string> dd;
for(int i=0;i<n;i++)
    {
        string d;
        cin>>d;
        dd.push_back(d);
    }
    vector<int> idss=giveids(dd);
    for(int i=0;i<n;i++){
        cout<<idss[i]<<" ";
    }
    return 0;
}
