#include <iostream>
#include <vector>

using namespace std;

vector<int> getNumPoints(vector<int> layers, vector<int> energy, long k) {
int n = layers.size();
    vector<int> points(n, 0);

    for (int i = 0; i < n; i++) {
        int remainingEnergy = k;
        for (int j = i; j < n; j++) {
            if (remainingEnergy >= layers[j]) {
                remainingEnergy -= layers[j];
                if(energy[j]<=remainingEnergy)
                points[i]++;
            } else {
                break;
            }
        }
    }

    return points;
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