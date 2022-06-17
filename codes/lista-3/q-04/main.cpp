#include <iostream>
using namespace std;

float donation(float value_donation, int churches){
    float value = 0.0;
    for(int cont = churches; cont >= 1; cont--){
        value = (value + value_donation)/2;
    }
    return value;
    }

int main() {
    int value_donation, churches;
    cin >> churches;
    cin >> value_donation;

    printf("%.2f", donation(value_donation, churches));

    return 0;
}
