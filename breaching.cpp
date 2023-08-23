#include <iostream>
#include <vector>

using namespace std;

vector<int> getNumPoints(vector<int> layers, vector<int> energy, long k) {
    int n = layers.size();
    vector<int> points(n, 0);

    long remainingEnergy = k;
    int totalPoints = 0;

    for (int i = 0; i < n; i++) {
        if (remainingEnergy >= layers[i]) {
            int breachCount = remainingEnergy / layers[i];
            points[i] += breachCount;
            totalPoints += breachCount;
            remainingEnergy -= breachCount * layers[i];
        }
    }

    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        result[i] = totalPoints;
        if (remainingEnergy >= layers[i]) {
            remainingEnergy -= layers[i];
            result[i]++;
        }
    }

    return result;
}
int main()
{
    vector<int> layers;
    layers.push_back(5);
    layers.push_back(8);
    layers.push_back(1);
    vector<int> energy;
    energy.push_back(4);
    energy.push_back(2);
    energy.push_back(1);
    long k=10;
    vector<int> result=getNumPoints(layers,energy,k);
    cout<<result[0]<<" "<<result[1]<<" "<<result[2]<<endl;
}